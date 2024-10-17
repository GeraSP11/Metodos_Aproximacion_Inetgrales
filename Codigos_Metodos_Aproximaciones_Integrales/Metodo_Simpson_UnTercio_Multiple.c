#include <stdio.h>
#include <math.h>


double funcion(double x) {
    return 4 + 3 * cos(x);
}

double simpson(double a, double b, int n) {

	int i;
    double h = (b - a) / n;
    double sum = funcion(a) + funcion(b);

    for (i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * funcion(x);
        } else {
            sum += 4 * funcion(x);
        }
    }

    return (b - a) * (sum / (3 * n));
}

double simpson_tabla(double *x, double *fx, int n) {

	int i;
    double h = (x[0] - x[n-1]) / n;
    double sum = fx[0] + fx[n-1];

    for (i = 1; i < n; i++) {
        if (i % 2 == 0) {
            sum += 2 * fx[i];
        } else {
            sum += 4 * fx[i];
        }
    }

    return (x[0] - x[n-1]) * (sum / (3 * n));
}
int main() {
    double a, b, resultado;
    int n, opcion, i;

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

        resultado = simpson(a, b, n);
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

        resultado = simpson_tabla(x, fx, n);
        printf("Aproximacion de la integral usando la tabla: %.6lf\n", resultado);
    } else {
        printf("Opcion no valida.\n");
    }
    return 0;
}
