#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BIN_LENGTH 9 // M�ximo de bits por caractere (8 + '\0')
#define MAX_CHARS 256    // M�ximo de caracteres na mensagem

// Fun��o para converter bin�rio em decimal
int binarioParaDecimal(const char *binario) {
    return (int)strtol(binario, NULL, 2); // Converte diretamente de bin�rio para decimal
}

int main() {
    char binarios[MAX_CHARS][MAX_BIN_LENGTH]; // Array para armazenar c�digos bin�rios
    char mensagemDecodificada[MAX_CHARS];    // String para armazenar a mensagem decodificada
    int quantidade, i;

    printf("Quantos caracteres bin�rios deseja decodificar? ");
    scanf("%d", &quantidade);

    if (quantidade > MAX_CHARS) {
        printf("Erro: o n�mero m�ximo de caracteres permitidos � %d.\n", MAX_CHARS);
        return 1;
    }

    // Entrada dos c�digos bin�rios
    printf("Insira os c�digos bin�rios (1 por linha):\n");
    for (i = 0; i < quantidade; i++) {
        scanf("%s", binarios[i]);
        if (strlen(binarios[i]) >= MAX_BIN_LENGTH) {
            printf("Erro: c�digo bin�rio excede o limite de 8 bits.\n");
            return 1;
        }
    }

    // Decodificar os c�digos bin�rios
    for (i = 0; i < quantidade; i++) {
        int decimal = binarioParaDecimal(binarios[i]);
        mensagemDecodificada[i] = (char)decimal; // Converter decimal para caractere
    }
    mensagemDecodificada[quantidade] = '\0'; // Adicionar caractere nulo ao final

    // Exibir a mensagem decodificada
    printf("\nMensagem codificada em bin�rio:\n");
    for (i = 0; i < quantidade; i++) {
        printf("%s ", binarios[i]);
    }
    printf("\n\nMensagem decodificada: %s\n", mensagemDecodificada);

    return 0;
}
