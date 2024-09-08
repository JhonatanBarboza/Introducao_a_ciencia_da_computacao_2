#include <stdio.h>
#include <stdlib.h>

//só um prototipo das coisas que precisa fazer aqui, como nao consigo testar nada é só pra ter uma ideia inicial
//explicação de cada função em cima dela 

typedef struct celula{
    int conteudo;
    celula *prox;
}celula;

//acho uma celula da lista com tal conteudo x dentro
celula *busca(int x, celula *ini){
    celula *p;
    p = ini;
    while(p != NULL && p->conteudo != x) p = p->prox;
    return p;
}

//removo uma celula com tal conteudo y dentro
void buscaRemove(int y, celula *ini){
    celula *p, *remove;
    p->prox = busca(y, ini); //acho o que quero rancar 
    remove = p->prox; //aqui guardo no remove o que quero tirar
    p->prox = remove->prox; //jogo o prox do p pro prox do remove (teoricamente pulo a posição do que quero tirar)
    free(remove); //dou free no que quero tirar
}

//insiro uma celula com conteudo x no final de uma lista
celula *insere(int x, celula *ini){
    celula *p, *criar;
    criar->conteudo = x;
    criar->prox = NULL;
    p = ini; //partindo do inicio
    while(p->prox != NULL) p = p->prox; //vou andando ate achar o fim da lista
    p->prox = criar; //na ultima posiçao coloco o que quero criar
    return p; //retorno a ultima posição (nao sei se precisava mas fiz isso)
}

//apago um numero x de celulas contando a partir do inicio da lista
void apagaGeral(int x, celula **p){ //como eu quero remover os bagulho direto, passo p como ponteiro duplo
    celula *aux;
    while(aux != NULL) aux->prox = (*p); //vou andando pra trás ate achar o começo da lista
    *p = aux; //partindo do começo da lista
    for(int i = 0; i < x; i++){
        free(*p); //vou apagando 
        *p = (*p)->prox; //e ando pra frente quando apago
    } //quando sair desse 'for' vou ter apagado as x primeiras posições
}   

//inverto uma lista inteira (nao pode usar lista auxiliar mas eu nao consegui fazer sem, perdao)
void inverte(celula **p){ //assim como no apagaGeral, como quero alterar diretamente eu passo p como ponteiro duplo
    celula *aux;
    int tam = 0; //esse aqui eu vou guardar o tamanho da lista pra dar free no aux dps

    while(aux != NULL) aux->prox = (*p); //vou andando pra trás ate achar o começo da lista
    *p = aux; //guardo o começo da lista no p

    while(aux->prox != NULL){
        aux = (*p)->prox; //agora vou andando pra frente pra deixar o final da lista no aux
        tam++; //uso o tam para mais tarde
    }

    while((*p)->prox != NULL || aux != NULL){
        (*p)->conteudo = aux->conteudo;
        (*p) = (*p)->prox; //ando pra frente o p
        aux->prox = aux; //ando pra tras o aux
    } //no fim do while vou ter invertido a lista no p

    apagaGeral(tam, &aux); //agora pra terminar a ideia de que nao posso usar outra lista vou apagar o aux inteiro
    //teoricamente ta errado fazer isso desse jeito pq ele pediu sem usar mais de uma lista, mas eu nao consegui kkkkkkkkk
    //por favor pensem algum modo de fazer isso diferente do que eu fiz
}

int main(void){
    //nao sei como fazer para testar as coisa... entao nao vou testar valeu eh nois
    return 0;
}