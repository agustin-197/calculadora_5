/*********************************************************************************************************************
Copyright 2016-2025, Laboratorio de Microprocesadores
Facultad de Ciencias Exactas y Tecnologia
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

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

/** @file calculadora.h
 ** @brief Definiciones y firmas públicas de la calculadora abstracta.
 **/

/* === Headers files inclusions ==================================================================================== */

/* === Header for C++ compatibility ================================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =================================================================================== */

/* === Public data type declarations =============================================================================== */

/** @brief Definición del tipo de dato puntero a la estructura principal */
typedef struct calculadora_s * calculadora_t;

/** @brief Puntero a función tipado con los argumentos y el retorno de las operaciones */
typedef int (*operacion_func_t)(int, int);

/* === Public variable declarations ================================================================================ */

/* === Public function declarations ================================================================================ */

/**
 * @brief Crea un nuevo objeto de calculadora en un estado conocido.
 * @return calculadora_t Puntero a la instancia creada.
 */
calculadora_t CrearCalculadora(void);

/**
 * @brief Registra una nueva operación matemática en la calculadora.
 * @param calc Puntero a la instancia de la calculadora.
 * @param operador Carácter que representa la operación (ej. '+', '-').
 * @param funcion Puntero a la función que ejecuta el cálculo.
 */
void AgregarOperacion(calculadora_t calc, char operador, operacion_func_t funcion);

/**
 * @brief Identifica la operación y utiliza la función correspondiente para completar el cálculo.
 * @param calc Puntero a la instancia de la calculadora.
 * @param a Primer operando.
 * @param b Segundo operando.
 * @param operador Carácter que representa la operación a ejecutar.
 * @return int Resultado de la operación matemática.
 */
int Calcular(calculadora_t calc, int a, int b, char operador);

/* === End of conditional blocks =================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* CALCULADORA_H_ */