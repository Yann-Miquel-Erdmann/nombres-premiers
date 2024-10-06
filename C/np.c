#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    unsigned int npatrouver;
    printf("Nombre de nombres premiers à trouver: ");
    scanf("%d", &npatrouver);

    unsigned int *np;
    np = (unsigned int*) malloc(npatrouver * sizeof(unsigned int));

    clock_t begin = clock();

    // np[0] = 2;
    // unsigned int nplen = 1;
    // unsigned int nombre = 3;
    // unsigned int test = 0;
    // float max = sqrt(nombre);

    // while (nplen<npatrouver) {
    //     test = 0;
    //     max = sqrt(nombre);
    //     while (np[test] <= max) {
    //         if (nombre % np[test] == 0) {;
    //             test = 0;
    //             nombre+=2;
    //             max = sqrt(nombre);
    //         } else {
    //             test++;
    //         }
    //     }
    //     np[nplen] = nombre;
    //     nplen++;
    //     nombre+=2;

    // }


   



    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f" ,time_spent);

    return 0;
}
