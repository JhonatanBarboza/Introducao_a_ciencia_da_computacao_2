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

int main(){
    //cria nós e atribui valores
    node no1, no2, no3, no4;
    no1.n = 1; no2.n = 2; no3.n = 3, no4.n = 4;
    no1.next = &no2; no2.next = &no3; no3.next = &no4; no4.next = NULL;

    printList(&no1);

    inverterPilha(&no1, 4);
    
    printList(&no1);
}