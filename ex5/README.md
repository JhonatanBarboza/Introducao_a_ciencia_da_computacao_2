## Parte 1: Mostre que $f(x) = x^4 - 23x^3 + 12x^2 + 15x - 21$ pertence a $\Theta(x^4)$

Para mostrar que $f(x) \in \Theta(x^4)$, precisamos verificar que a função $f(x)$ está tanto em $O(x^4)$ (limite superior) quanto em $\Omega(x^4)$ (limite inferior).

### 1. Limite Superior: $f(x) = O(x^4)$

A função $f(x)$ é dominada pelo termo de maior ordem, que é $x^4$. Isso implica que, para $x$ suficientemente grande, os termos de menor ordem ($-23x^3 + 12x^2 + 15x - 21$) são insignificantes. Assim, temos que:

$f(x) = x^4 - 23x^3 + 12x^2 + 15x - 21 \leq C \cdot x^4 \quad \text{para algum} \, C > 0 \, \text{e} \, x \geq x_1.$

Portanto, $f(x) \in O(x^4)$.

### 2. Limite Inferior: $f(x) = \Omega(x^4)$

Como o termo dominante em $f(x)$ é $x^4$, podemos também afirmar que $f(x)$ não pode crescer mais lentamente do que $x^4$ para valores grandes de $x$. Formalmente, existe uma constante $C' > 0$ tal que:

$f(x) \geq C' \cdot x^4 \quad \text{para} \, x \geq x_2.$

Logo, $f(x) \in \Omega(x^4)$.

### Conclusão

Como $f(x)$ está limitada superiormente e inferiormente por $x^4$, podemos concluir que:

$f(x) \in \Theta(x^4).$

---

## Parte 2: Se $f(x) = O(g(x))$ e $g(x) = O(h(x))$, mostre que $f(x) = O(h(x))$

### Prova:

1. Sabemos que $f(x) = O(g(x))$, ou seja, existe uma constante $C_1 > 0$ e um $x_1$ tal que:
   $|f(x)| \leq C_1 |g(x)| \quad \text{para todo} \, x \geq x_1.$

2. Sabemos que $g(x) = O(h(x))$, ou seja, existe uma constante $C_2 > 0$ e um $x_2$ tal que:
   $|g(x)| \leq C_2 |h(x)| \quad \text{para todo} \, x \geq x_2.$

3. Substituindo a segunda desigualdade na primeira, obtemos:
   $|f(x)| \leq C_1 |g(x)| \leq C_1 C_2 |h(x)| \quad \text{para todo} \, x \geq \max(x_1, x_2).$

4. Portanto, $f(x) = O(h(x))$ com $C_3 = C_1 C_2$ e $x_3 = \max(x_1, x_2)$.

### Conclusão:

Assim, se $f(x) = O(g(x))$ e $g(x) = O(h(x))$, então $f(x) = O(h(x))$.

---

## Parte 3: Sejam f(n) e g(n) funções assintoticamente não negativas usando a definição basica da notação $\theta$. Prove que $max{ f(n), g(n) } = \theta (f(n) + g(n))$

A função $\max\{f(n), g(n)\}$ representa o maior valor entre $f(n)$ e $g(n)$ para um dado $n$. Isso significa que, para grandes valores de $n$, a função que cresce mais rapidamente (ou seja, a de ordem maior) irá dominar. 

A igualdade $\max\{f(n), g(n)\} = \Theta(f(n) + g(n))$ é válida porque, se uma das funções tiver uma ordem de crescimento maior, ela dominará tanto o máximo quanto a soma. Por exemplo, se $f(n)$ crescer mais rapidamente que $g(n)$, a soma $f(n) + g(n)$ será dominada por $f(n)$, o que faz com que o comportamento assintótico seja essencialmente o mesmo de $\max\{f(n), g(n)\}$.

Assim, a complexidade de $\max\{f(n), g(n)\}$ e de $f(n) + g(n)$ são assintoticamente equivalentes, o que justifica a validade da igualdade $\max\{f(n), g(n)\} = \Theta(f(n) + g(n))$.
