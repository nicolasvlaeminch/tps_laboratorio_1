/*
 * input.h
 *
 *  Created on: 1 oct 2022
 *      Author: Nicolas
 */

#ifndef INPUT_H_

int PedirEntero(char mensaje[], char mensajeError[], int min, int max);
int PedirCadena(char cadena[],int len,char mensaje[]);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

#define INPUT_H_



#endif /* INPUT_H_ */
