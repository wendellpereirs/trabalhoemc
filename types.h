#ifndef TYPES
#define TYPES

#define MAX_LENGTH 99
#define MAX_NAME_LENGTH 64

// Definição da estrutura do álbum
struct Album {
    char name[MAX_NAME_LENGTH];
} typedef Album;

// Definição da estrutura do artista
struct Artist {
    char name[MAX_NAME_LENGTH];
    char gender[MAX_NAME_LENGTH];
    char bornAt[MAX_NAME_LENGTH];
    Album albums[MAX_LENGTH];
    int albumsSize;
} typedef Artist;

#endif}