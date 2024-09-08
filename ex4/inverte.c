#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct celula
{
    int n;
    struct celula * next;
}cel;

cel* cria(cel* list)
{
    list = NULL;
    return list;
}

bool vazio(cel* list)
{
    if(list != NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void insere(cel** list, int p)
{
    cel *a, *ptr1, *ptr2;
    a = (cel*) malloc (sizeof(cel));
    a->n = p;
    a->next = NULL;
    ptr1 = *list;
    if(vazio(*list))
    {
        *list = a;
    }
    else
    {
        while(ptr1 != NULL)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        ptr2->next = a;
    }
}

void print(cel* list)
{
    cel* ptr1;
    ptr1 = list;
    if(vazio(list))
    {
        printf("Lista vazia!\n");
    }
    else
    {
        while(ptr1 != NULL)
        {
            printf("%d ", ptr1->n);
            ptr1 = ptr1->next;
        }
        printf("\n");
    }
}

void inverte(cel** list, cel* aux)
{
    //Verifica se a lista está vazia
    if(*list == NULL)
    {
        return;
    }
    else
    {
        //Guarda o endereço da célula seguinte
        cel* next = (*list)->next;
        //Inverte
        (*list)->next = aux;
        //Se next for NULL, não precisa mais inverter,
        //uma vez que já está no final da lista
        if(next == NULL)
        {
            return;
        }
        //Recursão, chamando a função inverte com uma lista encadeada
        //sem o elemento que acabou de ser invertido
        inverte(&next, *list);
        //Atualizando o valor de lista
        *list = next;
    }
}

int main()
{
    cel* a;
    cel* aux;
    a = cria(a);
    insere(&a, 4);
    insere(&a, 4);
    insere(&a, 4);
    insere(&a, 8);
    insere(&a, 7);
    insere(&a, 3);
    insere(&a, 1);
    insere(&a, 4);
    print(a);
    inverte(&a, aux);
    print(a);
    return 0;
}