#include <stdio.h>
#include <math.h>
#include <windows.h>

double funcion(double x){
	//return  (pow(x,4) - 2*pow(x,3) - 3*pow(x,2) - 4*x + 4) / (4*pow(x,3) - 6*pow(x,2) + 6*x - 4);
	
	//return  (2*sin(sqrt(x)) - x) / (cos(sqrt(x)) / sqrt(x) - 1);
	
	/*double W = 1000000.0, Q = 100000.0, V = 1000000.0, k = 0.25;
    return ((W - Q*x - k*V*sqrt(x)) / V) / (-Q/V-k/(2*sqrt(x)));*/
    
//    return (2*pow(x,3) - 11.7*pow(x,2) + 17.7*x - 5) / (6*pow(x,2) - 23.4*x + 17.7);

	return (sin(x) + cos(1+pow(x,2)) - 1) / (cos(x) - 2 * x * sin(1-pow(x,2)));
}

double Newton_Raphson(double a, double tolerancia, int iteraciones){
	
	double c = 0.0;
    int i;
    double error = 0.0;
    
    printf("\nMETODO NEWTON-RAPHSON\n");
    printf("\nIter\txi\t\tf(xi)/f'(xi)\tError\n");
    
    for(i = 1; i <= iteraciones; i++) {
        
		c = a - funcion(a);
        
        error = fabs( (c - a) / c ) * 100;
        
        if(c == 0 || error < tolerancia) {
        	printf("%d\t%lf\t%lf\t%lf\n", i, c, funcion(a), error);
            printf("Raiz encontrada en la iteracion %d: %lf\n", i, c);
            return c;
        }
        
        printf("%d\t%lf\t%lf\t%lf\n", i, c, funcion(a), error);
        
        a = c;
    }
    
    printf("Iteraciones agotadas. Raiz aproximada: %lf\n", c);
    return c;
}

int main(){
	
	double a, tolerancia, raiz;
    int iteraciones;
    
    while(1){
    	printf("Introduce el punto de partida: ");
	    scanf("%lf", &a);
	    
	    printf("Introduce la tolerancia deseada: ");
	    scanf("%lf", &tolerancia);
	    
	    printf("Introduce el numero de iteraciones: ");
	    scanf("%d", &iteraciones);
	    
	    system("cls");
	    
	    raiz = Newton_Raphson(a, tolerancia, iteraciones);
	    
	    system("pause");
	    system("cls");
	}
    	
    return 0;
	
}
