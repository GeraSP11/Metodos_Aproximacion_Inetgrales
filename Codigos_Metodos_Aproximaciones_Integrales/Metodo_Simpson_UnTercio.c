#include <stdio.h>
#include <math.h>


double funcion(double x) {
    return 4 + 3 * cos(x);
}

double simpson(double a, double b, int n) {

    double h = (b - a) / n, x;
    double sum = funcion(a) + funcion(b);
    int i;

    for (i = 1; i < n; i++) {
        x = a + i * h;
        sum += 4 * funcion(x);
    }

    return (b - a) * (sum / (3 * n));
}

int main() {
    double a, b, resultado;
    int n;

    printf("Ingrese el limite inferior del intervalo (a): ");
    scanf("%lf", &a);
    printf("Ingrese el limite superior del intervalo (b): ");
    scanf("%lf", &b);
    printf("Ingrese el numero de subintervalos (n, debe ser par): ");
    scanf("%d", &n);

    resultado = simpson(a, b, n);

    printf("El valor aproximado de la integral es: %lf\n", resultado);

    return 0;
}
