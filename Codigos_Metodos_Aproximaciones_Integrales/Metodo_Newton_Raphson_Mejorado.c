#include <stdio.h>
#include <math.h>
#include <windows.h>

double funcion(double x){
	return pow(x,4) - 2*pow(x,3) - 3*pow(x,2) - 4*x + 4;
}

double funciond(double x){
	return 4*pow(x,3) - 6*pow(x,2) + 6*x - 4;
}

double funciondd(double x){
	return 12*pow(x,2) - 12*x + 6;
}


double Newton_Raphson(double a, double tolerancia, int iteraciones){
	
	double c = 0.0, rsf = 0.0;
    int i;
    double error = 0.0;
    
    printf("\nMETODO NEWTON-RAPHSON MEJORADO\n");
    printf("\nIter\txi\t\tMEJORA\tError\n");
    
    for(i = 1; i <= iteraciones; i++) {
        
        rsf = (funcion(a) * funciond(a)) / (pow(funciond(a),2) - (funcion(a) * funciondd(a)));
        c = a - rsf;
        
        error = fabs( (c - a) / c ) * 100;
        
        if(c == 0 || error < tolerancia) {
        	printf("%d\t%lf\t%lf\t%lf\n", i, c, rsf, error);
            printf("Raiz encontrada en la iteracion %d: %lf\n", i, c);
            return c;
        }
        
        printf("%d\t%lf\t%lf\t%lf\n", i, c, rsf, error);
        
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
