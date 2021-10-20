/*
 * tipos.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Pazos Ezequiel
 */

#ifndef TIPOS_H_
#define TIPOS_H_

typedef struct{
	int id;
	char descripcion[20];
}eTipo;

#endif /* TIPOS_H_ */

int mostrarTipos(eTipo lista[], int tam);
