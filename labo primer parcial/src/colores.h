/*
 * colores.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Pazos Ezequiel
 */

#ifndef COLORES_H_
#define COLORES_H_

typedef struct{
	int id;
	char nombreColor[20];
}eColor;

#endif /* COLORES_H_ */

int mostrarColores(eColor lista[], int tam);
int cargarNombreColor(eColor lista[], int tam, int idColor, char nombre[]);
