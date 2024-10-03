#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct para o funcionamento do timer
typedef struct {
    clock_t start;
    clock_t end;
} Timer;

// Variáveis globais para contagem de comparações e trocas
long long comparacoes = 0;
long long trocas = 0;

// Inicializa o timer
void start_timer(Timer *timer) {
    timer->start = clock();
}

// Para o timer e calcula o tempo decorrido
double stop_timer(Timer *timer) {
    timer->end = clock();
    return ((double)(timer->end - timer->start)) / CLOCKS_PER_SEC;
}

// Função para imprimir o tempo de execução, comparações e trocas
void imprimeEstatisticas(double tempo, const char *algoritmo) {
    printf("\n%s:\n", algoritmo);
    printf("Tempo de execução: %f segundos\n", tempo);
    printf("Comparações: %lld\n", comparacoes);
    printf("Trocas: %lld\n", trocas);
}

// Reseta as contagens globais para a próxima execução
void resetar_estatisticas() {
    comparacoes = 0;
    trocas = 0;
}

// Algoritmo original de ShellSort (h = n/2^k)
void shellsort(int *vet, int tam) {
    int aux, gap = tam / 2;
    while (gap > 0) {
        for (int i = gap; i < tam; i++) {
            aux = vet[i];
            int j = i;
            while (j >= gap) {
                comparacoes++;
                if (vet[j - gap] > aux) {
                    vet[j] = vet[j - gap];
                    j -= gap;
                    trocas++;
                } else {
                    break;
                }
            }
            vet[j] = aux;
        }
        gap /= 2;
    }
}

// Algoritmo de ShellSort com sequência de Knuth (h = (3^k - 1) / 2)
void shellsortknuth(int *vet, int tam) {
    int gap = 1;
    while (gap < tam) {
        gap = (3 * gap) + 1;
    }

    while (gap > 0) {
        for (int i = gap; i < tam; i++) {
            int tmp = vet[i];
            int j = i;
            while (j >= gap) {
                comparacoes++;
                if (vet[j - gap] > tmp) {
                    vet[j] = vet[j - gap];
                    j -= gap;
                    trocas++;
                } else {
                    break;
                }
            }
            vet[j] = tmp;
        }
        gap /= 3;
    }
}

// Algoritmo de ShellSort com sequência de Sedgewick
void shellsortsedgewick(int *vet, int n) {
    int gaps[] = {1, 5, 19, 41, 109, 209, 505, 929, 2309, 4621}; // Gaps pré-selecionados
    int size = sizeof(gaps) / sizeof(gaps[0]);

    for (int i = size - 1; i >= 0; i--) {
        int gap = gaps[i];
        if (gap > n) continue;
        for (int j = gap; j < n; j++) {
            int temp = vet[j];
            int k;
            for (k = j; k >= gap; k -= gap) {
                comparacoes++;
                if (vet[k - gap] > temp) {
                    vet[k] = vet[k - gap];
                    trocas++;
                } else {
                    break;
                }
            }
            vet[k] = temp;
        }
    }
}

// Algoritmo de ShellSort com sequência de Gonnet e Baeza-Yates
void shellsortgonnet(int *vet, int n) {
    int gaps[] = {1, 4, 10, 23, 57, 132, 301, 701, 1750, 4299}; // Gaps pré-selecionados
    int size = sizeof(gaps) / sizeof(gaps[0]);

    for (int i = size - 1; i >= 0; i--) {
        int gap = gaps[i];
        if (gap > n) continue;
        for (int j = gap; j < n; j++) {
            int temp = vet[j];
            int k;
            for (k = j; k >= gap; k -= gap) {
                comparacoes++;
                if (vet[k - gap] > temp) {
                    vet[k] = vet[k - gap];
                    trocas++;
                } else {
                    break;
                }
            }
            vet[k] = temp;
        }
    }
}

// Função para clonar o vetor original e evitar ordenações já feitas
void clonar_vetor(int *original, int *copia, int tam) {
    for (int i = 0; i < tam; i++) {
        copia[i] = original[i];
    }
}

// Função para gerar um vetor aleatório
void gerar_vetor_aleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

// Função para comparar as implementações do ShellSort
void comparar_implementacoes(int *vet_original, int tam) {
    Timer timer;
    int *vet = malloc(sizeof(int) * tam); // Vetor para clonar a entrada

    // ShellSort original
    clonar_vetor(vet_original, vet, tam);
    resetar_estatisticas();
    start_timer(&timer);
    shellsort(vet, tam);
    imprimeEstatisticas(stop_timer(&timer), "ShellSort original");

    // ShellSort com sequência de Knuth
    clonar_vetor(vet_original, vet, tam);
    resetar_estatisticas();
    start_timer(&timer);
    shellsortknuth(vet, tam);
    imprimeEstatisticas(stop_timer(&timer), "ShellSort com sequência de Knuth");

    // ShellSort com sequência de Sedgewick
    clonar_vetor(vet_original, vet, tam);
    resetar_estatisticas();
    start_timer(&timer);
    shellsortsedgewick(vet, tam);
    imprimeEstatisticas(stop_timer(&timer), "ShellSort com sequência de Sedgewick");

    // ShellSort com sequência de Gonnet e Baeza-Yates
    clonar_vetor(vet_original, vet, tam);
    resetar_estatisticas();
    start_timer(&timer);
    shellsortgonnet(vet, tam);
    imprimeEstatisticas(stop_timer(&timer), "ShellSort com sequência de Gonnet e Baeza-Yates");

    free(vet);
}

int main(void) {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int *vet = malloc(sizeof(int) * tam);
    
    gerar_vetor_aleatorio(vet, tam);

    printf("\nComparando as diferentes implementações de ShellSort:\n");
    comparar_implementacoes(vet, tam);

    free(vet);
    return 0;
}
