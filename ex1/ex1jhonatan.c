#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//função para transformar em float
float converte (char *str, int base){
    float res =0;
    int tam = strlen(str);
    int B = 1;
    for (int i = tam-1; i>=0 ; i--){
        res += (str[i] - 48) * B;
        B *= base; 
    }
    return res;
}

//Função resebe as strings e calcula seu tamanho
int tamnho_str(char *str1, char *str2){
    int tam;
    printf("Digite a primeira string:");
    scanf(" %s", str1);
    printf("Digite a segunda string:");
    scanf(" %s", str2);
    tam = strlen(str1) + strlen(str2);
    return tam;
    }

//função que faz a unição das strings
char *unir_str (char *str1, char *str2, int tam) {
    char *str3 = (char *)malloc((tam + 1) * sizeof(char));
    for (int i = 0; i < strlen(str1); i++) {
        str3[i] = str1[i];}
    for (int j = 0; j < strlen(str2); j++) {
        str3 [strlen(str1)+j] = str2[j];}
    str3 [tam]= '\0';
    return str3;
}

char* strsubst(const char* string_in, const char* searchStr, const char* replaceStr) {
    char* result;
    char* ins;    // Ponto de inserção
    char* tmp;    // Ponto temporário
    int len_search, len_replace, len_front, count;

    if (!string_in || !searchStr)
        return NULL;

    len_search = strlen(searchStr);
    if (len_search == 0)
        return NULL; // Se a substring de pesquisa é vazia, retorna NULL
    len_replace = strlen(replaceStr);

    ins = (char*)string_in;
    for (count = 0; (tmp = strstr(ins, searchStr)); ++count) {
        ins = tmp + len_search;
    }

    tmp = result = malloc(strlen(string_in) + (len_replace - len_search) * count + 1);

    if (!result)
        return NULL;

    while (count--) {
        ins = strstr(string_in, searchStr);
        len_front = ins - string_in;
        tmp = strncpy(tmp, string_in, len_front) + len_front;
        tmp = strcpy(tmp, replaceStr) + len_replace;
        string_in += len_front + len_search; // Move o ponteiro de entrada
    }
    strcpy(tmp, string_in);
    return result;
}

int main(){
    
    // Transformar uma string char do uma base em um float
    char str[100];
    int base;
    printf("Insira a string e a base:");
    scanf("%s %d", str, &base);
    printf("O resultado é %f\n\n", converte (str, base));

    // Juntar strings 
    char str1[100];
    char str2[100];
    int tam = tamnho_str(str1, str2);
    char *str3 = unir_str(str1, str2, tam);
    printf ("O tamanho da string é: %d\n", tam);
    printf ("A string união é: %s\n\n", str3);
    free (str3);

    //Subatituir string
    char string_in[100], searchStr[50], replaceStr[50];
    printf("Digite a string original: ");
    fgets( string_in, sizeof(string_in), stdin);
    string_in[strcspn(string_in, "\n")] = '\0'; // Remove o caractere de nova linha
    
    printf("Digite a substring a ser substituída: ");
    fgets(searchStr, sizeof(searchStr), stdin);
    searchStr[strcspn(searchStr, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite a substring de substituição: ");
    fgets(replaceStr, sizeof(replaceStr), stdin);
    replaceStr[strcspn(replaceStr, "\n")] = '\0'; // Remove o caractere de nova linha

    char* result = strsubst(string_in, searchStr, replaceStr);

    if (result) {
        printf("Resultado: %s\n", result);
        free(result); // Libera a memória alocada
    } else {
        printf("Nenhuma substituição realizada.\n");
    }


    return (0);
}