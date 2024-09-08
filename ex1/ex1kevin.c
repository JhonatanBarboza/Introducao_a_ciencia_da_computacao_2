#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float strtofloat(char* string, int base)
{
    float resultado=0;
    int base1 = 1;
    //For começando do final da string
    for(int i=strlen(string)-1;i>=0;i--)
    {
        //Se o caracter da string for uma letra e a base for hexadecimal
        if((string[i]>=65&&string[i]<=70)||(string[i]>=97&&string[i]<=102)&&base==16)
        {
            //Se for abaixo de 70, é letra maiúscula e deve subtrair 55
            if(string[i]<=70)
            {
                resultado += (string[i]-55)*base1;
            }
            //Senão, é letra minúscula e deve subtrair 87
            else
            {
                resultado += (string[i]-87)*base1;
            }
        }
        //Senão, ele será um número e, para correponder aos valores da tabela ascii,
        //deve subtrair 48
        else
        {
            resultado += (string[i]-48)*base1;
        }
        //Atualizando a base a cada loop
        base1 *= base;
    }
    //Retorna o resultado
    return resultado;
}

void concat()
{
    char a[50];
    char b[50];
    char c[50];
    printf("Digite as duas strings a serem concatenadas: \n");
    //Leitura das strings
    scanf("%s", a);
    scanf("%*c%s", b);
    //Copiando a string a na string c
    for(int i=0;i<strlen(a);i++)
    {
        c[i] = a[i];
    }
    //Copiando a string b na string c
    for(int i=0;i<strlen(b);i++)
    {
        c[strlen(a)+i] = b[i];
    }
    printf("Tamanho da string: %ld\n", strlen(c));
    printf("String: ");
    //Printando o resultado
    for(int i=0;i<strlen(c);i++)
    {
        printf("%c", c[i]);
    }
    printf("\n");
    return;
}

char* strsubst(char *in, char *search, char *replace)
{
    //Declaração das variáveis de controle
    int i,k,j;
    //Declaração dos limitadores dos loops
    int errou, acabou;
    char* res;
    //Alocando a quantidade exata de memória para a nova string
    res = (char*) malloc ((strlen(in)+strlen(replace)-strlen(search))*sizeof(char));
    acabou = 0;
    //For termina quando acabar a string ou quando replace for colocado 
    for(i=0;i<strlen(in)&&acabou==0;i++)
    {
        //Se o caracter de in for diferente do primeiro caracter de search,
        //é copiado para a string res
        if(in[i] != search[0])
        {
            res[i] = in[i];
        }
        //Senão...
        else
        {
            errou = 0;
            //Verifica se os caracteres seguintes correpondem ao search
            for(k=1;k<strlen(search)&&errou==0;k++)
            {
                if(search[k] != in[i+k])
                {
                    errou = 1;
                }
            }
            //Se errou==0, então quer dizer que a string search foi encontrada,
            //então precisamos colocar a string replace no lugar
            if(errou == 0)
            {
                j = i;
                //Colocando replace no lugar de search
                for(k=0;k<strlen(replace);k++)
                {
                    res[j] = replace[k];
                    j++;
                }
                //Colocando os caracteres faltantes de in em res
                for(k=i+strlen(search);k<strlen(in);k++)
                {
                    res[j] = in[k];
                    j++;
                }
                acabou = 1;
            }
            //Se errou!=0, então a string search não foi encontrada 
            //e precisamos apenas copiar o caracter para a string res
            else
            {
                res[i] = in[i];
            }
        }
    }
    //retorna string res
    return res;
}

int main()
{
    char a[]= "345987";
    char b[]= "1010";
    char c[]= "ba12";
    char *d= "comunication";
    char *e= "comu";
    char *f= "";
    char *g;
    
    //Teste 1
    printf("Teste EX1: \n");
    printf("%s(10) = ", a);
    printf("%.0f(10)\n", strtofloat(a, 10));
    printf("%s(2) = ", b);
    printf("%.0f(10)\n", strtofloat(b, 2));
    printf("%s(16) = ", c);
    printf("%.0f(10)\n", strtofloat(c, 16));
    printf("\n");
    
    //Teste 2
    printf("Teste EX2: \n");
    concat();
    printf("\n");
    
    //Teste 3
    printf("Teste EX3: \n");
    g = strsubst("comunication", "comu", "");
    for(int i=0;i<strlen(g);i++)
    {
        printf("%c", g[i]);
    }
    return 0;
}
