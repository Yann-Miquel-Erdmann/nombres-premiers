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

std::mutex myMutex;

int npatrouver;


void insertToNp(int x)
{
    myMutex.lock();
    
    int pos = nplen;
    np[pos] = x;
    nplen++;

    unsigned int temp;

    while (np[pos-1]>np[pos]){
        cout<<nplen<<endl;
        temp = np[pos-1];
        np[pos-1] = np[pos];
        np[pos] = temp;
        pos--;
    }
    myMutex.unlock();        
}


void primeTread(){
    unsigned int test;
    unsigned int number;
    float max;

    while (nplen<npatrouver){
        test = 0;

        number = nombre;
        max = sqrt(number);
        // cout <<max<< endl;
        while (np[test] <= max) {
            // cout << number << endl;
            if (number % np[test] == 0) {
                test = 0;
                nombre+=2;
                number = nombre;
                max = sqrt(number);

            } else {
                test++;
            }
        }
        insertToNp(number)   ;   
        nombre+=2;
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

    cout<<np[nplen-1]<<endl;

    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
        for(int count = 0; count < nplen; count ++){
            myfile << np[count] << "\n" ;
        }
        myfile.close();
    }

    
    free(np);
    return 0;
}   





//g++ -std=c++11 np\ speed\ test\ thread.cpp -lpthread -o main  && sudo nice -20 ./main