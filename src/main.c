/*********************************************************************************************************************
Copyright 2016-2025, Laboratorio de Microprocesadores
Facultad de Ciencias Exactas y Tecnología
Universidad Nacional de Tucuman
http://www.microprocesadores.unt.edu.ar/

Copyright 2026, Díaz Gerardo Agustín <agustin041097@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/

/** @file main.c
 ** @brief Programa principal para probar la calculadora abstracta.
 ** @author Díaz Gerardo Agustín
 **/

/* === Headers files inclusions ================================================================ */

#include <stdio.h>
#include "calculadora.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private function declarations =========================================================== */

/* === Private variable definitions ============================================================ */

/* === Public variable definition  ============================================================= */

/* === Private function definitions ============================================================ */

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

/* === Public function implementation ========================================================== */

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

/* === End of documentation ==================================================================== */