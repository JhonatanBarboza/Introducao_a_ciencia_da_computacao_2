#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//baseado no chatgpt rsrs, nao sei usar essas funções todas da string.h. a logica geral ta certa, so dei umas minimas mexidas no que ele tinha feito e adicionei outras coisas que achei que precisava
//ta dando certo em alguns casos que estavam meia boca no codigo de antes, o problema é que, as vezes, ele printa certo e depois printa lixo a mais tb

char *lestring(void){
    char *str;
    str = malloc(sizeof(char) * 50);
    scanf(" %[^\n]", str);
    str = realloc(str, sizeof(char) * strlen(str));
    return str;
}

// Função para substituir todas as ocorrências de 'substr' por 'replace' em 'str'
char* subststr(const char* str, const char* substr, const char* replace) {
    // Contar o número de ocorrências da substring
    int count = 0;
    const char* tmp = str;
    while ((tmp = strstr(tmp, substr)) != NULL) {
        count++;
        tmp += strlen(substr);
    }

    // Calcular o tamanho da nova string
    size_t new_len = strlen(str) + count * (strlen(replace) - strlen(substr));
    char* result = (char*)malloc(new_len + 1);
    if(!result){
        printf("erro na alocação");
        exit(1);
    }

    // Substituir as ocorrências
    char* pos = result;
    const char* start = str;
    while((tmp = strstr(start, substr)) != NULL){
        size_t len = tmp - start;
        memcpy(pos, start, len);
        pos += len;
        memcpy(pos, replace, strlen(replace));
        pos += strlen(replace);
        start = tmp + strlen(substr);
    }
    strcpy(pos, start);

    return result;
}

int main() {
    char* text = lestring();
    char* old_substr = lestring();
    char* new_substr = lestring();

    char* result = subststr(text, old_substr, new_substr);

    printf("texto antes: ");
    for(int i = 0; i < strlen(text); i++){
        printf("%c", text[i]);
    }

    printf("\ntexto depois: ");
    for(int i = 0; i < strlen(result); i++){
        printf("%c", result[i]);
    }

    free(result);
    return 0;
}