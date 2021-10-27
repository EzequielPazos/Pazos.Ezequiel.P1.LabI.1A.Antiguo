/*
 * validaciones.c
 *
 *  Created on: 27 oct. 2021
 *      Author: Ezequiel Pazos
 */

#include <stdio.h>
#include <stdlib.h>
#include "tipos.h"
#include "colores.h"

int validarIdTipo(eTipo lista[], int tam, int id){

	int existe = 0;

	if(lista !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(lista[i].id == id)
			{
				existe = 1;
				break;
			}
		}
	}
	return existe;
}

int validarIdColor(eColor lista[], int tam, int id){

	int existe = 0;

	if(lista !=NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(lista[i].id == id)
			{
				existe = 1;
				break;
			}
		}
	}
	return existe;
}
