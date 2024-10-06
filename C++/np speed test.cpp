#include <iostream>
#include <chrono>
#include <cmath>
#include <fstream>

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


int main()
{

    int *np;
    unsigned int npatrouver;
    cout << "Entrez le nombre de nombres premiers à trouver: ";
    cin >> npatrouver;
    np = (int *)malloc(npatrouver*sizeof(unsigned int));
    const std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
 
    np[0] = 2;
    unsigned int nplen = 1;
    unsigned int nombre = 3;
    unsigned int test = 0;
    float max = sqrt(nombre);

    while (nplen<npatrouver) {
        test = 0;
        max = sqrt(nombre);
        while (np[test] <= max) {
            if (nombre % np[test] == 0) {;
                test = 0;
                nombre+=2;
                max = sqrt(nombre);
            } else {
                test++;
            }
        }
        np[nplen] = nombre;
        nplen++;
        nombre+=2;
            

        


    }

    const std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    const int diff = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    std::cout << "Time difference = " << diff << "[ms]" << std::endl;
    ConvertSectoDay(diff/1000);

    std::cout <<nombre-2 <<std::endl;

    ofstream myfile ("example.txt");
    if (myfile.is_open())
    {
        for(int count = 0; count < nplen; count ++){
            myfile << np[count] << "\n" ;
        }
        myfile.close();
    }

    std::cout << "end" << std::endl;

    
    return 0;
}   
