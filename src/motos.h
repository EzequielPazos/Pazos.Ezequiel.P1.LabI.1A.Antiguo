/*
 * motos.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Eze
 */

#ifndef MOTOS_H_
#define MOTOS_H_

typedef struct{
	int id; //AUTOINCREMENTAL
	char marca[20];
	int idTipo; //VALIDAR
	int idColor; //VALIDAR
	int cilindrada; //PUEDEN SER 50,125,500,600,750
	int puntaje; //de 1 a 10
	int isEmpty;
}eMoto;

#endif /* MOTOS_H_ */

int inicializarMotos(eMoto lista[], int tam); //inicializa el campo isEmpty en 1
int buscarLibre(eMoto lista[], int tam); //retorna el indice de la primer estructura libre o -1
int altaMoto(eMoto lista[], int tam, int* pId); // 1 si ok 0 si error
int mostrarMotos(eMoto lista[], int tam);
void mostrarMoto(eMoto unaMoto);
int buscarMotoPorId(eMoto lista[], int tam, int id); //devuelve el indice a modificar o -1
int modificarMoto(eMoto lista[], int tam);
int bajaMoto(eMoto lista[], int tam);
int ordenarMotosPorTipoId(eMoto vec[], int tam);
