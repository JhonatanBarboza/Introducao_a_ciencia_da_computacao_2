// Atividade1 para entregar até(19/08)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Função para converter uma string em um float
float strtofloat(char *string, int base){
    int size = strlen(string), ans=0;
    for(int i=0; i<size; i++){
        ans += (string[i] - 48)*pow(base, size-i-1);
    }
    return (float)ans;
}

//Função juntar strings 
void strjuntar(char *str1, char* str2){
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    char strfinal[100];
    for(int i=0; i<size1; i++){
        strfinal[i] = str1[i];
    }
    for(int i=0; i<size2; i++){
        strfinal[i+size1] = str2[i];
    }
    printf("%s %i\n", strfinal, (int)strlen(strfinal)); 
}

//função verifica se ha o caractere a ser substituido na palavra 
int comp(char *s1, char *s2){
    int size = strlen(s1);
    for(int i=0; i<size; i++){
        if(s1[i] != s2[i]) return 0;
    }
    return 1;
}

//Função faz a substituição na palavra 
char *strsubst(char *string_in, char *searchStr, char *replaceStr){
    int newSize = strlen(string_in) - strlen(searchStr) + strlen(replaceStr);
    char *strFinal = (char *)calloc(newSize,sizeof(char));

    for(int i=0; i<strlen(string_in); i++){
        if(comp(searchStr, string_in+i)){
            for(int a=0; a<i; a++){
                strFinal[a] = string_in[a];
            }
            for(int a=0; a
            <strlen(replaceStr); a++){
                strFinal[i+a] = replaceStr[a];
            }
            if(strlen(strFinal) < newSize){
                for(int a = strlen(replaceStr); a < newSize; a++){ 
                    strFinal[a + i] = string_in[i + strlen(searchStr) + (a - strlen(replaceStr))]; 
                }
            }
            strFinal[newSize] = '\0';
            break;
        }
    }
    return strFinal;
}

int main(){
    /* utiliza strtofloat */
    char str[100];
    int base;
    printf("Digite a string (numero) e a base:\n");
    scanf("%s %d", str, &base);
    printf("Conversão: %f\n\n", strtofloat(str, base));

    /* utiliza strjuntar */
    char str1[100], str2[100];
    printf("Digite as duas strings:\n");
    scanf("%s %s", str1, str2);
    strjuntar(str1,str2);
    printf("\n");

    /* utiliza strbust */
    char str_in[100], str_srch[100], str_rpc[100];
    printf("Digite a palavra, os caracteres a serem substituidos e os substitutos:\n");
    scanf("%s %s", str_in, str_srch);
    getchar();
    int i=0;
    while(1){
        char a;
        a = getchar();
        if(a == '\n') break ;
        str_rpc[i++] = a;}
    str_rpc[i] = '\0';
    printf("%s\n", strsubst(str_in, str_srch, str_rpc));
}   