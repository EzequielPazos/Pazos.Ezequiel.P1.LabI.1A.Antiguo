/*
 * motos.c
 *
 *  Created on: 20 oct. 2021
 *      Author: Pazos Ezequiel
 */

#include <stdio.h>
#include <stdlib.h>
#include "motos.h"
#include "tipos.h"
#include "colores.h"
#include "validaciones.h"

int menu(){

	int opcion;

	system("cls");

	printf("=====        *** ABM MOTOS ***        =====\n");
	printf("   1 --> ALTA MOTO\n");
	printf("   2 --> MODIFICAR MOTO\n"); //se ingresara el id, permitiendo en un submenu modificar: color / puntaje
	printf("   3 --> BAJA MOTO\n"); //se ingresara el id de la moto y se realizara una baja logica
	printf("   4 --> LISTAR MOTOS\n"); //listado unico de todas las motos ordenadas por tipo e id
	printf("   5 --> LISTAR TIPOS\n");
	printf("   6 --> LISTAR COLORES\n");
	printf("   7 --> LISTAR SERVICIOS\n");
	printf("   8 --> ALTA TRABAJO\n"); //se dara de alta cada ocurrencia de trabajo pidiendole al usuario que elija una moto y un servicio
	printf("   9 --> LISTAR TRABAJOS\n");
	printf("   10 --> INFORMES\n");
	printf("   11 --> SALIR\n");

	printf("\n   ==> INGRESE LA OPCION DESEADA: ");
	scanf("%d", &opcion);

	return opcion;
}

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

int altaMoto(eMoto lista[], int tam, int* pId, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c)
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

			mostrarTipos(listaTipos, tam_t);	//muestro tipos
			printf(" --> Ingrese el ID segun su tipo: ");  //ingreso tipos
			scanf("%d", &auxMoto.idTipo);

			while(!validarIdTipo(listaTipos, tam_t, auxMoto.idTipo)){		//validacion tipo existente
				mostrarTipos(listaTipos, tam_t);
				printf(" --> El ID ingresado es invalido. Ingrese nuevamente: ");
				scanf("%d", &auxMoto.idTipo);
			}

			mostrarColores(listaColores, tam_c); //muestro colores
			printf(" --> Ingrese el ID segun su color: "); //ingreso color
			scanf("%d", &auxMoto.idColor);

			while(!validarIdColor(listaColores, tam_c, auxMoto.idColor)){		//validacion color existente
				mostrarColores(listaColores, tam_c);
				printf(" --> El ID ingresado es invalido. Ingrese nuevamente: ");
				scanf("%d", &auxMoto.idColor);
			}

			printf(" --> Ingrese la cilindrada (50, 125, 500, 600, 750):  ");
			scanf("%d", &auxMoto.cilindrada);

			while(auxMoto.cilindrada !=50 && auxMoto.cilindrada !=125 && auxMoto.cilindrada !=500 && auxMoto.cilindrada !=600 && auxMoto.cilindrada !=750){ //validacion cilindrada correcta
				printf(" --> La cilindrada ingresada es invalida. Ingrese nuevamente (50, 125, 500, 600, 750): ");
				scanf("%d", &auxMoto.cilindrada);
			}

			printf(" --> Ingrese el puntaje (ENTRE 1 Y 10): ");
			scanf("%d", &auxMoto.puntaje);

			while(auxMoto.puntaje !=1 && auxMoto.puntaje !=2 && auxMoto.puntaje !=3 && auxMoto.puntaje !=4 && auxMoto.puntaje !=5 && auxMoto.puntaje !=6 && auxMoto.puntaje !=7 && auxMoto.puntaje !=8 && auxMoto.puntaje !=9 && auxMoto.puntaje !=10){
				printf(" --> El puntaje ingresado es invalido. Ingrese nuevamente (ENTRE 1 Y 10): "); //validacion puntaje correcto
				scanf("%d", &auxMoto.puntaje);
			}

			auxMoto.isEmpty = 0;

			lista[indice] = auxMoto;

			todoOk = 1;
		}
	}

	return todoOk;
}

int mostrarMotos(eMoto lista[], int tam, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c)
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
				mostrarMoto(lista[i], listaTipos, tam_t, listaColores, tam_c);
			}
		}
		todoOk = 1;
	}

	return todoOk;
}

void mostrarMoto(eMoto unaMoto, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c)
{
	char descripcionTipo[20];
	char nombreColor[20];

	cargarDescripcionTipo(listaTipos, tam_t, unaMoto.idTipo, descripcionTipo);
	cargarNombreColor(listaColores, tam_c, unaMoto.idColor, nombreColor);

	printf(" %d %10s     %s    %s         %d          %d\n",
			unaMoto.id,
			unaMoto.marca,
			descripcionTipo,
			nombreColor,
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

int modificarMoto(eMoto lista[], int tam, eColor listaColores[], int tam_c, eTipo listaTipos[], int tam_t)
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
		mostrarMotos(lista, tam, listaTipos, tam_t, listaColores, tam_c);
		printf(" --> INGRESE EL ID DE LA MOTO A MODIFICAR: ");
		scanf("%d", &id);

		indice = buscarMotoPorId(lista, tam, id);

		if(indice == -1)
		{
			printf(" --> NO EXISTE UNA MOTO CON ESA ID!\n\n");
		}else
		{
			mostrarMoto(lista[indice], listaTipos, tam_t, listaColores, tam_c);

			do{
				printf("QUE DESEA MODIFICAR?\n\n");
				printf("1 ---> COLOR\n");
				printf("2 ---> PUNTAJE\n");
				printf("3 ---> VOLVER ATRAS\n");
				scanf("%d", &opcion);

				switch(opcion)
				{
					case 1:

						mostrarColores(listaColores, tam_c);

						printf(" --> Ingrese el ID segun su color: ");
						scanf("%d", &lista[indice].idColor);

						while(!validarIdColor(listaColores, tam_c, lista[indice].idColor)){		//validacion color existente
							mostrarColores(listaColores, tam_c);
							printf(" --> El ID ingresado es invalido. Ingrese nuevamente: ");
							scanf("%d", &lista[indice].idColor);
						}

						printf("\n\nEl cambio de color ha sido realizado con exito!");
						system("pause");
						break;
					case 2:
						printf(" --> Ingrese el puntaje deseado (ENTRE 1 Y 10): ");
						scanf("%d", &lista[indice].puntaje);
						while(lista[indice].puntaje !=1 && lista[indice].puntaje !=2 && lista[indice].puntaje !=3 && lista[indice].puntaje !=4 && lista[indice].puntaje !=5 && lista[indice].puntaje !=6 && lista[indice].puntaje !=7 && lista[indice].puntaje !=8 && lista[indice].puntaje !=9 && lista[indice].puntaje !=10){
							printf(" --> El puntaje ingresado es invalida. Ingrese nuevamente (ENTRE 1 Y 10): ");
							scanf("%d", &lista[indice].puntaje);
						}
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

int bajaMoto(eMoto lista[], int tam, eTipo listaTipos[], int tam_t, eColor listaColores[], int tam_c)
{
	int todoOk = 0;
	int indice;
	int id;
	char confirmar;

	if(lista != NULL && tam > 0)
	{
		system("cls");
		printf("=====        *** BAJA DE MOTOS ***        =====\n\n");
		mostrarMotos(lista, tam, listaTipos, tam_t, listaColores, tam_c);
		printf(" --> Ingrese el ID de la moto que desea dar de baja: ");
		scanf("%d", &id);

		indice = buscarMotoPorId(lista, tam, id);

		if(indice == -1)
		{
			printf(" --> No existe ninguna moto con esa ID!\n\n");
		}else
		{
			mostrarMoto(lista[indice], listaTipos, tam_t, listaColores, tam_c);
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
				if(vec[i].idTipo < vec[j].idTipo || (vec[i].idTipo == vec[j].idTipo && vec[i].id < vec[j].id)) //ordenamiento por tipo e id decreciente
				{
					aux = vec[i];
					vec[i] = vec[j];
					vec[j] = aux;
				}
			}
		}

		todoOk = 1;
	}
	return todoOk;
}
