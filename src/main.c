#include <stdio.h>
#include "calculadora.h"

int sumar(int a, int b){
    return a+b;
}

int restar(int a, int b){
    return a-b;
}

int multiplicar(int a, int b){
    return a*b;
}

int dividir(int a, int b){
    if (b == 0)
    {
        return 0;
    }

    return a/b;
}

int main(void){

    calculadora_t mi_calculadora = CrearCalculadora();

    AgregarOperacion(mi_calculadora, '+', sumar);
    AgregarOperacion(mi_calculadora, '-', restar);
    AgregarOperacion(mi_calculadora, '*', multiplicar);
    AgregarOperacion(mi_calculadora, '/', dividir);

    printf("--- Prueba de la calculadora ---\n");
    
    int resultado_suma = Calcular(mi_calculadora, 10, 5, '+');
    printf("10 + 5 = %d\n",resultado_suma);

    int resultado_resta = Calcular(mi_calculadora, 10, 5, '-');
    printf("10 - 5 = %d\n", resultado_resta);

    int resultado_mult = Calcular(mi_calculadora, 10, 5, '*');
    printf("10 * 5 = %d\n", resultado_mult);

    int resultado_div = Calcular(mi_calculadora, 10, 5, '/');
    printf("10 / 5 = %d\n", resultado_div);

    int resultado_desconocido = Calcular(mi_calculadora, 10, 5, '^');
    printf("10 ^ 5 (no registrada) = %d\n", resultado_desconocido);

    return 0;
}