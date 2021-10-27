/*
 * trabajos.h
 *
 *  Created on: 27 oct. 2021
 *      Author: Pazos Ezequiel
 */

#include "fecha.h"

#ifndef TRABAJOS_H_
#define TRABAJOS_H_

typedef struct{
	int id; //AUTOINCREMENTAL
	int idMoto; //DEBE EXISTIR - VALIDAR
	int idServicio; //DEBE EXISTIR - VALIDAR
	eFecha fecha; //VALIDAR DIA, MES Y AÑO
	int isEmpty;
}eTrabajo;

#endif /* TRABAJOS_H_ */

int inicializarTrabajos(eTrabajo lista[], int tam);
int buscarLibreTrabajo(eTrabajo lista[], int tam);
int altaTrabajo(eTrabajo lista[], int tam, int* pId);
int mostrarTrabajos(eTrabajo lista[], int tam);
void mostrarTrabajo(eTrabajo unTrabajo);
