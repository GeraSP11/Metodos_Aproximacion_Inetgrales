#include <stdio.h>

double interpolar_newton(double x[], double y[], int n, double valor) {
    double diferencias[n][n];
    double resultado = y[0];
    double term;
    int i, j;

    for (i = 0; i < n; i++) {
        diferencias[i][0] = y[i];
    }

    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            diferencias[i][j] = (diferencias[i + 1][j - 1] - diferencias[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    printf("Diferencias Divididas:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            printf("%lf\t", diferencias[i - j][j]);
        }
        printf("\n");
    }

    for (i = 1; i < n; i++) {
        term = diferencias[0][i];
        for (j = 0; j < i; j++) {
            term *= (valor - x[j]);
        }
        resultado += term;
    }

    return resultado;
}

int main() {
    int n, i;
    double valor, resultado;

    printf("Introduce el numero de puntos: ");
    scanf("%d", &n);

    double x[n], y[n];

    for (i = 0; i < n; i++) {
        printf("Introduce el punto %d (x y): ", i + 1);
        scanf("%lf %lf", &x[i], &y[i]);
    }

    printf("Introduce el valor para interpolar: ");
    scanf("%lf", &valor);

    resultado = interpolar_newton(x, y, n, valor);

    printf("El valor interpolado en x = %lf es y = %lf\n", valor, resultado);

    return 0;
}
