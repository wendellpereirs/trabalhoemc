#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "filesystem.h"
#include "operations.h"

int main() {
    setlocale(LC_ALL, "C.UTF-8");

    // Aloca memória para os artistas
    Artist *artists = (Artist *)malloc(sizeof(Artist) * MAX_LENGTH);
    if (artists == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Lê os dados dos artistas do arquivo
    int size = readFile(artists);
    if (size == -1) {
        printf("Erro ao ler dados dos artistas.\n");
        free(artists);
        return 1;
    }

    // Menu de opções para o usuário
    int input;
    do {
        printf("1 - Inserir novo artista (ordenado por nome)\n");
        printf("2 - Remover um artista\n");
        printf("3 - Editar um artista\n");
        printf("4 - Buscar um artista por nome\n");
        printf("5 - Buscar um álbum por nome\n");
        printf("9 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                size = insertArtist(artists, size);
                break;
            case 2:
                size = removeArtist(artists, size);
                break;
            case 3:
                editArtist(artists, size);
                break;
            case 4:
                binarySearchByName(artists, size);
                break;
            case 5:
                sequencialSearchByAlbum(artists, size);
                break;
            case 9:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    } while (input != 9);

    // Libera memória alocada
    free(artists);

    return 0;
}