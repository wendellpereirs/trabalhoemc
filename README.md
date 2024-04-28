# Programa de Gerenciamento de Artistas e Álbuns

## Descrição
Este programa permite a leitura de uma lista de artistas/bandas de um arquivo, armazenando os registros em uma lista sequencial durante a execução. O usuário pode realizar diversas operações, como inserção, remoção, edição e busca de artistas, bem como busca de álbuns.

## Como Executar
1. Certifique-se de ter um compilador C instalado em seu sistema.
2. Clone ou baixe os arquivos do repositório.
3. Abra um terminal e navegue até o diretório onde os arquivos estão localizados.
4. Compile os arquivos usando um comando de compilação adequado, como:
   ```
   gcc -o programa main.c operations.c search.c sort.c utils.c filesystem.c
   ```
   Certifique-se de incluir todos os arquivos necessários no comando de compilação.
5. Execute o programa gerado usando o comando:
   ```
   ./programa
   ```

## Possíveis Erros
- **Erro ao abrir o arquivo:** Isso pode ocorrer se o arquivo de entrada `artistas.txt` não estiver presente no diretório do programa ou se o programa não tiver permissão para acessá-lo. Certifique-se de que o arquivo existe e as permissões estão corretas.
