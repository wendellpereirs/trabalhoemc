#include "utils.h"

// Função para remover o caractere de nova linha de uma string
void removeNewlineCh(char *line) {
    int length = strlen(line);
    if (length > 0 && line[length - 1] == '\n') {
        line[length - 1] = '\0'; // Remove o caractere de nova linha
    }
}