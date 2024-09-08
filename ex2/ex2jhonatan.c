#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int meu_printf(const char formato[], ...);

int main(void) {
    int valor;
    scanf("%d", &valor);

    meu_printf("O valor é %d\n", valor);
    return EXIT_SUCCESS;
}

enum formato_caractere {
    FORMATO_INT = 'd',
};

#define TAMANHO_INT 12

int meu_printf(const char formato[], ...) {
    const char* iterador = formato;
    int contagem_caracteres = 0;
    va_list argumentos;

    va_start(argumentos, formato);

    while (*iterador) {
        if (*iterador == '%') {
            ++iterador;
            switch ((enum formato_caractere) *iterador) {
                case FORMATO_INT: {
                    char str_saida[TAMANHO_INT];
                    int numero = va_arg(argumentos, int);
                    sprintf(str_saida, "%d", numero);
                    char* iter_saida = str_saida;
                    for (; *iter_saida; ++iter_saida) {
                        putchar(*iter_saida);
                        ++contagem_caracteres;
                    }
                } break;
                default: {
                    fprintf(stderr, "Erro: formato inválido especificado: %c\n", *iterador);
                } break;
            }
            ++iterador;
            continue;
        }
        putchar(*iterador);
        ++contagem_caracteres;
        ++iterador;
    }

    return contagem_caracteres;
}
