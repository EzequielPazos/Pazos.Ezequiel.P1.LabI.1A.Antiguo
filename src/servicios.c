/*
 * servicios.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Pazos Ezequiel
 */

#include <stdio.h>
#include <stdlib.h>
#include "motos.h"
#include "tipos.h"
#include "colores.h"
#include "servicios.h"

int mostrarServicios(eServicio lista[], int tam){

	int todoOk = 0;

	if(lista !=NULL && tam>0)
	{
		system("cls");
		printf("=====        ***   LISTADO DE SERVICIOS   ***        =====\n");
		printf("   ID  | DESCRIPCION | PRECIO\n");
		printf("-------------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			printf(" %d     %10s     %d", lista[i].id, lista[i].descripcion, lista[i].precio);
		}
		todoOk = 1;
	}

	return todoOk;
}
