#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void meu_printf(char *formato, ...) {
    char msg[1024] = { 0 };
    va_list ap;

    va_start(ap, formato);
    vsprintf(msg, formato, ap);
    va_end(ap);

    for (unsigned int i = 0; i < strlen(msg); i++) {
        if (msg[i] == '\\' && msg[i + 1] == 'n') { // nova linha
            putchar('\n'); // nova linha
            i++;
        } else if (msg[i] == '\\' && msg[i + 1] == 't') { // tabulação
            putchar('\t'); // tabulação
            i++;
        } else {
            putchar(msg[i]);
        }
    }
}

int main() {
    char *formato = "%d";
    int num;

    printf("Digite seu número: ");
    scanf("%d", &num);

    meu_printf(formato, num);
    printf("\n\n");

    return 0;
}
