/*
 * trabajos.c
 *
 *  Created on: 27 oct. 2021
 *      Author: Pazos Ezequiel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajos.h"

int inicializarTrabajos(eTrabajo lista[], int tam)
{
	int todoOk = -1;

	if(lista != NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			lista[i].isEmpty = 1;
		}

		todoOk = 1;
	}

	return todoOk;
}

int buscarLibreTrabajo(eTrabajo lista[], int tam)
{

	int indice = -1;

	if(lista != NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			if(lista[i].isEmpty == 1){
				indice = i;
				break;
			}
		}
	}

	return indice;
}

int altaTrabajo(eTrabajo lista[], int tam, int* pId)
{
	int todoOk = 0;
	int indice;
	eTrabajo auxTrabajo;

	if(lista != NULL && tam > 0 && pId != NULL)
	{
		system("cls");
		printf("=====        *** ALTA TRABAJO ***        =====\n");

		indice = buscarLibreTrabajo(lista, tam);
		if(indice == -1)
		{
			printf(" ==> NO HAY LUGAR EN EL SISTEMA!\n");
		}else
		{
			auxTrabajo.id = *pId;
			(*pId)++;

			printf(" --> Ingrese el ID de su moto: "); //VALIDAR QUE EXISTA
			fflush(stdin);
			scanf("%d", &auxTrabajo.idMoto);

			printf(" --> Ingrese el ID del servicio deseado: "); //VALIDAR QUE EXISTA
			scanf("%d", &auxTrabajo.idServicio);

			printf(" --> Ingrese la fecha: "); //VALIDAR QUE EXISTA
			scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

			auxTrabajo.isEmpty = 0;

			lista[indice] = auxTrabajo;

			todoOk = 1;
		}
	}

	return todoOk;
}

int mostrarTrabajos(eTrabajo lista[], int tam)
{
	int todoOk = 0;

	if(lista !=NULL && tam>0)
	{
		system("cls");
		printf("=====        ***   LISTADO DE MOTOS   ***        =====\n");
		printf("   ID  | ID MOTO  | ID SERVICIO  | FECHA  \n");
		printf("-------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			if(lista[i].isEmpty == 0)
			{
				mostrarTrabajo(lista[i]);
			}
		}
		todoOk = 1;
	}

	return todoOk;
}

void mostrarTrabajo(eTrabajo unTrabajo)
{
	printf(" %d %d  %d    %d/%d/%d\n",
			unTrabajo.id,
			unTrabajo.idMoto,
			unTrabajo.idServicio,
			unTrabajo.fecha.dia,
			unTrabajo.fecha.mes,
			unTrabajo.fecha.anio);
}
