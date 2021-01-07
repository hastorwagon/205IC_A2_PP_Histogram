#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 1. Wypelnić tablice o zadanym rozmiarze lcizbami pseudolosowymi (int) z zadanego przedziału
// 2. Policzyć sume elementów tablicy
// 3. Policzyć sredni arytmetyzna elementow tablicy
// 4. wygeneruje histogram wartosci tablicy

#define ROZMIAR_TABLICY 10
#define MIN 2
#define MAX 10


void wypelnijTabliceLiczbamiPseudolosowymi(int* tab, int min, int max);
int sumaTablicy(int *tab);
float sredniaTablicy(int *tab);
void generujHistogram(int *tab, int* histogram);
void wypiszTablice(int *tab);
void wypiszStatystyki(int *tab, int suma, float srednia, int* histogram);

int main() {
    int tablica[ROZMIAR_TABLICY];
    wypelnijTabliceLiczbamiPseudolosowymi(tablica, MIN, MAX);
    wypiszTablice(tablica);
    //wypiszStatystyki();
    return 0;
}

void wypelnijTabliceLiczbamiPseudolosowymi(int* tab, int min, int max){
    srand(time(0));

    for (int i=0; i<ROZMIAR_TABLICY; i++) {
        tab[i] = rand() % max;
       // sumaTablicy = min + max;
    }
}



void wypiszTablice(int *tab) {
    printf("\n");
    for (int i=0; i<ROZMIAR_TABLICY; i++) {
        printf("%d ", tab[i]);
    }
}


/*
void generujHistogram(int *tab, int* histogram);
    int i, j;
    for (i = 0; i<ROZMIAR_TABLICY; i++) {
        printf("[%d]", i);
        for ( j = 0; j < hist[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
}
 */