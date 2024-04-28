#include "operations.h"

// Implementações das funções

int insertArtist(Artist* artists, int size) {
    Artist new;

    printf("Inserção ordenada (por nome) de novos artistas \n\n");

    printf("Digite o Nome do Artista (ou '9' para voltar): ");
    fgets(new.name, sizeof(new.name), stdin);
    removeNewlineCh(new.name);
    if (new.name[0] == '9') return size;

    printf("Digite o Gênero Musical do Artista (ou '9' para voltar): ");
    fgets(new.gender, sizeof(new.gender), stdin);
    removeNewlineCh(new.gender);
    if (new.gender[0] == '9') return size;

    printf("Digite o Local de Surgimento do Artista (ou '9' para voltar): ");
    fgets(new.bornAt, sizeof(new.bornAt), stdin);
    removeNewlineCh(new.bornAt);
    if (new.bornAt[0] == '9') return size;

    int albums_index = 0;
    char albumInput[64];
    do {
        printf("Digite o Nome do Álbum (ou '8' para confirmar e voltar, '9' para voltar): ");
        fgets(albumInput, sizeof(albumInput), stdin);
        removeNewlineCh(albumInput);
        if (albumInput[0] == '9') return size;
        if (albumInput[0] != '8') {
            strcpy(new.albums[albums_index].name, albumInput);
            albums_index++;
        }
    } while (albumInput[0] != '8');

    new.albumsSize = albums_index;
    artists[size] = new;

    int newSize = size + 1;
    sort(artists, newSize);
    writeFile(artists, newSize);

    return newSize;
}

int removeArtist(Artist* artists, int size) {
    char nameToRemove[64];
    printf("Remoção de um artista \n\n");
    printf("Digite o Nome do Artista: ");
    fgets(nameToRemove, sizeof(nameToRemove), stdin);
    removeNewlineCh(nameToRemove);

    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(nameToRemove, artists[i].name) != 0) {
            artists[newSize] = artists[i];
            newSize++;
        }
    }

    writeFile(artists, newSize);
    return newSize;
}

void editArtist(Artist* artists, int size) {
    char nameToEdit[64];
    printf("Edição de um artista \n\n");
    printf("Digite o Nome do Artista: ");
    fgets(nameToEdit, sizeof(nameToEdit), stdin);
    removeNewlineCh(nameToEdit);

    for (int i = 0; i < size; i++) {
        if (strcmp(nameToEdit, artists[i].name) == 0) {
            printf("\nEdição dos atributos do artista: %s \n\n", artists[i].name);

            printf("Digite o Nome do Artista: ");
            fgets(artists[i].name, sizeof(artists[i].name), stdin);
            removeNewlineCh(artists[i].name);

            printf("Digite o Gênero Musical do Artista: ");
            fgets(artists[i].gender, sizeof(artists[i].gender), stdin);
            removeNewlineCh(artists[i].gender);

            printf("Digite o Local de Surgimento do Artista: ");
            fgets(artists[i].bornAt, sizeof(artists[i].bornAt), stdin);
            removeNewlineCh(artists[i].bornAt);

            printf("Digite os Álbuns do Artista (separados por enter, '8' para confirmar e voltar): ");
            int albums_index = 0;
            char albumInput[64];
            do {
                fgets(albumInput, sizeof(albumInput), stdin);
                removeNewlineCh(albumInput);
                if (albumInput[0] != '8') {
                    strcpy(artists[i].albums[albums_index].name, albumInput);
                    albums_index++;
                }
            } while (albumInput[0] != '8');

            artists[i].albumsSize = albums_index;

            sort(artists, size);
            writeFile(artists, size);
            return;
        }
    }

    printf("Artista não encontrado!! \n\n");
}

void binarySearchByName(Artist* artists, int size) {
    char nameToSearch[64];
    printf("Busca binária por um artista \n\n");
    printf("Digite o Nome do Artista: ");
    fgets(nameToSearch, sizeof(nameToSearch), stdin);
    removeNewlineCh(nameToSearch);

    sort(artists, size);
    int index = binarySearchIndex(artists, nameToSearch, size);

    if (index == -1) {
        printf("Artista não encontrado!! \n\n");
        return;
    }

    printArtist(artists[index]);
}

void sequencialSearchByAlbum(Artist* artists, int size) {
    char albumToSearch[64];
    printf("Busca sequencial por um álbum \n\n");
    printf("Digite o Nome do Álbum: ");
    fgets(albumToSearch, sizeof(albumToSearch), stdin);
    removeNewlineCh(albumToSearch);

    int found = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < artists[i].albumsSize; j++) {
            if (strcmp(artists[i].albums[j].name, albumToSearch) == 0) {
                printArtist(artists[i]);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        printf("Álbum não encontrado!! \n\n");
    }
}