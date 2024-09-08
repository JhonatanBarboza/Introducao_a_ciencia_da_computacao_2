#include <stdio.h>
#include <stdlib.h>

//inverter uma lista de forma recursiva
//achar dentro de um vetor a subsequência que resulta na maior soma

typedef struct node_{
    int a; //o valor que vou guardar no nó
    struct node_ *next;
}NODE;

void inv(NODE **head, int *aux, int flag, int i, int tam){

    if(i < tam && !flag){ //vou andando pra frente enquanto a flag for 0
        aux[i] = (*head)->a;
        i++;
        inv(&(*head)->next, aux, flag, i, tam);

    }else if((*head)->next == NULL && !flag){ //quando achar o final, coloco a flag em 1
        flag = 1;
        inv(&head, aux, flag, i, tam);
    }else if(flag){
        head[tam - i]->a = aux[i];
        i--;
        inv(&head, aux, flag, i, tam);
        if(!i) return; //quando chegar em i == 0 quer dizer que ja inverti tudo, aí retorna
    }

}

void printa(NODE *head){
    if(head->next == NULL) return;
    printf("%d ", head->a);
    head = head->next;
    printa(head); //pra completar, printo a lista invertida recursivamente (nao precisava, fiz so por vontade mesmo)
}

int main(void){
    int flag = 0, tam, i, auxint; //vou usar como parametro pra flag no inv

    printf("digite o tamanho da sua lista: ");
    scanf("%d", &tam); //vou usar o tam pra printar invertido depois

    int *aux = malloc(sizeof(int) * i);
    NODE *head = malloc(sizeof(NODE) * i);

    printf("digite os valores de sua lista:\n");
    for(int j = 0; j < tam; j++){
        scanf(" %d", &auxint);
        head[j].a = auxint;
    }

    inv(&head, aux, flag, i, tam);
    printf("sua lista invertida:\n");
    printa(head);

}