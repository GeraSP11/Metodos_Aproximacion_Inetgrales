#include <stdio.h>
#include <math.h>

// Declaración de funciones
double ecuacion(double x);
void entrada_datos(double *xi, double *xf, double *Ea, int *nmax);
int proceso(double xi, double xf, double Ea, int nmax);

int main() {
    double xi = 0.0, xf = 0.0, Ea = 0.0;
    int nmax;
    int res;

    do {
        entrada_datos(&xi, &xf, &Ea, &nmax);
        proceso(xi, xf, Ea, nmax);

        printf("Continuar? [0 = no, 1 = si]: ");
        scanf("%d", &res);

    } while (res == 1);

    return 0;
}

double ecuacion(double x) {
    return -pow(x, 2) + (4 * x) + 1;
}

void entrada_datos(double *xi, double *xf, double *Ea, int *nmax) {
    printf("\nIngrese valores para el intervalo.\n");
    printf("\tIngrese valor para xi: ");
    scanf("%lf", xi);
    printf("\tIngrese valor para xf: ");
    scanf("%lf", xf);

    printf("\nIngrese Error deseado: ");
    scanf("%lf", Ea);

    printf("\nIngrese numero maximo de iteraciones: ");
    scanf("%d", nmax);
}

int proceso(double xi, double xf, double Ea, int nmax) {
    double xr = 0.0, xrold = 0.0, error = 100.0;
    int ite = 0;
    double Es = Ea; // Error deseado
    double fxi, fxf, fxr;

    fxi = ecuacion(xi);
    fxf = ecuacion(xf);

    if (fxi * fxf > 0) {
        printf("\nNo existe raiz o existen multiples raices en el intervalo proporcionado.");
        return 1; // Indica que se debe intentar con un nuevo intervalo
    }

    while (error > Es && ite < nmax) {
        ite++;
        xrold = xr;
        xr = (xi + xf) / 2;
        fxr = ecuacion(xr);

        if (ite > 1) {
            error = fabs((xr - xrold) / xr) * 100;
        }

        printf("Iteracion %d: xr = %.6lf, error = %.6lf%%\n", ite, xr, error);

        if (fxi * fxr < 0) {
            xf = xr;
            fxf = fxr;
        } else {
            xi = xr;
            fxi = fxr;
        }

        if (fxr == 0.0) {
            error = 0.0; // La raíz exacta ha sido encontrada
            break;
        }
    }

    printf("La raiz aproximada es: %.6lf\n", xr);
    return 0; // Indica que el proceso terminó correctamente
}

