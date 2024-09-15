## Mostre que $x⁴-23x³+12x²+15x-21 = \theta (x⁴)$

Para mostrar que $f(x)=x⁴-23x³+12x²+15x-21$ pertence a $\theta (x⁴)$ devemos verificar os limites superior $O(x⁴)$ e inferiore $\ohm(x⁴)$ de $f(x)$.

Primeiramente a função $f(x)$ é dominada pelo termo de maior ordem $x⁴$, assim para x suficientemente grande os termos $-23x³+12x²+15x-21$ são irelevantes. Assim podermos afirmar:

Limite superior $f(x)=o(x⁴)$

$f(x)=O(n⁴)$ (limitada superiormente) - já que $x⁴-23x³+12x²+15x-21 <= C.n⁴$ para um $C$ e um $n$ suficientemente grandes.

Limite inferior $f(x)=\ohm(x⁴)$

$f(x)=\ohm(n⁴)$ (limitada inferiormente) - já que $x⁴-23x³+12x²+15x-21 >= C'.n⁴$ para $C'>0$ 

Assim, podermos concluir que $f(x)$ tem o crecimento assintotico de $\theta(x⁴)$, pois é limitada superiormente $f(x)=O(n⁴)$ e inferiormente $f(x)=\omega(n⁴)$

## Seja $f(x)=O(g(x))$ e $g(x)=O(h(x))$, mostre que $f(x)=O(h(x))$

Definição de Big-O:

$f(x) = O(g(x))$ significa que existem constantes positivas $C$ e $x.1$ tais que: $f(x)\leq C(g(x))$ para todo $x \geq x.1$

Para provar que $f(x) = O(h(x))$, ou seja, queremos mostrar que existem constantes positivas $C_3$ e $x_3$ tais que:
$|f(x)| \leq C_3 |h(x)|$ para todo $\ x \geq x_3$.

1. Sabemos que $f(x) = O(g(x))$, então existe uma constante $c_1$ e $x_1$ tal que:$|f(x)| \leq C_1 |g(x)| \quad \text{para todo} \ x \geq x_1.$
   
2. Sabemos que $g(x) = O(h(x))$, então existe uma constante $C_2$ e $x_2$ tal que:$|g(x)| \leq C_2 |h(x)| \quad \text{para todo} \ x \geq x_2.$
   
3. Substituindo a segunda inequação na primeira, temos:$|f(x)| \leq C_1 |g(x)| \leq C_1 C_2 |h(x)| \quad \text{para todo} \ x \geq \max(x_1, x_2).$

4. Portanto, temos $|f(x)| \leq C_3 |h(x)|$ para $C_3 = C_1 C_2$ e $x_3 = \max(x_1, x_2)$.

Assim, se $f(x) = O(g(x))$ e $g(x) = O(h(x))$, então $f(x) = O(h(x))$, pois a constante de proporcionalidade $C_3$ pode ser obtida como o produto das constantes $C_1$ e $C_2$.