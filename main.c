#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR_TABLICY 15
#define MIN 2
#define MAX 10
#define ROZMIAR_HISTOGRAMA 11

void wypelnijTablice(int* tab, int min, int max);
int sumaTablicy(int *tab);
float sredniaTablicy(int *tab);
void generujHistogram(int *tab, int* histogram);
void wypiszTablice(int *tab);
void wypiszStatystyki(int *tab, int suma, float srednia, int* histogram);

int main() {
    int tablica[ROZMIAR_TABLICY];
    int histogram[ROZMIAR_HISTOGRAMA];
    for(int i=0; i<ROZMIAR_HISTOGRAMA; i++ ){
        histogram[i]=0;
    }
    wypelnijTablice(tablica, MIN, MAX);
    generujHistogram(tablica, histogram);
    wypiszTablice(tablica);
    wypiszStatystyki (tablica, sumaTablicy(tablica), sredniaTablicy(tablica), histogram);
    return 0;
}

void wypelnijTablice(int* tab, int min, int max){
    srand(time(0));

    for (int i=0; i<ROZMIAR_TABLICY; i++) {
        tab[i] = MIN + rand() % (MAX - MIN+1);
    }
}

int sumaTablicy(int *tab){
    int suma=0;
    for(int i=0; i<ROZMIAR_TABLICY; i++) {
        suma = suma+tab[i];
    }
    return suma;
}

float sredniaTablicy(int *tab) {
    float srednia = 0;
    srednia = (float)sumaTablicy(tab) / ROZMIAR_TABLICY;
    return srednia;
}
void generujHistogram(int *tab, int* histogram) {
    for (int i = 0; i < ROZMIAR_TABLICY; i++) {
        histogram[tab[i]] = histogram[tab[i]] + 1;
    }
}

void wypiszTablice(int *tab) {
        printf("\n[");
        for (int i = 0; i < ROZMIAR_TABLICY; i++) {
            printf("%d ", tab[i]);
        }
        printf("]\n");
}

void wypiszStatystyki(int *tab, int suma, float srednia, int* histogram) {
        printf("Suma: %d \n", suma);
        printf("Srednia: %.1f \n", srednia);
        for (int i = 0; i < ROZMIAR_HISTOGRAMA; i++) {
            printf("%d -> %d \n", i, histogram[i]);
        }
    }
