/*
 ============================================================================
 Titulo      : labo.c
 Alumno      : Pazos Ezequiel
 Version     : 1.0.0
 Descripcion : Primer Parcial Laboratorio - Parte 1
 Curso		 : 1°A
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "motos.h"
#include "tipos.h"
#include "colores.h"
#include "servicios.h"

#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAM_M 10

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int id; //AUTOINCREMENTAL
	int idMoto; //DEBE EXISTIR - VALIDAR
	int idServicio; //DEBE EXISTIR - VALIDAR
	eFecha fecha; //VALIDAR DIA, MES Y AÑO
}eTrabajo;

int menu(); //muestra el menu y devuelve la opcion deseada

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
	eMoto lista[TAM_M];


	if( !inicializarMotos(lista, TAM_M)){
		printf("Ocurrio un problema al inicializar personas");
	}

	do{

		switch(menu())
		{
			case 1:
				if(altaMoto(lista, TAM_M, &nextIdMoto)){
					printf("\n --> EL ALTA FUE REALIZADA CON EXITO! \n");
				}else
				{
					printf("\n --> HUBO UN PROBLEMA CON EL ALTA! \n");
				}
				break;
			case 2:
				if(modificarMoto(lista, TAM_M)){
					printf("\n --> LA MODIFICACION FUE REALIZADA CON EXITO! \n");
				}else
				{
					printf("\n --> HUBO UN PROBLEMA CON LA MODIFICACION! \n");
				}
				break;
			case 3:
				if(bajaMoto(lista, TAM_M)){
					printf("\n --> LA BAJA FUE REALIZADA CON EXITO! \n");
				}else
				{
					printf("\n --> HUBO UN PROBLEMA CON LA BAJA! \n");
				}
				break;
			case 4:
				if(ordenarMotosPorTipoId(lista, TAM_M)){
					printf("\n --> LA LISTA FUE ORDENADA CON EXITO! \n");
					mostrarMotos(lista, TAM_M);
				}else
				{
					printf("\n --> HUBO UN PROBLEMA AL ORDENAR LA LISTA! \n");
				}
				break;
			case 5:
				if(mostrarTipos(listaTipos, TAM_T)){
					printf("\n --> LA LISTA FUE MOSTRADA CON EXITO! \n");
				}else
				{
					printf("\n --> HUBO UN PROBLEMA AL MOSTRAR LA LISTA! \n");
				}
				break;
			case 6:
				if(mostrarColores(listaColores, TAM_C)){
					printf("\n --> LA LISTA FUE MOSTRADA CON EXITO! \n");
				}else
				{
					printf("\n --> HUBO UN PROBLEMA AL MOSTRAR LA LISTA! \n");
				}
				break;
			case 7:
				if(mostrarServicios(listaServicios, TAM_S)){
					printf("\n --> LA LISTA FUE MOSTRADA CON EXITO! \n");
				}else
				{
					printf("\n --> HUBO UN PROBLEMA AL MOSTRAR LA LISTA! \n");
				}
				break;
			case 8:
				printf("ALTA TRABAJO\n"); //SIN TERMINAR
				break;
			case 9:
				printf("LISTAR TRABAJOS\n"); //SIN TERMINAR
				break;
			case 10:
				seguir = 'n';
				break;
			default:
				printf(" ==> LA OPCION INGRESADA ES INVALIDA\n\n");
		}

	}while(seguir == 's');

	return EXIT_SUCCESS;
}

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
	printf("   10 --> SALIR\n");

	printf("\n   ==> INGRESE LA OPCION DESEADA: ");
	scanf("%d", &opcion);

	return opcion;
}
