#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lestring(int *t){
    char *str;
    str = malloc(sizeof(char) * 50);
    scanf(" %[^\n]", str);
    str = realloc(str, sizeof(char) * strlen(str));
    *t = strlen(str);
    return str;
}

int comparastring(char *str, char *strp, int t, int tp){
    int ponto;
    for(int i = 0; i < t; i++){
        for(int j = 0; j < tp; j++){
            if(str[i + j] != strp[j]){
                ponto = -1;
                break;
            }
            if(j == 0) ponto = i;
        }
    }
    return ponto;
}

char *strsubst(int ponto, char *str, char *strpoe, int ttira, int tpoe, int ts){
    char *straux; //string que vou usar para pegar o resultado final do negocio todo
    straux = calloc(sizeof(char), (ts - ttira + tpoe));
    int taux = (ts - ttira);

    for(int i = 0; i < taux; i++){
        straux[i] = str[i];
    }
    if(strpoe[0] == 36) return straux;
    for(int i = taux; i < (tpoe + taux); i++){
        straux[i] = strpoe[i - taux];
    }
    return straux;
}

int main(void){
    char *str, *strpoe, *strtira; //str vai ser a string original, strpoe é o que eu quero por e strtira o que eu quero tirar
    int ts, tpoe, ttira, ponto; //como dá pra deduzir, esses sao os tamanhos das strings de cima

    printf("entrada esperada: digite uma string, uma parte da string que voce quer tirar e outra string que quer colocar no lugar\n");
    printf("caso queira apenas apagar uma parte da primeira string, digite $ na terceira string\n");

    str = lestring(&ts);
    strtira = lestring(&ttira);
    strpoe = lestring(&tpoe);

    ponto = comparastring(str, strtira, ts, ttira);
    str = strsubst(ponto, str, strpoe, ttira, tpoe, ts);
    realloc(str, sizeof(char) * (ts - ttira + tpoe));
    
    for(int i = 0; i < ts - ttira + tpoe; i++){ //poderia printar só no %s mas tava dando ruim (sei la porque)
        printf("%c", str[i]);
    }
}
