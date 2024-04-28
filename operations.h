#ifndef OPERATIONS
#define OPERATIONS

#include "types.h"

// Protótipos das funções
int insertArtist(Artist* artists, int size);
int removeArtist(Artist* artists, int size);
void editArtist(Artist* artists, int size);
void binarySearchByName(Artist* artists, int size);
void sequencialSearchByAlbum(Artist* artists, int size);

#endif