## Mostre que $x⁴-23x³+12x²+15x-21 = \theta (x⁴)$

Para mostrar que $f(x)=x⁴-23x³+12x²+15x-21$ pertence a $\theta (x⁴)$ devemos verificar os limites superior $O(x⁴)$ e inferiore $\ohm(x⁴)$ de $f(x)$.

Primeiramente a função $f(x)$ é dominada pelo termo de maior ordem $x⁴$, assim para x suficientemente grande os termos $-23x³+12x²+15x-21$ são irelevantes. Assim podermos afirmar:

Limite superior $f(x)=o(x⁴)$

$f(x)=O(n⁴)$ (limitada superiormente) - já que $x⁴-23x³+12x²+15x-21 <= C.n⁴$ para um $C$ e um $n$ suficientemente grandes.

Limite inferior $f(x)=\ohm(x⁴)$

$f(x)=\ohm(n⁴)$ (limitada inferiormente) - já que $x⁴-23x³+12x²+15x-21 >= C'.n⁴$ para $C'>0$ 

Assim, podermos concluir que $f(x)$ tem o crecimento assintotico de $\theta(x⁴)$, pois é limitada superiormente $f(x)=O(n⁴)$ e inferiormente $f(x)=\omega(n⁴)$