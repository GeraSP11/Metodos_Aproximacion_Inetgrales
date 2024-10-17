#include <stdio.h>

// Funcion para calcular el polinomio de Lagrange
float lagrange(float x[], float y[], int n, float xp) {
    float p = 0;
    for (int i = 0; i < n; i++) {
        float L = 1;
        for (int j = 0; j < n; j++) {
            if (j != i)
                L *= (xp - x[j]) / (x[i] - x[j]);
        }
        p += L * y[i];
    }
    return p;
}

int main() {
    // Puntos de datos ejemplo
    float x[] = {1, 2, 3, 4};
    float y[] = {1, 4, 9, 16};
    int n = sizeof(x) / sizeof(x[0]);
    
    // Punto a interpolar
    float xp = 2.5;
    
    // Resultado
    float yp = lagrange(x, y, n, xp);
    
    printf("El valor interpolado en x = %.2f es y = %f\n", xp, yp);
    
    return 0;
}
