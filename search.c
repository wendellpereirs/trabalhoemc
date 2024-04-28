#include "search.h"

// Implementação da função de busca binária por nome de artista
Artist binarySearch(Artist* artists, char* name, int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2; // Calcula o meio do intervalo
        int comparison = strcmp(artists[mid].name, name); // Compara o nome no meio com o nome procurado
        if (comparison == 0) {
            return artists[mid]; // Se encontrou, retorna o artista
        } else if (comparison < 0) {
            low = mid + 1; // Se o nome no meio é menor, busca na metade superior
        } else {
            high = mid - 1; // Se o nome no meio é maior, busca na metade inferior
        }
    }

    // Se não encontrou, retorna um artista com o nome "NULL"
    Artist artistNotFound;
    strcpy(artistNotFound.name, "NULL");
    return artistNotFound;
}