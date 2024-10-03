## Atividade: Ordenação - ShellSort e Inserção Simples

Exercício: Formar aleatoriamente vetores de tamanho razoavelmente grande,
e verificar como a escolha da sequencia de h afeta o desempenho do método.
Entregar um grafico ou tabela de tempo de execucao com as variaçoes possiveis,
incluindo o tempo do método de inserção simples.


Neste relatório, analisamos como diferentes sequências de espaçamento influenciam o desempenho do algoritmo ShellSort, comparando implementações com as sequências original, de Knuth, Sedgewick, e Gonnet e Baeza-Yates. São avaliados tempos de execução, número de comparações e trocas em vetores de tamanhos variados, além de uma comparação com o método de inserção simples, destacando o impacto dessas escolhas na eficiência da ordenação.

![comparação_aleatoria](https://github.com/user-attachments/assets/802bc3cf-e658-447d-9edf-8a454db5b139)

_______________________________________________________

Digite o tamanho do vetor: 100

Comparando as diferentes implementações de ShellSort:

ShellSort original:
Tempo de execução: 0.000021 segundos
Comparações: 958
Trocas: 516

ShellSort com sequência de Knuth:
Tempo de execução: 0.000017 segundos
Comparações: 792
Trocas: 498

ShellSort com sequência de Sedgewick:
Tempo de execução: 0.000021 segundos
Comparações: 717
Trocas: 440

ShellSort com sequência de Gonnet e Baeza-Yates:
Tempo de execução: 0.000018 segundos
Comparações: 736
Trocas: 384

_______________________________________________________

Digite o tamanho do vetor: 500

Comparando as diferentes implementações de ShellSort:

ShellSort original:
Tempo de execução: 0.000108 segundos
Comparações: 6124
Trocas: 2873

ShellSort com sequência de Knuth:
Tempo de execução: 0.000096 segundos
Comparações: 5954
Trocas: 3686

ShellSort com sequência de Sedgewick:
Tempo de execução: 0.000096 segundos
Comparações: 5768
Trocas: 3398

ShellSort com sequência de Gonnet e Baeza-Yates:
Tempo de execução: 0.000141 segundos
Comparações: 5666
Trocas: 2925

_______________________________________________________


Digite o tamanho do vetor: 1000 

Comparando as diferentes implementações de ShellSort:

ShellSort original:
Tempo de execução: 0.000304 segundos
Comparações: 14898
Trocas: 7394

ShellSort com sequência de Knuth:
Tempo de execução: 0.000249 segundos
Comparações: 14708
Trocas: 9698

ShellSort com sequência de Sedgewick:
Tempo de execução: 0.000217 segundos
Comparações: 13371
Trocas: 7681

ShellSort com sequência de Gonnet e Baeza-Yates:
Tempo de execução: 0.000245 segundos
Comparações: 13004
Trocas: 6673
_
______________________________________________________


Digite o tamanho do vetor: 1500

Comparando as diferentes implementações de ShellSort:

ShellSort original:
Tempo de execução: 0.000439 segundos
Comparações: 24856
Trocas: 12132

ShellSort com sequência de Knuth:
Tempo de execução: 0.000386 segundos
Comparações: 24347
Trocas: 16100

ShellSort com sequência de Sedgewick:
Tempo de execução: 0.000345 segundos
Comparações: 21933
Trocas: 12526

ShellSort com sequência de Gonnet e Baeza-Yates:
Tempo de execução: 0.000422 segundos
Comparações: 20963
Trocas: 10930

_______________________________________________________


Digite o tamanho do vetor: 30000

Comparando as diferentes implementações de ShellSort:

ShellSort original:
Tempo de execução: 0.011534 segundos
Comparações: 959132
Trocas: 584280

ShellSort com sequência de Knuth:
Tempo de execução: 0.011393 segundos
Comparações: 877295
Trocas: 634617

ShellSort com sequência de Sedgewick:
Tempo de execução: 0.011624 segundos
Comparações: 684019
Trocas: 402688

ShellSort com sequência de Gonnet e Baeza-Yates:
Tempo de execução: 0.015741 segundos
Comparações: 672763
Trocas: 389279

_______________________________________________________


Digite o tamanho do vetor: 100000

Comparando as diferentes implementações de ShellSort:

ShellSort original:
Tempo de execução: 0.055368 segundos
Comparações: 4251430
Trocas: 2801875

ShellSort com sequência de Knuth:
Tempo de execução: 0.033405 segundos
Comparações: 3682665
Trocas: 2757110

ShellSort com sequência de Sedgewick:
Tempo de execução: 0.027608 segundos
Comparações: 2863511
Trocas: 1887546

ShellSort com sequência de Gonnet e Baeza-Yates:
Tempo de execução: 0.027580 segundos
Comparações: 2898647
Trocas: 1920118

_______________________________________________________

Digite o tamanho do vetor: 10000000

Comparando as diferentes implementações de ShellSort:

ShellSort original:
Tempo de execução: 5.240454 segundos
Comparações: 982831242
Trocas: 767843360

ShellSort com sequência de Knuth:
Tempo de execução: 4.760054 segundos
Comparações: 988981418
Trocas: 853884842

ShellSort com sequência de Sedgewick:
Tempo de execução: 62.836981 segundos
Comparações: 5866724637
Trocas: 5766769994

ShellSort com sequência de Gonnet e Baeza-Yates:
Tempo de execução: 77.061970 segundos
Comparações: 6318151467
Trocas: 6218192579