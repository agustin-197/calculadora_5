/** * @file main.c
 * @brief Programa principal para probar la calculadora abstracta.
 **/

#include <stdio.h>
#include "calculadora.h"

/**
 * @brief Implementación de la operación suma.
 * @param a Primer operando.
 * @param b Segundo operando.
 * @return int Resultado de la suma (a + b).
 */
int sumar(int a, int b){
    return a+b;
}

/**
 * @brief Implementación de la operación resta.
 * @param a Primer operando.
 * @param b Segundo operando.
 * @return int Resultado de la resta (a - b).
 */
int restar(int a, int b){
    return a-b;
}

/**
 * @brief Implementación de la operación multiplicación.
 * @param a Primer operando.
 * @param b Segundo operando.
 * @return int Resultado de la multiplicación (a * b).
 */
int multiplicar(int a, int b){
    return a*b;
}

/**
 * @brief Implementación de la operación división con protección contra división por cero.
 * @param a Primer operando (dividendo).
 * @param b Segundo operando (divisor).
 * @return int Resultado de la división (a / b), o 0 si el divisor es 0.
 */
int dividir(int a, int b){
    if (b == 0)
    {
        return 0;
    }

    return a/b;
}

/**
 * @brief Función principal del programa.
 * * Crea una instancia de la calculadora abstracta, registra las operaciones básicas
 * (suma, resta, multiplicación y división) y ejecuta una serie de cálculos de prueba 
 * para verificar su correcto funcionamiento por consola.
 * * @return int Código de salida del programa (0 si la ejecución fue exitosa).
 */
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