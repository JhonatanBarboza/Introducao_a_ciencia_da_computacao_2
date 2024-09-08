
//****************Exercicio 1 - (19/08/2024)****************
// Atividade que o prof passou em sala para entregar (19/08)

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//'0' = 48 e '9' = 57
float strtofloat(char *string, int base){
    int size = strlen(string), ans=0;
    for(int i=0; i<size; i++){
        ans += (string[i] - 48)*pow(base, size-i-1);
    }
    return (float)ans;
}

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

int comp(char *s1, char *s2){
    int size = strlen(s1);
    for(int i=0; i<size; i++){
        if(s1[i] != s2[i]) return 0;
    }
    return 1;
}

char *strsubst(char *string_in, char *searchStr, char *replaceStr){
    char *strFinal = (char *)malloc(100*sizeof(char));

    for(int i=0; i<strlen(string_in); i++){
        if(comp(searchStr, string_in+i)){
            for(int a=0; a<i; a++){
                strFinal[a] = string_in[a];
            }
            for(int a=0; a<strlen(replaceStr); a++){
                strFinal[i+a] = replaceStr[a];
            }
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
    printf("Conversão: %f\n", strtofloat(str, base));

    /* utiliza strjuntar */
    char str1[100], str2[100];
    scanf("%s %s", str1, str2);
    strjuntar(str1,str2);

    /* utiliza strbust */
    char str_in[100], str_srch[100], str_rpc[100];
    scanf("%s %s", str_in, str_srch);
    getchar();
    scanf("%[^\n]", str_rpc);
    printf("%s\n", strsubst(str_in, str_srch, str_rpc));
}   