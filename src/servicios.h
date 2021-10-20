/*
 * servicios.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Pazos Ezequiel
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_

typedef struct{
	int id;
	char descripcion[25];
	int precio;
}eServicio;

#endif /* SERVICIOS_H_ */

int mostrarServicios(eServicio lista[], int tam);
