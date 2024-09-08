#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// função interativa para encontrar a maior soma de subvetores de tamanho 3
int maior_soma_interantiva (int *sequencia, int tam){
    int resultado=0;
    int soma [tam];
    // calcula a soma dos de trez elementos em trez elementos 
    for (int i=0; i<tam-2 ; i++){
        soma[i] = sequencia [i] + sequencia [i+1] + sequencia [i+2];
    }
    // identivica a maior soma dos subvetores
    resultado = soma[0];
    for (int j=0 ; j<tam-2 ; j++){
        if (resultado<soma[j]){
            resultado = soma [j];
        }
    }
    return (resultado);
}

// função recursiva para encontrar a maior soma de subvetores de tamanho 3
int maior_soma_recursiva(int *sequencia, int tam) {
    if (tam <= 3) {
        int soma = 0;
        for (int i = 0; i < tam; i++) {
            soma += sequencia[i];
        }
        return soma;
    } else {
        // calcula a soma dos três primeiros elementos
        int soma_atual = sequencia[0] + sequencia[1] + sequencia[2];

        // calcula a maior soma dos subvetores restantes
        int maior_soma_restante = maior_soma_recursiva(sequencia + 1, tam - 1);

        // retorna o maior valor entre a soma atual e a maior soma restante
        return soma_atual > maior_soma_restante ? soma_atual : maior_soma_restante;
    }
}

int main(){

    int tam=0; 
    printf("digite o tamanho da sequencia: ");
    scanf("%d", &tam);
    if (tam<3){
        printf("sequencia de tamanho insuficiente!");
    }

    int sequencia[tam];
    printf("digite a sequencia: ");

    for (int i=0; i<tam ; i++)
        scanf("%d", &sequencia[i]);

    int res = maior_soma_interantiva(sequencia, tam);
    int ress = maior_soma_recursiva(sequencia, tam);

    printf("(interativo) A maior soma é %d\n", res);
    printf("(recurcivo)A maior soma é %d\n", ress);
    return 0;
}