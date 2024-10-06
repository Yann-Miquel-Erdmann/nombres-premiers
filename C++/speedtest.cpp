#include<iterator>
#include<list>
#include<iostream>
#include <chrono>

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
     
    std::cout << day << " " << "days " << hour
         << " " << "hours " << minutes << " "
         << "minutes " << seconds << " "
         << "seconds "  << endl;
}


int main(){
    unsigned int max = 1000000 ;
    list<unsigned int> lst;
    const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
        for(unsigned int i = 0; i!=max;i++){
            lst.push_back(i);
        }
        // for(std::list<unsigned int>::iterator i = lst.begin(); i != lst.end(); ++i){
            
        // }
        // list<unsigned int>::iterator iter;
        // iter = lst.begin();
        // while (*iter<max) {
        //     // cout<<*iter<<endl;
        //     iter++;
        // }
    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    const int diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    cout << "Time difference = " << diff << "[ms]" << std::endl;


    int *lst2;
    lst2 = (int *)malloc(1000000*sizeof(unsigned int));
    const std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
    for(int i = 0; i!=1000000;i++){
        lst2[i] = i;
    }
    int i = 0;
    while (lst2[i]<max) {
        i++;
    }
    const std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();
    const int diff2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2).count();
    cout << "Time difference = " << diff2 << "[ms]" << std::endl;
}

