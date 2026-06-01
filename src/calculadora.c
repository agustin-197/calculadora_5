/*********************************************************************************************************************
Copyright 2016-2025, Laboratorio de Microprocesadores
Facultad de Ciencias Exactas y Tecnología
Universidad Nacional de Tucuman
http://www.microprocesadores.unt.edu.ar/

Copyright 2016-2025, Esteban Volentini <evolentini@herrera.unt.edu.ar>

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

/** @file plantilla.c
 ** @brief Plantilla para la creación de archivos de código fuente en lenguaje C
 **/

/* === Headers files inclusions ================================================================ */

#include "calculadora.h"
#include <stdlib.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

typedef struct operacion_s
{
    char operador;
    operacion_func_t funcion;
    struct operacion_s *siguiente;
} *operacion_t;

struct calculadora_s
{
    operacion_t operaciones;
};



/* === Private function declarations =========================================================== */

static operacion_t BuscarOperacion(calculadora_t calc, char operador);

/* === Private variable definitions ============================================================ */

/* === Public variable definition  ============================================================= */

/* === Private function definitions ============================================================ */

/* === Public function implementation ========================================================== */

calculadora_t CrearCalculadora(void){

    calculadora_t calc = malloc(sizeof(struct calculadora_s));

    if (calc != NULL)
    {
        calc->operaciones = NULL;
    }

    return calc;

}

void AgregarOperacion(calculadora_t calc, char operador, operacion_func_t funcion){

    if (calc == NULL) return;

    operacion_t nueva_op = malloc(sizeof(struct operacion_s));

    if (nueva_op == NULL) return;

    nueva_op->operador = operador;
    nueva_op->funcion = funcion;

    nueva_op->siguiente = calc->operaciones;

    calc->operaciones = nueva_op;

}

int Calcular(calculadora_t calc, int a, int b, char operador){

    if (calc == NULL)
    {
        return 0;
    }

    operacion_t op = BuscarOperacion(calc, operador);

    if (op != NULL)
    {
        return op->funcion(a, b);
    }

    return 0;    

}

/* === Private function implementations ======================================================== */

static operacion_t BuscarOperacion(calculadora_t calc, char operador){

    operacion_t actual = calc->operaciones;

    while (actual != NULL) {

        if (actual->operador == operador)
        {
            return actual;
        }
        
        actual = actual->siguiente;
    }

    return NULL;
}

/* === End of documentation ==================================================================== */