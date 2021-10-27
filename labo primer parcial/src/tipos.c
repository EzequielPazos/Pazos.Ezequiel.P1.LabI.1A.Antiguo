/*
 * tipos.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Pazos Ezequiel
 */

#include <stdio.h>
#include <stdlib.h>
#include "motos.h"
#include "tipos.h"

int mostrarTipos(eTipo lista[], int tam){

	int todoOk = 0;

	if(lista !=NULL && tam>0)
	{
		system("cls");
		printf("=====        ***   LISTADO DE TIPOS   ***        =====\n");
		printf("   ID  | DESCRIPCION\n");
		printf("-------------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			printf(" %d     %10s\n", lista[i].id, lista[i].descripcion);
		}
		todoOk = 1;
	}

	return todoOk;
}

int cargarDescripcionTipo(eTipo lista[], int tam, int idTipo, char descripcion[]){

	int todoOk = 0;

	if(lista !=NULL && tam>0 && descripcion !=NULL){
		for(int i=0; i<tam;i++)
		{
			if(lista[i].id == idTipo){
				strcpy(descripcion, lista[i].descripcion);
				break;
			}
		}

		todoOk = 1;
	}
	return todoOk;
}
