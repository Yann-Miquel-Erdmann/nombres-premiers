#include <iostream>
#include <chrono>
#include <cmath>
#include <fstream>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;


void ConvertSectoDay(int n)
{
    int day = n / (24 * 3600);
 
    n = n % (24 * 3600);
    int hour = n / 3600;
 
    n %= 3600;
    int minutes = n / 60 ;
 
    n %= 60;
    int seconds = n;
     
    cout << day << " " << "days " << hour
         << " " << "hours " << minutes << " "
         << "minutes " << seconds << " "
         << "seconds "  << endl;
}
  

unsigned int *np;
std::atomic_uint nplen = 0;
std::atomic_uint nombre = 3;
std::atomic_uint biggest = 2;
std::mutex add_end_Mutex;
std::mutex sort_end_Mutex;
std::mutex nombre_Mutex;

int npatrouver;


void insertToNp(const unsigned int x)
{   
    if (x==biggest){
        return;
    }

    add_end_Mutex.lock();
    np[nplen] = x;
    nplen++;

    if (x > biggest){
        biggest = x;
        add_end_Mutex.unlock();     

    }
    else if (sort_end_Mutex.try_lock()){
        add_end_Mutex.unlock();     

        // cout<<nplen<<endl;
        unsigned int pos;
        unsigned int pos_start = nplen-1;

        while (pos_start !=nplen){
            unsigned int temp;
            pos = pos_start;
            while (np[pos-1]>np[pos]){
                // cout<<nplen<<endl;
                temp = np[pos-1];
                np[pos-1] = np[pos];
                np[pos] = temp;
                pos--;
            }
            pos_start++;
        }

            // cout <<"end"<<x<<endl;
        sort_end_Mutex.unlock();
    }else{
        add_end_Mutex.unlock();     

    }

}


void primeTread( ){
    unsigned int test;
    unsigned int number;
    float max;

    cout<<"thread start: "<<nombre<<endl;
    number = nombre;


    while (nplen<npatrouver){
        test = 0;

        max = sqrt(number);

        while (np[test] <= max) {
            if (number % np[test] == 0) {
                test = 0;

                nombre_Mutex.lock();
                nombre+=2;
                number = nombre;
                nombre_Mutex.unlock();

                max = sqrt(number);

            } else {
                test++;
            }
        }
        insertToNp(number);   

        nombre_Mutex.lock();
        nombre+=2;
        number = nombre;
        nombre_Mutex.unlock();


    }
}



int main()
{
    cout << "Entrez le nombre de nombres premiers à trouver: ";
    cin >> npatrouver;
    np = (unsigned int *)malloc(npatrouver*sizeof(unsigned int));

    
    const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
 
    np[0] = 2;
    nplen++;

    std::thread t1(primeTread);
    std::thread t2(primeTread);
    std::thread t3(primeTread);
    std::thread t4(primeTread);
    
    
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    
    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    const int diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    std::cout << "Time difference = " << diff << "[ms]" << std::endl;
    ConvertSectoDay(diff/1000);

    cout<<np[npatrouver-1]<<endl;
    
    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
        for(int count = 0; count < nplen; count ++){
            if (np[count] == np[count+1]){
                cerr << np[count] << endl;
            }
            myfile << np[count] << endl ;
        }
        myfile.close();
    }else{
        cout << "Unable to open file";
    }
    

    // ofstream out("numbers.bin", ios::out | ios::binary);
    // if(!out) {
    //     cout << "Cannot open file.";
    //     return 1;
    // }

    // out.write((char * ) np, sizeof(unsigned int) * nplen);

    // out.close();

    
    free(np);
    return 0;
}   





//g++ -std=c++11 np\ speed\ test\ thread.cpp -lpthread -o main  && sudo nice -20 ./main