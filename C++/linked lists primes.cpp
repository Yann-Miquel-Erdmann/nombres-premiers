#include<iterator>
#include<list>
#include<iostream>
#include <atomic>
#include <chrono>
#include <cmath>
#include <fstream>
using namespace std;

list<unsigned int> np;
std::atomic_uint nplen = 0;
// unsigned int nplen = 0;

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


void insertNP(unsigned int nbr)
{
    list<unsigned int>::iterator iter = np.end();
    iter--;
    while(*(iter) > nbr){
        iter--;
    }
    iter++;
    np.insert(iter,nbr);
    nplen++;
}

int main() {
    // std::atomic_uint nombre = 3;
    unsigned int nombre = 3;
    float max = sqrtl(nombre);
    unsigned int npatrouver;
    cout << "Entrez le nombre de nombres premiers à trouver: ";
    cin >> npatrouver;
    
    const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    insertNP(2);

    list<unsigned int>::iterator iter;
    while (nplen<npatrouver) {
        iter = np.begin();
        max = sqrt(nombre);
        while (*(iter) <= max) {
            if (nombre % *(iter) == 0) {;
                iter = np.begin();
                nombre+=2;
                max = sqrt(nombre);
            } else {
                iter++;
            }
        }
        np.push_back(nombre);
        nplen++;
        // insertNP(nombre);
        nombre+=2;

    }

    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    const int diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    cout << "Time difference = " << diff << "[ms]" << std::endl;
    ConvertSectoDay(diff/1000);

    cout <<nombre-2 <<std::endl;


    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
        for (auto v : np){
            myfile << v << "\n" ;
        }
        myfile.close();
    }

    // std::cout << "end" << std::endl;
}