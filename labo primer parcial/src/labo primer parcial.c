/*
 ============================================================================
 Titulo      : labo.c
 Alumno      : Pazos Ezequiel
 Version     : 1.1.0
 Descripcion : Primer Parcial Laboratorio - Parte 1
 Curso		 : 1°A
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "motos.h"
#include "tipos.h"
#include "colores.h"
#include "servicios.h"
#include "trabajos.h"
#include "validaciones.h"
#include "fecha.h"

#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAM_M 10
#define TAM_TRA 100

int menuInformes();
//int mostrarAutosUnColor(eMoto listaMotos[], int tam, eColor listaColores[], int tam_c, eTipo listaTipos, int tam_t);

int main(void) {

	setbuf(stdout, NULL);

	eTipo listaTipos[TAM_T] = {			//hardcodeo del array de la estructura tipos
		{1000, "Enduro"},
		{1001, "Chopera"},
		{1002, "Scooter"},
		{1003, "Vintage"}
	};

	eColor listaColores[TAM_C] = {			//hardcodeo del array de la estructura colores
		{10000, "Gris"},
		{10001, "Negro"},
		{10002, "Azul"},
		{10003, "Blanco"},
		{10004, "Rojo"}
	};

	eServicio listaServicios[TAM_S] = {			//hardcodeo del array de la estructura servicios
		{20000, "Limpieza", 450},
		{20001, "Ajuste", 300},
		{20002, "Balanceo", 150},
		{20003, "Cadena", 390}
	};

	char seguir = 's';
	int nextIdMoto = 1;
	int nextIdTrabajo = 30000;
	int flagPrimerAlta = 0;
	int flagPrimerAltaTrabajo = 0;
	eMoto lista[TAM_M];
	eTrabajo listaTrabajos[TAM_TRA];


	if( !inicializarMotos(lista, TAM_M)){
		printf("Ocurrio un problema al inicializar personas");
	}

	if( !inicializarTrabajos(listaTrabajos, TAM_TRA)){
		printf("Ocurrio un problema al inicializar trabajos");
	}

	do{

		switch(menu())
		{
			case 1:
				if(altaMoto(lista, TAM_M, &nextIdMoto, listaTipos, TAM_T, listaColores, TAM_C)){
					printf("\n --> EL ALTA FUE REALIZADA CON EXITO! \n\n");
					flagPrimerAlta = 1;
				}else
				{
					printf("\n --> HUBO UN PROBLEMA CON EL ALTA! \n\n");
				}
				break;
			case 2:
				if(flagPrimerAlta){
					if(modificarMoto(lista, TAM_M, listaColores, TAM_C, listaTipos, TAM_T)){
						printf("\n --> LA MODIFICACION FUE REALIZADA CON EXITO! \n\n");
					}else
					{
						printf("\n --> HUBO UN PROBLEMA CON LA MODIFICACION! \n\n");
					}
				}else{
					printf("\n --> TODAVIA NO SE HA DADO NINGUNA MOTO DE ALTA!  \n\n");
				}
				break;
			case 3:
				if(flagPrimerAlta){
					if(bajaMoto(lista, TAM_M, listaTipos, TAM_T, listaColores, TAM_C)){
						printf("\n --> LA BAJA FUE REALIZADA CON EXITO! \n\n");
					}else
					{
						printf("\n --> HUBO UN PROBLEMA CON LA BAJA! \n\n");
					}
				}else{
					printf("\n --> TODAVIA NO SE HA DADO NINGUNA MOTO DE ALTA!  \n\n");
				}
				break;
			case 4:
				if(flagPrimerAlta){
					if(ordenarMotosPorTipoId(lista, TAM_M)){
						printf("\n --> LA LISTA FUE ORDENADA CON EXITO! \n\n");
						mostrarMotos(lista, TAM_M, listaTipos, TAM_T, listaColores, TAM_C);
					}else
					{
						printf("\n --> HUBO UN PROBLEMA AL ORDENAR LA LISTA! \n\n");
					}
				}else{
					printf("\n --> TODAVIA NO SE HA DADO NINGUNA MOTO DE ALTA!  \n\n");
				}
				break;
			case 5:
				if(mostrarTipos(listaTipos, TAM_T)){
					printf("\n --> LA LISTA FUE MOSTRADA CON EXITO! \n\n");
				}else
				{
					printf("\n --> HUBO UN PROBLEMA AL MOSTRAR LA LISTA! \n\n");
				}
				break;
			case 6:
				if(mostrarColores(listaColores, TAM_C)){
					printf("\n --> LA LISTA FUE MOSTRADA CON EXITO! \n\n");
				}else
				{
					printf("\n --> HUBO UN PROBLEMA AL MOSTRAR LA LISTA! \n\n");
				}
				break;
			case 7:
				if(mostrarServicios(listaServicios, TAM_S)){
					printf("\n --> LA LISTA FUE MOSTRADA CON EXITO! \n\n");
				}else
				{
					printf("\n --> HUBO UN PROBLEMA AL MOSTRAR LA LISTA! \n\n");
				}
				break;
			case 8:
				if(altaTrabajo(listaTrabajos, TAM_TRA, &nextIdTrabajo)){
					printf("\n --> EL ALTA FUE REALIZADA CON EXITO! \n\n");
					flagPrimerAltaTrabajo = 1;
				}else
				{
					printf("\n --> HUBO UN PROBLEMA CON EL ALTA! \n\n");
				}
				break;
			case 9:
				if(flagPrimerAltaTrabajo){
					if(mostrarTrabajos(listaTrabajos, TAM_TRA)){
						printf("\n --> LA LISTA FUE MOSTRADA CON EXITO! \n");
					}else
					{
						printf("\n --> HUBO UN PROBLEMA AL MOSTRAR LA LISTA! \n");
					}
				}
				else{
						printf("\n --> TODAVIA NO SE HA DADO NINGUN TRABAJO DE ALTA!  \n");
				}
				break;
			case 10:
				switch(menuInformes()){
					case 1:
						//mostrarAutosUnColor(lista, TAM_M, listaColores, TAM_C, listaTipos, TAM_T);
						break;
					case 2:
						printf("AUTOS DE UNA MARCA");
						break;
					case 3:
						printf("AUTOS MAS VIEJOS");
						break;
					case 4:
						printf("AUTOS SEPARADOS POR MARCA");
						break;
					case 5:
						printf("CONTADOR AUTOS DE UN COLOR Y MARCA");
						break;
					case 6:
						printf("MARCA MAS ELEGIDA");
						break;
					case 7:
						printf("VOLVIENDO ATRAS\n\n");
						break;
					default:
						printf(" ==> LA OPCION INGRESADA ES INVALIDA\n\n");
				}
				break;
			case 11:
				seguir = 'n';
				break;
			default:
				printf(" ==> LA OPCION INGRESADA ES INVALIDA\n\n");
		}

	}while(seguir == 's');

	return EXIT_SUCCESS;
}

int menuInformes(){

	int opcion;

	system("cls");

	printf("=====        *** INFORMES ***        =====\n");
	printf("   1 --> AUTOS DE UN COLOR ESPECIFICO\n");
	printf("   2 --> AUTOS DE UNA MARCA ESPECIFICA\n");
	printf("   3 --> AUTOS MAS VIEJOS\n");
	printf("   4 --> LISTADO DE AUTOS POR MARCA\n");
	printf("   5 --> CONTADOR DE AUTOS POR COLOR Y MARCA\n");
	printf("   6 --> MARCAS MAS ELEGIDAS\n");
	printf("   7 --> ATRAS\n");

	printf("\n   ==> INGRESE LA OPCION DESEADA: ");
	scanf("%d", &opcion);

	return opcion;
}

/*int mostrarAutosUnColor(eMoto listaMotos[], int tam, eColor listaColores[], tam_c, eTipo listaTipos, tam_t){

	int todoOk = 0;
	int colorSeleccionado;

	mostrarColores(listaColores, tam_c);
	printf("Ingrese el ID del color deseado: \n\n");
	scanf("%d", &colorSeleccionado);

	while(!validarIdColor(listaColores, tam_c, colorSeleccionado)){		//validacion color existente
		mostrarColores(listaColores, tam_c);
		printf(" --> El ID ingresado es invalido. Ingrese nuevamente: ");
		scanf("%d", &colorSeleccionado);
	}

	for(int i=0; i<tam; i++)
	{
		if(listaMotos[i].idColor == colorSeleccionado){
			mostrarMoto(listaMotos[i], listaTipos, tam_t, listaColores, tam_c);
		}
	}

	return todoOk;
}

*/
