/*
 * motos.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Pazos Ezequiel
 */

#include <stdio.h>
#include <stdlib.h>
#include "motos.h"

int inicializarMotos(eMoto lista[], int tam)
{
	int todoOk = -1;

	if(lista !=NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			lista[i].isEmpty = 1;
		}

		todoOk = 1;
	}

	return todoOk;
}

int buscarLibre(eMoto lista[], int tam)
{

	int indice = -1;

	if(lista !=NULL && tam>0)
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

int altaMoto(eMoto lista[], int tam, int* pId)
{
	int todoOk = 0;
	int indice;
	eMoto auxMoto;

	if(lista !=NULL && tam > 0 && pId != NULL)
	{
		system("cls");
		printf("=====        *** ALTA MOTO ***        =====\n");

		indice = buscarLibre(lista, tam);
		if(indice == -1)
		{
			printf(" ==> NO HAY LUGAR EN EL SISTEMA!\n");
		}else
		{
			auxMoto.id = *pId;
			(*pId)++;

			printf(" --> Ingrese la marca: ");
			fflush(stdin);
			gets(auxMoto.marca);

			printf(" --> Ingrese el ID segun su tipo: "); //VALIDAR QUE EXISTA
			scanf("%d", &auxMoto.idTipo);

			printf(" --> Ingrese el ID segun su color: "); //VALIDAR QUE EXISTA
			scanf("%d", &auxMoto.idColor);

			printf(" --> Ingrese la cilindrada: "); //VALIDAR QUE EXISTA
			scanf("%d", &auxMoto.cilindrada);

			printf(" --> Ingrese el puntaje: "); //VALIDAR DE 1 A 10
			scanf("%d", &auxMoto.puntaje);

			auxMoto.isEmpty = 0;

			lista[indice] = auxMoto;

			todoOk = 1;
		}
	}

	return todoOk;
}

int mostrarMotos(eMoto lista[], int tam)
{
	int todoOk = 0;

	if(lista !=NULL && tam>0)
	{
		system("cls");
		printf("=====        ***   LISTADO DE MOTOS   ***        =====\n");
		printf("   ID  | MARCA  | TIPO  | COLOR  | CILINDRADA  | PUNTAJE\n");
		printf("--------------------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			if(lista[i].isEmpty == 0)
			{
				mostrarMoto(lista[i]);
			}
		}
		todoOk = 1;
	}

	return todoOk;
}

void mostrarMoto(eMoto unaMoto)
{
	printf(" %d %10s     %d    %d         %d          %d\n",
			unaMoto.id,
			unaMoto.marca,
			unaMoto.idTipo,
			unaMoto.idColor,
			unaMoto.cilindrada,
			unaMoto.puntaje);
}

int buscarMotoPorId(eMoto lista[], int tam, int id)
{
	int indice = -1;

	for(int i=0;i<tam;i++)
	{
		if(lista[i].id == id)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

int modificarMoto(eMoto lista[], int tam)
{
	int todoOk = 0;
	int id;
	int indice;
	int opcion;
	char seguir;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("=====        *** MODIFICAR MOTO ***        =====\n\n");
		mostrarMotos(lista, tam);
		printf(" --> INGRESE EL ID DE LA MOTO A MODIFICAR: ");
		scanf("%d", &id);

		indice = buscarMotoPorId(lista, tam, id);

		if(indice == -1)
		{
			printf(" --> NO EXISTE UNA MOTO CON ESA ID!\n\n");
		}else
		{
			mostrarMoto(lista[indice]);

			do{
				printf("QUE DESEA MODIFICAR?\n\n");
				printf("1 ---> COLOR\n");
				printf("2 ---> PUNTAJE\n");
				printf("3 ---> VOLVER ATRAS\n");
				scanf("%d", &opcion);

				switch(opcion)
				{
					case 1:

						//FALTA MOSTRAR COLORES

						printf(" --> Ingrese el ID segun su color: "); //VALIDAR QUE EXISTA
						scanf("%d", &lista[indice].idColor);
						printf("\n\nEl cambio de color ha sido realizado con exito!");
						system("pause");
						break;
					case 2:
						printf(" --> Ingrese el puntaje deseado: "); //VALIDAR QUE SEA ENTRE 1 Y 10
						scanf("%d", &lista[indice].puntaje);
						printf("\n\nEl cambio de puntaje ha sido realizado con exito!");
						system("pause");
						break;
					case 3:
						seguir = 'n';
						break;
					default:
						printf("\nLa opcion ingresada no existe!\n\n"); //validacion de las opciones disponibles
						system("pause");
						break;
				}
				todoOk = 1;
			}while(seguir == 's');
		}
	}
	return todoOk;
}

int bajaMoto(eMoto lista[], int tam)
{
	int todoOk = 0;
	int indice;
	int id;
	char confirmar;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("=====        *** BAJA DE MOTOS ***        =====\n\n");
		mostrarMotos(lista, tam);
		printf(" --> Ingrese el ID de la moto que desea dar de baja: ");
		scanf("%d", &id);

		indice = buscarMotoPorId(lista, tam, id);

		if(indice == -1)
		{
			printf(" --> No existe ninguna moto con esa ID!\n\n");
		}else
		{
			mostrarMoto(lista[indice]);
			printf(" --> Confirma el borrado? Ingrese s/n\n");
			fflush(stdin);
			scanf("%c", &confirmar);
			while(confirmar !='s' && confirmar !='n')
			{
				printf(" --> La respuesta ingresada no es valida. Ingrese s/n\n");
				fflush(stdin);
				scanf("%c", &confirmar);
			}

			if(confirmar =='s')
			{
				lista[indice].isEmpty = 1;
				todoOk = 1;
			}
		}
	}
	return todoOk;
}

int ordenarMotosPorTipoId(eMoto vec[], int tam){

	int todoOk = 0;
	eMoto aux;

	if(vec !=NULL && tam > 0){

		for(int i=0; i<tam-1; i++)
		{
			for(int j= i+1; j<tam; j++)
			{
				if(vec[i].idTipo < vec[j].idTipo) //ordenamiento por tipo decreciente
				{
					aux = vec[i];
					vec[i] = vec[j];
					vec[j] = aux;

					for(int i=0; i<tam-1; i++)
					{
						for(int j= i+1; j<tam; j++)
						{
							if(vec[i].id < vec[j].id) //ordenamiento por ID decreciente
							{
								aux = vec[i];
								vec[i] = vec[j];
								vec[j] = aux;
							}
						}
					}
				}
			}
		}

		todoOk = 1;
	}
	return todoOk;
}
