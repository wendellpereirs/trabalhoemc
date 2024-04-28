#include "sort.h"

// Implementação da função de ordenação de artistas por nome (bubble sort)
void sort(Artist* artists, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (strcmp(artists[j].name, artists[j + 1].name) > 0) {
                Artist tmp = artists[j];
                artists[j] = artists[j + 1];
                artists[j + 1] = tmp;
            }
        }
    }
}