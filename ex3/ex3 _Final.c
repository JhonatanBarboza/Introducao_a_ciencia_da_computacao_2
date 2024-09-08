#include <stdio.h>
#include <stdlib.h>

//************************3.1************************

typedef struct celula {
    int conteudo;
    struct celula *prox;
} celula;

celula *insereOrdenado(int x, celula *ini) {
    celula *nova, *p, *anterior = NULL;

    // faz a alocação dinamica de nova
    nova = (celula *)malloc(sizeof(celula));
    if (nova == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    nova->conteudo = x;

    // inserir no início da lista ou lista vazia
    if (ini == NULL || ini->conteudo >= x) {
        nova->prox = ini;
        return nova;
    }

    // busca pela posição de inserção
    p = ini;
    while (p != NULL && p->conteudo < x) {
        anterior = p;
        p = p->prox;
    }

    // inserção no meio ou final da lista
    anterior->prox = nova;
    nova->prox = p;

    return ini; // retorna o início da lista
}

//************************3.2************************

//removo uma celula que contiver a veriavel y
void buscaRemove(int y, celula *ini){

    celula *p = *ini, *remove = NULL;

    wlile(p != NULL && p->conteudo != y){
        anterior = p;
        p = p->prox;
    }
    
    //Se y não for encontrado retorna sem fazer nada
    if (p == NULL) return;

    //Se y estiver na primeira celula
    if (remove == NULL){
        *ini = p->prox;
    }
    else {
        remove->prox = p ->prox;
    }

    free(p);
}

//************************3.3************************

typedef struct node_{
    int data;
    struct node_* next;
} NODE;

NODE* nodeCreate(int d){
    NODE *new = (NODE *)malloc(sizeof(NODE));
    if(new == NULL){
        printf("Erro");
        exit(1);
    }
    new->data = d;
    new->next = NULL;
    return new;
}

NODE* addNode(NODE* n, int d){
    NODE* new = nodeCreate(d);
    if (n == NULL){
        return new;
    }
    NODE *cur = n;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = new;
    return n;
}

void printList(NODE* n){
    NODE* cur = n;
    while(cur != NULL){
        printf("%d - ", cur->data);
        cur = cur->next;
    }
    printf("Fim.");
}

NODE* removeFirst(NODE *n, int x){
    if (x<=0){
        return n;
    }

    NODE* cur = n;
    int i = 0;

    while(cur != NULL && i < x){
        NODE* t = cur;
        cur = cur->next;
        free(t);
        i++;
    }
    return cur;
}

NODE* clearNode(NODE* n){
    while(n != NULL){
        NODE* t = n;
        n = n->next;
        free(t);
        t = NULL;
    }
    n = NULL; //apenas certificando que n retorna null.
    return (n);
}

//************************3.4************************

//A função inverte uma lista encadeada
typedef struct cel {
    int conteudo;
    struct cel *prox;
} cel;

cel* inverte(cel* ini)
{
    int primeiro=0;
    //Ponteiro que irá ser retornado
    cel *ini_novo;
    //Ponteiro para voltar para o primeiro elemento da lista
    cel *anchor;
    //Ponteiro que percorrerá a lista
    cel *fin;
    //Ponteiro que percorrerá a lista após fin
    cel *aux;
    //Anchor recebe o endereço do primeiro elemento da lista
    anchor = ini;
    //O loop deve acabar quando anchor->prox == NULL, uma vez que,
    //depois de invertido, anchor é o último elemento.
    while(anchor->prox != NULL)
    {
        fin = anchor;
        //O while só irá parar quando chegar no último
        //elemento da parte que não está invertida
        while(fin->prox != NULL)
        {
            //Percorrendo a lista...
            aux = fin;
            fin = fin->prox;
        }
        //Se for a primeira vez, precisamos guardar o endereço apontado
        //por fin, uma vez que esse será o início da lista invertida
        if(primeiro == 0)
        {
            ini_novo = fin;
            primeiro = 1;
        }
        //Se fin != anchor, então há mais de um elemento na lista.
        //Então precisamos apontar o ponteiro do último elemento
        //para o penúltimo elemento e apontar o ponteiro->prox do
        //penúltimo elemento para NULL
        if(fin != anchor)
        {
            fin->prox = aux;
            aux->prox = NULL;
        }
        //Se fin == anchor, então precisamos apenas apontar fin->prox para NULL
        else
        {
            fin->prox = NULL;
        }
    }
    anchor = NULL;
    fin = NULL;
    aux = NULL;
    return ini_novo;
}
