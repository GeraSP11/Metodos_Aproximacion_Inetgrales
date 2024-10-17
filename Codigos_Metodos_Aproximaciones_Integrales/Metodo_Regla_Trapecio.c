#include <stdio.h>
#include <math.h>

double funcion(double x) {
    return 4 + 3 * cos(x);
}

double calcular_integral_funcion(double (*func)(double), double a, double b, int n) {
    double h, sumatoria, resultado;
    int i;
    h = (b - a) / n;
    sumatoria = 0.0;

    for (i = 1; i < n; i++) {
        sumatoria += func(a + i * h);
    }

    resultado = (h / 2) * (func(a) + (2 * sumatoria) + func(b));
    return resultado;
}

double calcular_integral_tabla(double *x, double *fx, int n) {
    double h, sumatoria, resultado;
    int i;
    sumatoria = 0.0;

    for (i = 1; i < n - 1; i++) {
        sumatoria += fx[i];
    }

    h = (x[n - 1] - x[0]) / (n - 1);
    resultado = (h / 2) * (fx[0] + (2 * sumatoria) + fx[n - 1]);
    return resultado;
}

int main() {
    double a, b;
    int n, opcion, i;
    double resultado;

    printf("METODO DE LA REGLA DEL TRAPECIO MULTIPLE\n");
    printf("Seleccione el metodo de entrada:\n");
    printf("1. Usar la función predefinida\n");
    printf("2. Ingresar valores de una tabla\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        // Usar la función predefinida
        printf("Ingrese intervalo...\nx0: ");
        scanf("%lf", &a);
        printf("xn: ");
        scanf("%lf", &b);

        printf("Ingrese el numero de subintervalos n: ");
        scanf("%d", &n);

        resultado = calcular_integral_funcion(funcion, a, b, n);
        printf("Aproximacion de la integral usando la función: %.6lf\n", resultado);
    } else if (opcion == 2) {
        // Ingresar valores de una tabla
        printf("Ingrese el numero de puntos en la tabla n: ");
        scanf("%d", &n);

        double x[n], fx[n];

        for (i = 0; i < n; i++) {
            printf("Ingrese x[%d]: ", i);
            scanf("%lf", &x[i]);
            printf("Ingrese f(x[%d]): ", i);
            scanf("%lf", &fx[i]);
        }

        resultado = calcular_integral_tabla(x, fx, n);
        printf("Aproximacion de la integral usando la tabla: %.6lf\n", resultado);
    } else {
        printf("Opcion no valida.\n");
    }

    return 0;
}

