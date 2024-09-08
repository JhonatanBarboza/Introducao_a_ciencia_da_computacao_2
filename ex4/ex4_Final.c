//************Problema da maior soma de subsequência em um vetor************

#include <stdio.h>
#include <stdlib.h>

int * vet_maior_soma(int* vet, int tam, int * tam_res)
{
    int maior = 0;
    int soma;
    int tam_;
    int tam_maior;
    int * subvet;
    int cont;
    //Alocando memória para o vetor de retorno
    subvet = (int*) malloc (tam*sizeof(int));
    //Percorrendo o vetor (0 até tam-1)
    for(int i=0;i<tam;i++)
    {
        //Percorrendo o vetor do final para o começo
        for(int j=tam-1;j>=i;j--)
        {
            soma = 0;
            tam_ = 0;
            //Percorrendo o subvetor que vai de i até j
            for(int k=i;k<=j;k++)
            {
                soma += vet[k];
                //Guardando o tamanho do subvetor
                tam_++;
            }
            //Se soma for maior que a variável maior,
            //atualizamos o valor da variável maior
            if(soma > maior)
            {
                maior = soma;
                tam_maior = tam_;
                cont = 0;
                //Copiando os valores do subvetor da maior soma
                //para o subvetor de retorno
                for(int l=i;l<i+tam_;l++)
                {
                    subvet[cont] = vet[l];
                    cont++;
                }
            }
        }
    }
    //Realocando a memória
    subvet = realloc(subvet, tam_maior*sizeof(int));
    //Devolvendo o tamanho de subvet
    *tam_res = tam_maior;
    //Retornando subvet
    return subvet;
}

int maior_soma(int* vet, int tam)
{
    //Inicialização de maior
    int maior = 0;
    int soma;
    //Percorrendo o vetor de 0 até tam-1
    for(int i=0;i<tam;i++)
    {
        //Percorrendo o vetor de tam-1 até i
        for(int j=tam-1;j>=i;j--)
        {
            soma = 0;
            //Somando os elementos de vet[i] até vet[j]
            for(int k=i;k<=j;k++)
            {
                soma += vet[k];
            }
            //Atualização da variável maior
            if(soma > maior)
            {
                maior = soma;
            }
        }
    }
    //Retorna o valor da maior soma
    return maior;
}

int maior_soma_r(int* vet, int tam)
{
    int maior=0;
    int soma;
    //Caso base: quando tam == 0
    if(tam == 0)
    {
        return 0;
    }
    else
    {
        //Percorrendo de tam-1 até 0
        for(int i=tam-1;i>=0;i--)
        {
            soma = 0;
            //Somando os valores de vet[j] até vet[i]
            for(int j=0;j<=i;j++)
            {
                soma += vet[j];
            }
            //Se a soma for maior, a variável deve ser atualizada
            if(soma > maior)
            {
                maior = soma;
            }
        }
        //Comparando a maior soma de agora, com a maior soma
        //dos subvetores seguintes(vet começa em vet+1 e tam = tam-1).
        //Se o maior atual for maior que todos os outros,
        //retornará maior
        if(maior > maior_soma(vet+1, tam-1))
        {
            return maior;
        }
        //Senão, retornará a maior soma encontrada no subvetor seguinte.
        else
        {
            return maior_soma(vet+1, tam-1);
        }
    }
}
/*
int main()
{
    int *res;
    int tam;
    int tam_vet_teste = 6;
    int vet[] = {100,-2, 3, 4, -5, 6};
    res = vet_maior_soma(vet, tam_vet_teste, &tam);
    printf("Elementos do subvetor:\n");
    for(int i=0;i<tam;i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    printf("Soma iterativa dos elementos:\n");
    printf("%d\n",maior_soma(vet, tam_vet_teste));
    printf("Soma recursiva dos elementos:\n");
    printf("%d\n",maior_soma_r(vet, tam_vet_teste));
    return 0;
}
*/
//************inverte sequencia************

#include <stdio.h>

typedef struct node node;
struct node{
    int n;
    node *next;
};

node* trocaNos(node *no, node *ultimo_modificado){
    // condição de parada: se o nó seguinte for NULL ou se ele já for um valor que chegou ali por meio de trocas
    if(no->next == NULL || no->next == ultimo_modificado) return no;

    int aux_n = no->n;

    // troca o valor do nó atual com o do nó seguinte
    no->n = (no->next)->n;
    (no->next)->n = aux_n;
    
    //faz o mesmo com o próximo
    trocaNos(no->next, ultimo_modificado);
}

//inverte a pilha fazendo uma espécie de bubble sort 
void inverterPilha(node *no, int tam){
    node *ultimo_modificado = NULL;
    
    //repete o processo de trocar os valores tam-1 vezes
    for(int i=1; i<tam; i++){
       ultimo_modificado =  trocaNos(no, ultimo_modificado);
    }
}

//imprime lista
void printList(node *head){
    printf("%d ", head->n);

    if(head->next == NULL) return;
    else printList(head->next);
}

//************main************

int main(){

//************Problema da maior soma de subsequência em um vetor************

    int *res;
    int tam;
    int tam_vet_teste = 6;
    int vet[] = {-2, 11, -4, 13, -5, -2};
    res = vet_maior_soma(vet, tam_vet_teste, &tam);
    printf("Elementos do subvetor:\n");
    for(int i=0;i<tam;i++)
    {
        printf("%d ", res[i]);
    }
    printf("\n");
    printf("Soma iterativa dos elementos:\n");
    printf("%d\n",maior_soma(vet, tam_vet_teste));
    printf("Soma recursiva dos elementos:\n");
    printf("%d\n",maior_soma_r(vet, tam_vet_teste));


//************inverte sequencia************
    
    //cria nós e atribui valores
    node no1, no2, no3, no4;
    no1.n = 1; no2.n = 2; no3.n = 3, no4.n = 4;
    no1.next = &no2; no2.next = &no3; no3.next = &no4; no4.next = NULL;

    printList(&no1);

    inverterPilha(&no1, 4);
    
    printList(&no1);

    return 0;
}