#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BIN_LENGTH 9 // Máximo de bits por caractere (8 + '\0')
#define MAX_CHARS 256    // Máximo de caracteres na mensagem

// Função para converter binário em decimal
int binarioParaDecimal(const char *binario) {
    return (int)strtol(binario, NULL, 2); // Converte diretamente de binário para decimal
}

int main() {
    char binarios[MAX_CHARS][MAX_BIN_LENGTH]; // Array para armazenar códigos binários
    char mensagemDecodificada[MAX_CHARS];    // String para armazenar a mensagem decodificada
    int quantidade, i;

    printf("Quantos caracteres binários deseja decodificar? ");
    scanf("%d", &quantidade);

    if (quantidade > MAX_CHARS) {
        printf("Erro: o número máximo de caracteres permitidos é %d.\n", MAX_CHARS);
        return 1;
    }

    // Entrada dos códigos binários
    printf("Insira os códigos binários (1 por linha):\n");
    for (i = 0; i < quantidade; i++) {
        scanf("%s", binarios[i]);
        if (strlen(binarios[i]) >= MAX_BIN_LENGTH) {
            printf("Erro: código binário excede o limite de 8 bits.\n");
            return 1;
        }
    }

    // Decodificar os códigos binários
    for (i = 0; i < quantidade; i++) {
        int decimal = binarioParaDecimal(binarios[i]);
        mensagemDecodificada[i] = (char)decimal; // Converter decimal para caractere
    }
    mensagemDecodificada[quantidade] = '\0'; // Adicionar caractere nulo ao final

    // Exibir a mensagem decodificada
    printf("\nMensagem codificada em binário:\n");
    for (i = 0; i < quantidade; i++) {
        printf("%s ", binarios[i]);
    }
    printf("\n\nMensagem decodificada: %s\n", mensagemDecodificada);

    return 0;
}
