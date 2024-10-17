#include <stdio.h>
#include <math.h>
#include <windows.h>

// Función a la que se desea calcular la raíz (modificar según sea necesario)
double funcion(double x) {
	
	return (-5*x*exp(-x)) - cos(5*x) + pow(x,3) - (2 * pow(x,2) * cos(2*x)) - 12;

}

// Método de bisección
double biseccion(double a, double b, double tolerancia, int iteraciones) {
    double c;
    int i;
    double error = 0.0, act = 0.0, ant = 0.0;
    
    printf("\nMETODO DE BISECCION\n");
    printf("\nIter\txl\t\txu\t\tf(xl)\t\tf(xu)\t\txr\t\tf(xr)\t\tf(xl)*f(xr)\tError\n");
    
    for(i = 1; i <= iteraciones; i++) {
        c = (a + b) / 2;
        act = c;
        
        error = fabs( (act - ant) / act ) * 100;
        
        if(funcion(b)*funcion(a) < 0){
        	printf("No existe raiz o existen multiples raices");
        	return 0;
		} else if (funcion(c) == 0 || error < tolerancia) {
        	printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", i, a, b, funcion(a), funcion(b), c, funcion(c), ( funcion(c) * funcion(a) ), error);
            printf("Raiz encontrada en la iteracion %d: %lf\n", i, c);
            return c;
        }
        
        printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", i, a, b, funcion(a), funcion(b), c, funcion(c), ( funcion(c) * funcion(a) ), error);
        
        if(funcion(c) * funcion(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        
        ant = act;
    }
    
    printf("Iteraciones agotadas. Raiz aproximada: %lf\n", c);
    return c;
}

// Método de falsa posición
double falsaPosicion(double a, double b, double tolerancia, int iteraciones) {
    double c;
    int i;
    double error = 0.0, act = 0.0, ant = 0.0;
    
    printf("\nMETODO DE FALSA POSICION\n");
    printf("\nIter\txl\t\txu\t\tf(xl)\t\tf(xu)\t\txr\t\tf(xr)\t\tf(xl)*f(xr)\tError\n");
    
    for(i = 1; i <= iteraciones; i++) {
        c = (a * funcion(b) - b * funcion(a)) / (funcion(b) - funcion(a));
        act = c;
        
        error = fabs( (act - ant) / act ) * 100;
        
        if(funcion(b)*funcion(a) < 0){
        	printf("no existe raiz o existen multiples raices");
        	return 0;
		} else if (funcion(c) == 0 || error < tolerancia) {
        	printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", i, a, b, funcion(a), funcion(b), c, funcion(c), ( funcion(c) * funcion(a) ), error);
            printf("Raiz encontrada en la iteracion %d (Falsa Posicion): %lf\n", i, c);
            return c;
        }
        
        printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", i, a, b, funcion(a), funcion(b), c, funcion(c), ( funcion(c) * funcion(a) ), error);
        
        if(funcion(c) * funcion(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        
        ant = act;
    }
    
    printf("Iteraciones agotadas (Falsa Posicion). Raiz aproximada: %lf\n", c);
    return c;
}

// Método de falsa posición mejorada
double falsaPosicionMejorada(double a, double b, double tolerancia, int iteraciones) {
    double c, c_ant = 0;
    int i;
    double error = 0.0, act = 0.0, ant = 0.0;
    
    printf("\nMETODO DE FALSA POSICION MEJORADA\n");
    printf("\nIter\txl\t\txu\t\tf(xl)\t\tf(xu)\t\txr\t\tf(xr)\t\tf(xl)*f(xr)\tError\n");
    
    for(i = 1; i <= iteraciones; i++) {
        c = (a * funcion(b) - b * funcion(a)) / (funcion(b) - funcion(a));
        act = c;
        error = fabs( (act - ant) / act ) * 100;
        
        if(funcion(c) == 0 || error < tolerancia) {
        	printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", i, a, b, funcion(a), funcion(b), c, funcion(c), ( funcion(c) * funcion(a) ), error);
            printf("Raiz encontrada en la iteracion %d (Falsa Posicion Mejorada): %lf\n", i, c);
            return c;
        }
        
        printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", i, a, b, funcion(a), funcion(b), c, funcion(c), ( funcion(c) * funcion(a) ), error);
        
        if(funcion(c) * funcion(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        
        ant = act;
    }
    
    printf("Iteraciones agotadas (Falsa Posicion Mejorada). Raiz aproximada: %lf\n", c);
    return c;
}

int main() {
    double a, b, tolerancia, raiz;
    int iteraciones, metodo;
    
    while(1){
    	printf("Introduce el punto bajo a: ");
	    scanf("%lf", &a);
	    
	    printf("Introduce el punto alto b: ");
	    scanf("%lf", &b);
	    
	    printf("Introduce la tolerancia deseada: ");
	    scanf("%lf", &tolerancia);
	    
	    printf("Introduce el numero de iteraciones: ");
	    scanf("%d", &iteraciones);
	    
	    printf("Seleccione el metodo para encontrar la raiz:\n");
	    printf("1. Biseccion\n");
	    printf("2. Falsa Posicion\n");
	    printf("3. Falsa Posicion Mejorada\n");
	    scanf("%d", &metodo);
	    
	    switch(metodo) {
	        case 1:
	        	system("cls");
	            raiz = biseccion(a, b, tolerancia, iteraciones);
	            break;
	        case 2:
	        	system("cls");
	            raiz = falsaPosicion(a, b, tolerancia, iteraciones);
	            break;
	        case 3:
	        	system("cls");
	            raiz = falsaPosicionMejorada(a, b, tolerancia, iteraciones);
	            break;
	        default:
	            printf("Opcion no valida.\n");
		}
		
		system("pause");
		system("cls");
	}
    
    return 0;
}

