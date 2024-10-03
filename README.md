# Repositório de Atividades - Introdução à Ciência da Computação 2

Bem-vindo ao repositório da disciplina de Introdução à Ciência da Computação 2. Aqui, você encontrará todos os exercícios e atividades que serão desenvolvidos ao longo do curso. Este espaço também servirá para coordenar o andamento das tarefas e facilitar a colaboração entre os participantes.


## Exercicio 1 - (19/08/2024)

1. Escreva uma função que transforme uma
string (que contenha apenas dígitos) em um
número float, para uma dada base.
int strtofloat(char *string, int base)

2. Escreva um programa que leia duas
strings, que as junte numa string só e
imprima o tamanho e o conteúdo da string
final.

3. Escreve um trecho de código que
substitua uma substring por outra

## Exercicio 2 - (22/08/2024)

1. Usando a biblioteca stdarg.h, implemente a função com o seguinte protótipo void printf(char *str, ...);

Considere como formatação possível apenas %u

Range do %u: 0 até 4294967295

## Exercicio 3 - (26/08/2024)

1. Escreva uma que insira uma nova célula
com conteúdo x em uma lista ordenada. A
lista deve continuar ordenada após a
inserção
- Utilize alocação dinâmica

2. Escreva uma função que remova a
primeira ocorrência de x na lista
 void buscaRemove(int y, celula *ini); 

3. Crie uma função que receba como
parâmetros: uma lista encadeada e um
número inteiro positivo (x). A função deve
remover os x primeiros elementos da lista
e retornar a lista modificada. Se x for
maior do que o tamanho da lista, a função
deve retornar uma lista vazia.

4. Escreva uma função em C que inverte a
ordem dos itens de uma lista encadeada
sem usar espaço auxiliar

## Exercicio 4 - (29/08/2024)
1. Problema da maior soma de subsequência
em um vetor
- Implemente um programa iterativo para
resolver o problema
- Implemente um problema recursivo

## Exercicio 5 - (12/09/2024)
Parte 1: Mostre que $f(x) = x^4 - 23x^3 + 12x^2 + 15x - 21$ pertence a $\Theta(x^4)$

Parte 2: Se $f(x) = O(g(x))$ e $g(x) = O(h(x))$, mostre que $f(x) = O(h(x))$

Parte 3: Sejam f(n) e g(n) funções assintoticamente não negativas usando a definição basica da notação $\theta$. Prove que $max{ f(n), g(n) } = \theta (f(n) + g(n))$

## Exercicio 6 - (30/09/2024)
Exercício: Formar aleatoriamente vetores de tamanho razoavelmente grande,
e verificar como a escolha da sequencia de h afeta o desempenho do método.
Entregar um grafico ou tabela de tempo de execucao com as variaçoes possiveis,
incluindo o tempo do método de inserção simples.  
