#include <stdio.h>
#include <math.h>
#include <windows.h>

double funcion(double x){
	/*double m = 68.1, v = 40, t = 10, g = 9.81;	
	return ((m*g)/x)*(1-exp(-x/m*t)) - v;*/
	
	//return exp(-x) - x;
		
	//return sin(x) + cos(1 + pow(x,2)) - 1;
	
	/*double W = 1000000.0, Q = 100000.0, V = 1000000.0, k = 0.25;
    return (W - Q*x - k*V*sqrt(x)) / V;*/
    
    return sin(x) + cos(1+pow(x,2)) - 1;
}

double Secante(double a, double b, double tolerancia, int iteraciones){
	
	double c = 0.0;
    int i;
    double error = 0.0;
    
    printf("\nMETODO DE LA SECANTE\n");
    printf("\nIter\txi\t\tf(xi-1)-f(xi)\tError\n");
    
    error = fabs( (a - 0) / a ) * 100;
    
    printf("%d\t%lf\t%lf\t%lf\n", -1, a, funcion(a), error);
    
    for(i = 0; i <= iteraciones; i++) {
    	
    	error = fabs( (b - a) / b ) * 100;
    	
    	printf("%d\t%lf\t%lf\t%lf\n", i, b, funcion(b), error);
    	
        c = b - (funcion(b) * (a - b)) / (funcion(a) - funcion(b));
        
        
        if(c == 0 || error < tolerancia) {
            printf("Raiz encontrada en la iteracion %d: %lf\n", i, b);
            return b;
        }
    	
    	a = b;
    	b = c;
    }
    
    printf("Iteraciones agotadas. Raiz aproximada: %lf\n", b);
    return b;
}

int main(){
	
	double a, b, tolerancia, raiz;
    int iteraciones;
    
    while(1){
    	printf("Introduce el primer punto (-1): ");
	    scanf("%lf", &a);
	    
	    printf("Introduce el segundo punto (0): ");
	    scanf("%lf", &b);
	    
	    printf("Introduce la tolerancia deseada: ");
	    scanf("%lf", &tolerancia);
	    
	    printf("Introduce el numero de iteraciones: ");
	    scanf("%d", &iteraciones);
	    
	    system("cls");
	    
	    raiz = Secante(a, b, tolerancia, iteraciones);
	    
	    system("pause");
	    system("cls");
	}
    	
    return 0;
	
}
