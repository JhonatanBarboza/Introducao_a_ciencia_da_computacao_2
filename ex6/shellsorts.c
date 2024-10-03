#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//exercicio pra comparar diferentes implementaçoes do shellsort (diferentes formas de escolher os "gaps" do algoritmo)

/*daqui pra baixo é pra funcionar o timer*/
// Struct para o funcionamento do timer
typedef struct{
    clock_t start;
    clock_t end;
}Timer;

// Inicializa o timer
void start_timer(Timer *timer){
    timer->start = clock();
}

// Para o timer e calcula o tempo decorrido
double stop_timer(Timer *timer){
    timer->end = clock();
    return ((double) (timer->end - timer->start)) / CLOCKS_PER_SEC;
}

void imprimeTempoDeExecucao(double tempo){
    printf("\ntempo de execução: %f segundos\n", tempo);
}
/*daqui pra frente é o codigo de vdd*/


void shellsort(int *vet, int tam){ //algoritmo original (h = n/2^k)
    printf("algoritmo do shellsort original:\n"); //esse printf é só pra funcionar pelo jeito que to chamando na main mesmo
    int aux, gap = tam/2;

    while(gap > 0){
        for(int i = gap; i < tam; i++){
            aux = vet[i];
            int j = i;
            while(j >= gap && vet[j - gap] > aux){
                vet[j] = vet[j - gap];
                j -= gap;
            }
            vet[j] = aux;
        }
        gap /= 2;
    }

    return;
}

void shellsortknuth(int *vet, int tam){ //algoritmo com a sequencia de knuth (h = (3^k - 1) / 2)
    printf("algoritmo do shellsort com a sequencia de knuth:\n"); //mesma coisa do printf de cima
    int gap = 1;
 
    while(gap < tam){
        gap = (3 * gap) + 1;
    }
 
    while(gap > 0){
        for (int i = gap; i < tam; i += gap) {
            int j = i;
            int tmp = vet[i];
 
            while((j >= gap) && (tmp < vet[j - gap])){
                vet[j] = vet[j - gap];
                j -= gap;
            }
            vet[j] = tmp;
        }
        gap /= 3;
    }

    return;
}

void shellsortsedgewick(int *vet, int n){ //algoritmo com a sequencia de sedgewick
    printf("algoritmo do shellsort com a sequencia de sedgewick:\n"); 
    int gaps[] = {1, 5, 19, 41, 109, 209, 505, 929, 2309, 4621}; //gaps selecionados na mão pq o algoritmo pra achar eles é embaçado demais
    int size = sizeof(gaps) / sizeof(gaps[0]);
    
    for(int i = size - 1; i >= 0; i--) {
        int gap = gaps[i];
        if(gap > n) continue; // ignora gaps maiores que n

        for(int j = gap; j < n; j++) {
            int temp = vet[j];
            int k;
            for(k = j; k >= gap && vet[k - gap] > temp; k -= gap){
                vet[k] = vet[k - gap];
            }

            vet[k] = temp;
        }
    }

    return;
}

void shellsortgonnet(int *vet, int n){ //algoritmo com a sequencia de gonnet e baeza-yates
    printf("algoritmo do shellsort com a sequencia de gonnet e baeza-yates:\n"); 
    int gaps[] = {1, 4, 10, 23, 57, 132, 301, 701, 1750, 4299}; //gaps selecionados na mão pelo mesmo motivo da sequencia de sedgewick
    int size = sizeof(gaps) / sizeof(gaps[0]);

    for(int i = size - 1; i >= 0; i--){
        int gap = gaps[i];
        if (gap > n) continue; //ignora gaps maiores que n
        for (int j = gap; j < n; j++) {
            int temp = vet[j];
            int k;
            for (k = j; k >= gap && vet[k - gap] > temp; k -= gap){
                vet[k] = vet[k - gap];
            }
            vet[k] = temp;
        }
    }

    return;
}

void printa(int *vet, int tam){ //printa o vetor
    for(int i = 0; i < tam; i++) printf("%d ", vet[i]);
    return;
}

int main(void){
    Timer timer; 
    int tam;
    scanf("%d", &tam);
    int *vet = malloc(sizeof(int) * tam);

    for(int i = 0; i < tam; i++) scanf(" %d", &vet[i]);

    printf("vetor antes da ordenação:\n");
    printa(vet, tam);
    printf("\nvetor depois da ordenação por ");
    start_timer(&timer);
    /*shellsort(vet, tam);
    shellsortsedgewick(vet, tam);
    shellsortknuth(vet, tam);
    shellsortgonnet(vet, tam);*/ //aqui ce tira do comentario o que quer testar (ta geral funcionando ok)
    printa(vet, tam);
    imprimeTempoDeExecucao(stop_timer(&timer));

    return 0;
}