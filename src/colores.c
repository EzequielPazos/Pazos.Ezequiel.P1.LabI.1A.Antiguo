/*
 * colores.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Eze
 */

#include <stdio.h>
#include <stdlib.h>
#include "motos.h"
#include "tipos.h"
#include "colores.h"

int mostrarColores(eColor lista[], int tam){

	int todoOk = 0;

	if(lista !=NULL && tam>0)
	{
		system("cls");
		printf("=====        ***   LISTADO DE COLORES   ***        =====\n");
		printf("   ID  | NOMBRE COLOR\n");
		printf("-------------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			printf(" %d     %10s", lista[i].id, lista[i].nombreColor);
		}
		todoOk = 1;
	}

	return todoOk;
}
