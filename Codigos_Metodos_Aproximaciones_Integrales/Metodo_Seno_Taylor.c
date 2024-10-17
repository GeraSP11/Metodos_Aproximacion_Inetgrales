#include <stdio.h>
#include <math.h>

double taylor_seno(double x, int n) {
    double sum = 0.0;
    int i;
    double term;
    
    for (i = 0; i <= n; i++) {
        term = pow(-1, i) * pow(x, 2*i + 1) / tgamma(2*i + 1);
        sum += term;
        printf("\n%lf",sum);
    }

    return sum;
}

int main() {
    double x; 
    int n;     
	double resultado = 0.0;

	printf("\nValor a aproximar seno(x): ");
	scanf("%lf",&x);
	printf("\nNumero de terminos de la serie de Taylor: ");
	scanf("%d",&n);

    resultado = taylor_seno(x, n);

    printf("\nResultado: %lf\n",resultado);

    return 0;
}
