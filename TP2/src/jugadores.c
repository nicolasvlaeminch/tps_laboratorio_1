/*
 * libros.c
 *
 *  Created on: 1 oct 2022
 *      Author: Nicolas
 */
#include "jugadores.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "utn.h"
#define CANTIDAD 5
#define LLENO 1
#define VACIO 0

/**
 * \fn int AltaJugador(eJugador[], int, int)
 * \brief
 *
 * \param libros
 * \param tam
 * \param legajoAutoIncremental
 * \return
 *
 * Esta funcion da de alta un libro y lo guarda en una estructura, retorna 1 si se
 * da correctamente y 0 si falla. Primero llama la funcion BuscarLibre, para verificar
 * si hay un espacio libre en el array, si lo hay guardara el numero retornado por
 * BuscarLibre en la variable indice, luego enviara los mensajes uno por uno de las
 * funciones llamadas PedirEntero y PedirCadena guardando los datos ingresados en la
 * estructura con el indice guardado anteriormente si cumple con las verificaciones.
 */
int AltaJugador(eJugador jugadores[], int tam, int codigoAutoIncremental) {
	int retorno;
	int indice;
	int opcion;
	int respuestaMenu;

	retorno = 0; //Si la lista está llena

	indice = BuscarLibre(jugadores,tam);

	if(indice > -1)
	{
		jugadores[indice].id = codigoAutoIncremental;
	    PedirCadena(jugadores[indice].nombre, 51, "Ingrese el nombre del jugador: ");
	    respuestaMenu = utn_getNumero(&opcion,
	    				"\n"
	    				"1. Arquero\n"
	    				"2. Defensor\n"
	    				"3. Mediocampista\n"
	    				"4. Delantero\n"
	    				"\n\nIngrese una opcion: ", "\nERROR: numero invalido\n", 1, 4, 3);
	    		if(!respuestaMenu) {
	    			switch(opcion) {
	    			case 1:
	    				strcpy(jugadores[indice].posicion, "Arquero");
	    				break;
	    			case 2:
	    				strcpy(jugadores[indice].posicion, "Defensor");
	    				break;
	    			case 3:
	    				strcpy(jugadores[indice].posicion, "Mediocampista");
	    				break;
	    			case 4:
	    				strcpy(jugadores[indice].posicion, "Delantero");
	    				break;
	    			}
	    		}
	    jugadores[indice].numeroCamiseta = PedirEntero("Ingrese el numero de camiseta: ", "ERROR: Ingrese un numero entre 1 a 99: ", 1, 99);
	    jugadores[indice].salario = PedirEntero("Ingrese el salario del jugador: ", "ERROR: Ingrese un numero mayor a 0 y menor a 2 millones: ", 1, 20000000);
	    respuestaMenu = utn_getNumero(&opcion,
	    				"\n"
	    				"0. CONMEBOL\n"
	    				"1. UEFA\n"
	    				"2. AFC\n"
	    				"3. CAF\n"
	    				"4. CONCACAF\n"
	    				"5. OFC\n"
	    				"\n\nIngrese una opcion: ", "\nERROR: numero invalido\n", 0, 5, 3);
	    		if(!respuestaMenu) {
	    			switch(opcion) {
	    			case 0:
	    				jugadores[indice].idConfederacion.id = 0;
	    				jugadores[indice].idConfederacion.anioCreacion = 1916;
	    				strcpy(jugadores[indice].idConfederacion.nombre, "CONMEBOL");
	    				strcpy(jugadores[indice].idConfederacion.region, "SUDAMERICA");
	    				break;
	    			case 1:
	    				jugadores[indice].idConfederacion.id = 1;
	    				jugadores[indice].idConfederacion.anioCreacion = 1954;
	    				strcpy(jugadores[indice].idConfederacion.nombre, "UEFA");
	    				strcpy(jugadores[indice].idConfederacion.region, "EUROPA");
	    				break;
	    			case 2:
	    				jugadores[indice].idConfederacion.id = 2;
	    				jugadores[indice].idConfederacion.anioCreacion = 1954;
	    				strcpy(jugadores[indice].idConfederacion.nombre, "AFC");
	    				strcpy(jugadores[indice].idConfederacion.region, "ASIA");
	    				break;
	    			case 3:
	    				jugadores[indice].idConfederacion.id = 3;
	    				jugadores[indice].idConfederacion.anioCreacion = 1957;
	    				strcpy(jugadores[indice].idConfederacion.nombre, "CAF");
	    				strcpy(jugadores[indice].idConfederacion.region, "AFRICA");
	    				break;
	    			case 4:
	    				jugadores[indice].idConfederacion.id = 4;
	    				jugadores[indice].idConfederacion.anioCreacion = 1961;
	    				strcpy(jugadores[indice].idConfederacion.nombre, "CONCACAF");
	    				strcpy(jugadores[indice].idConfederacion.region, "NORTE Y CENTRO AMERICA");
	    				break;
	    			case 5:
	    				jugadores[indice].idConfederacion.id = 5;
	    				jugadores[indice].idConfederacion.anioCreacion = 1966;
	    				strcpy(jugadores[indice].idConfederacion.nombre, "OFC");
	    				strcpy(jugadores[indice].idConfederacion.region, "OCEANIA");
	    				break;
	    			}
	    		}
	    jugadores[indice].aniosContrato = PedirEntero("Ingrese los años de contrato: ", "ERROR: Ingrese de 1 a 10 años de contrato: ", 1, 10);


	    jugadores[indice].isEmpty = LLENO;
	    retorno = 1; //TODO SALIO BIEN
	}
	return retorno;
}

/**
 * \fn int BuscarLibre(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 * \return
 *
 * Esta funcion reccore un for busca un espacio libre en un array.
 * Se le pasa como parametro una estructura y el tamaño.
 * retornara -1 si no hay espacio o el numero del indice encontrado.
 */
int BuscarLibre(eJugador jugadores[],int tam) {
	int indice;
	indice = -1;

	for(int i=0; i<tam; i++)
    {
	   if(jugadores[i].isEmpty == VACIO)
	   {
		   indice = i;
		   break;
	   }
    }
	return indice;
}

/**
 * \fn int BuscarLibro(eLibro[], int, int)
 * \brief
 *
 * \param libros
 * \param tam
 * \param codigoABuscar
 * \return
 *
 * Esta funcion busca un libro por su codigo.
 *
 * Recorre la sentencia for verificiando si el codigo pasado
 * por parametro existe, si existe retornara el indice de lo
 * contrario retornara -1.
 */
int BuscarJugador(eJugador jugadores[],int tam,int codigoABuscar) {
	int indice;

	indice = -1;

	for(int i=0; i<tam; i++)
    {
	   if(jugadores[i].isEmpty == LLENO && jugadores[i].id == codigoABuscar)
	   {
		   indice = i;
		   break;
	   }
    }

	return indice;
}


/**
 * \fn int ModificarLibro(eLibro[], int, int)
 * \brief
 *
 * \param libros
 * \param tam
 * \param opcion
 * \return
 *
 * Esta funcion permite modificar un lugar en concreto de un libro.
 * Primero la funcion pide que ingrese el codigo del libro mediante
 * la funcion PedirEntero, busca el libro mediante la funcion
 * BuscarLibro, luego dependiendo del dato pasado por la variable
 * opcion ingresara al switch eligiendo el tipo de dato a cambiar,
 * una vez terminado el cambio pedira verificar si estas seguro en
 * realizar los cambios ingresando 1 si la respuesta es si, y 0
 * si la respuesta es no.
 * Retorna -1 no encuentra el libro y 1 si lo encuentra.
 *
 */
int ModificarJugador(eJugador jugadores[], int tam, int opcion) {
	int codigoAModificar;
	char nombreModificado[51];
	int indiceAModificar;
	int confirmacion;
	int retorno;
	int numeroCamiseta;
	int respuestaMenu;
	int salario;
	int aniosContrato;
	retorno = -1;//Si no encontro el libro

	codigoAModificar = PedirEntero("\nIngrese el codigo del jugador a modificar: ", "Error: Ingrese el codigo del jugador a modificar: ", 0, 3000);
	indiceAModificar = BuscarJugador(jugadores, tam, codigoAModificar);

	if(indiceAModificar > -1)
	{
		switch (opcion) {
			case 1:
				PedirCadena(nombreModificado,51,"Ingrese el nuevo nombre : ");
				retorno = 0;//Si cancelo la operación
				confirmacion = PedirEntero("Nombre listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ",
						"ERROR: Nombre listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ", 0, 1);
				if(confirmacion == 1)
				{
					strcpy(jugadores[indiceAModificar].nombre, nombreModificado);
					retorno = 1;//Salió todo bien
				}
				break;
			case 2:
			    respuestaMenu = utn_getNumero(&opcion,
			    				"\n"
			    				"1. Arquero\n"
			    				"2. Defensor\n"
			    				"3. Mediocampista\n"
			    				"4. Delantero\n"
			    				"\n\nIngrese una opcion: ", "\nERROR: numero invalido\n", 1, 4, 3);
				retorno = 0;//Si cancelo la operación
				confirmacion = PedirEntero("Nueva confederacion lista para ser cargada ¿Desea guardar los cambios? 1 si 0 no: ",
						"ERROR: Nueva confederacion lista para ser cargada ¿Desea guardar los cambios? 1 si 0 no: ", 0, 1);
				if(confirmacion == 1) {
					retorno = 1;//Salió todo bien
				    		if(!respuestaMenu) {
				    			switch(opcion) {
				    			case 1:
				    				strcpy(jugadores[indiceAModificar].posicion, "Arquero");
				    				break;
				    			case 2:
				    				strcpy(jugadores[indiceAModificar].posicion, "Defensor");
				    				break;
				    			case 3:
				    				strcpy(jugadores[indiceAModificar].posicion, "Mediocampista");
				    				break;
				    			case 4:
				    				strcpy(jugadores[indiceAModificar].posicion, "Delantero");
				    				break;
				    			}
				    		}
				}
			    break;
			case 3:
				numeroCamiseta = PedirEntero("Ingrese el nuevo n° camiseta: ", "ERROR: Ingrese un n° camiseta valido del 1 al 99: ", 1, 99);
				retorno = 0;//Si cancelo la operación
				confirmacion = PedirEntero("Nuevo n° camiseta listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ",
						"ERROR: Nuevo n° camiseta listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ", 0, 1);
				if(confirmacion == 1)
				{
				    jugadores[indiceAModificar].numeroCamiseta = numeroCamiseta;
					retorno = 1;//Salió todo bien
				}
				break;
			case 4:
				salario = PedirEntero("Ingrese el nuevo sueldo: ", "ERROR: Ingrese un sueldo valido entre 1 y 2millones: ", 1, 2000000);
				retorno = 0;//Si cancelo la operación
				confirmacion = PedirEntero("Nuevo sueldo listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ",
						"ERROR: Nuevo sueldo listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ", 0, 1);
				if(confirmacion == 1)
				{
				    jugadores[indiceAModificar].salario = salario;
					retorno = 1;//Salió todo bien
				}
				break;
			case 5:
			    respuestaMenu = utn_getNumero(&opcion,
			    				"\n"
			    				"0. CONMEBOL\n"
			    				"1. UEFA\n"
			    				"2. AFC\n"
			    				"3. CAF\n"
			    				"4. CONCACAF\n"
			    				"5. OFC\n"
			    				"\n\nIngrese una opcion: ", "\nERROR: numero invalido\n", 0, 5, 3);
				retorno = 0;//Si cancelo la operación
				confirmacion = PedirEntero("Nueva confederacion lista para ser cargada ¿Desea guardar los cambios? 1 si 0 no: ",
						"ERROR: Nueva confederacion lista para ser cargada ¿Desea guardar los cambios? 1 si 0 no: ", 0, 1);
				if(confirmacion == 1) {
					retorno = 1;//Salió todo bien
		    		if(!respuestaMenu) {
		    			switch(opcion) {
		    			case 0:
		    				jugadores[indiceAModificar].idConfederacion.id = 0;
		    				jugadores[indiceAModificar].idConfederacion.anioCreacion = 1916;
		    				strcpy(jugadores[indiceAModificar].idConfederacion.nombre, "CONMEBOL");
		    				strcpy(jugadores[indiceAModificar].idConfederacion.region, "SUDAMERICA");
		    				break;
		    			case 1:
		    				jugadores[indiceAModificar].idConfederacion.id = 1;
		    				jugadores[indiceAModificar].idConfederacion.anioCreacion = 1954;
		    				strcpy(jugadores[indiceAModificar].idConfederacion.nombre, "UEFA");
		    				strcpy(jugadores[indiceAModificar].idConfederacion.region, "EUROPA");
		    				break;
		    			case 2:
		    				jugadores[indiceAModificar].idConfederacion.id = 2;
		    				jugadores[indiceAModificar].idConfederacion.anioCreacion = 1954;
		    				strcpy(jugadores[indiceAModificar].idConfederacion.nombre, "AFC");
		    				strcpy(jugadores[indiceAModificar].idConfederacion.region, "ASIA");
		    				break;
		    			case 3:
		    				jugadores[indiceAModificar].idConfederacion.id = 3;
		    				jugadores[indiceAModificar].idConfederacion.anioCreacion = 1957;
		    				strcpy(jugadores[indiceAModificar].idConfederacion.nombre, "CAF");
		    				strcpy(jugadores[indiceAModificar].idConfederacion.region, "AFRICA");
		    				break;
		    			case 4:
		    				jugadores[indiceAModificar].idConfederacion.id = 4;
		    				jugadores[indiceAModificar].idConfederacion.anioCreacion = 1961;
		    				strcpy(jugadores[indiceAModificar].idConfederacion.nombre, "CONCACAF");
		    				strcpy(jugadores[indiceAModificar].idConfederacion.region, "NORTE Y CENTRO AMERICA");
		    				break;
		    			case 5:
		    				jugadores[indiceAModificar].idConfederacion.id = 5;
		    				jugadores[indiceAModificar].idConfederacion.anioCreacion = 1966;
		    				strcpy(jugadores[indiceAModificar].idConfederacion.nombre, "OFC");
		    				strcpy(jugadores[indiceAModificar].idConfederacion.region, "OCEANIA");
		    				break;
		    			}
		    		}
				}
				break;
			case 6:
				aniosContrato = PedirEntero("Ingrese los nuevos años de contrato: ", "ERROR: Ingrese los nuevos años de contrato entre 1 y 10: ", 1, 10);
				retorno = 0;//Si cancelo la operación
				confirmacion = PedirEntero("Nuevo contrato listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ",
						"ERROR: Nuevo contrato listo para ser cargado ¿Desea guardar los cambios? 1 si 0 no: ", 0, 1);
				if(confirmacion == 1)
				{
				    jugadores[indiceAModificar].aniosContrato = aniosContrato;
					retorno = 1;//Salió todo bien
				}
				break;
		}
	}
	return retorno;
}

/**
 * \fn int BajaLibro(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 * \return
 *
 * Esta funcion da de baja un libro.
 * Primero pide que ingreses el codigo del libro que deseas borrar mediante
 * la funcion PedirEntero, luego busca el libro por la funcion BuscarLibro
 * si lo encuentra deja un espacio vacio y retorna 1 de lo contrario retorna 0.
 *
 *
 */
int Baja(eJugador jugadores[],int tam) {
	int idABorrar;
	int retorno;
	int indiceDelLibro;

	idABorrar = PedirEntero("\nIngrese el id del jugador a dar de baja: ", "ERROR: Ingrese un numero valido: ", 0, 3000);
	indiceDelLibro = BuscarJugador(jugadores,tam,idABorrar);

	retorno = 0;//Si no encontro al libro a borrar

	if(indiceDelLibro > -1)
	{
		jugadores[indiceDelLibro].isEmpty=VACIO;
		retorno = 1;//Encontro al libro y lo borro
	}
    return retorno;
}

/**
 * \fn int VerificarLleno(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 * \return
 *
 * Esta funcion sirve para saber si hay un espacio libre.
 * La funcion recorre el for verificando si el estado del
 * libro esta lleno si lo esta retornara 1, de lo contrario
 * retornara 0.
 */
int VerificarLleno(eJugador jugadores[],int tam) {
	int retorno;
	retorno = 0;

	for(int i=0; i<tam; i++)
    {
	   if(jugadores[i].isEmpty == LLENO)
	   {
		   retorno = 1;
		   break;
	   }
    }
	return retorno;
}

/**
 * \fn void MostrarLibros(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 *
 * Esta funcion imprime todos los libros con sus datos
 * siempre y cuando existan, esto lo verifica con la funcion
 * VerificarLleno, la funcion no retornada nada.
 */
void MostrarJugadores(eJugador jugadores[], int tam) {
	if(VerificarLleno(jugadores, tam) == 1) {

		   printf(" ________________________________________________________________________________________________________________________\n"
		   	   		   "|%-5s|%-28s|%-15s|%-15s|%-13s|%-20s|%-20s|\n"
		   	   		   "|=====|============================|===============|==============|=============|====================|===================|\n",
		   	   		     " ID", " NOMBRE", " POSICION", " N° CAMISETA", " SUELDO" , " CONFEDERACION", " AÑOS DE CONTRATO");


		   for(int i=0; i<tam; i++) {
			   if(jugadores[i].isEmpty == LLENO) {
				   printf("|  %d  | %-26s | %-13s |     %-8d | %-10.2f  | %-18s |     %-14d|\n",
						   jugadores[i].id,
						   jugadores[i].nombre,
						   jugadores[i].posicion,
						   jugadores[i].numeroCamiseta,
						   jugadores[i].salario,
						   jugadores[i].idConfederacion.nombre,
						   jugadores[i].aniosContrato);
				   printf("|_____|____________________________|_______________|______________|_____________|____________________|___________________|\n");
			   }
		   }
	   }
}

/**
 * \fn void OrdenarImporteYTitulo(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 *
 * Esta funcion ordena los libros primero por Importe de manera
 * descendente y luego por Titulo de manera ascendente.
 */
void OrdenarImporteYTitulo(eJugador jugadores[], int tam) {
	eJugador aux;

	for (int i = 0; i < tam - 1; ++i) {
		for (int j = 0 + 1; j > tam; ++j) {
			if(jugadores[i].id > jugadores[j].id) {
				aux = jugadores[i];
				jugadores[i] = jugadores[j];
				jugadores[j] = aux;
			}
		}
	}
}

void OrdenarDosCadenas(eJugador jugadores[], int tam) {
	eJugador aux;

	for (int i = 0; i < tam - 1; ++i) {
		for (int j = 0 + 1; j < tam; ++j) {
			if(strcmp(jugadores[i].idConfederacion.nombre, jugadores[j].idConfederacion.nombre) > 0) {
				aux = jugadores[i];
				jugadores[i] = jugadores[j];
				jugadores[j] = aux;
			}
			else {
				if(jugadores[i].idConfederacion.nombre == jugadores[j].idConfederacion.nombre) {
					if (strcmp(jugadores[i].nombre, jugadores[j].nombre) > 0) {
						aux = jugadores[i];
						jugadores[i] = jugadores[j];
						jugadores[j] = aux;
					}
				}
			}
		}
	}
	MostrarJugadores(jugadores, tam);
}

void MostrarConfederacionJugador(eJugador jugadores[], int tam, char confederacion[]) {
	if(VerificarLleno(jugadores, tam) == 1) {

		   printf(" ____________________________\n"
		   	   		   "|%-28s|\n"
		   	   		   "|============================|\n",
					   confederacion);


		   for(int i=0; i<tam; i++) {
			   if(jugadores[i].isEmpty == LLENO) {
				   if (strcmp(jugadores[i].idConfederacion.nombre, confederacion) == 0){
					   printf("| %-26s |\n",
							   jugadores[i].nombre);
					   printf("|____________________________|\n");
				   }
			   }
		   }
	   }
}

void ListarConfederacionJugador(eJugador jugadores[], int tam) {
	MostrarConfederacionJugador(jugadores, CANTIDAD, "CONMEBOL");
	MostrarConfederacionJugador(jugadores, CANTIDAD, "UEFA");
	MostrarConfederacionJugador(jugadores, CANTIDAD, "AFC");
	MostrarConfederacionJugador(jugadores, CANTIDAD, "CAF");
	MostrarConfederacionJugador(jugadores, CANTIDAD, "CONCACAF");
	MostrarConfederacionJugador(jugadores, CANTIDAD, "OFC");
}

int TotalSalarios(eJugador jugadores[], int tam) {
	int salarioTotal = 0;

	for (int i = 0; i < tam; ++i) {
		salarioTotal = salarioTotal + jugadores[i].salario;
	}

	return salarioTotal;
}

/**
 * \fn float Promedio(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 * \return
 *
 * Esta funcion recorre la sentencia for si el importe es mayor a 0
 * sumara 1 al contador, luego sacara el promedio pasando a float
 * el retorno de la funcion Sumatoria y dividiendo por la variable
 * cantidadLibros para luego retornar el promedio.
 */
float Promedio(eJugador jugadores[], int tam) {
	float promedio;
	int cantidadJugadores = 0;

	for (int i = 0; i < tam; ++i) {
		if (jugadores[i].isEmpty > 0) {
			cantidadJugadores++;
		}
	}

	promedio = (float)TotalSalarios(jugadores, CANTIDAD) / cantidadJugadores;

	return promedio;
}

/**
 * \fn int SuperiorPromedio(eLibro[], int)
 * \brief
 *
 * \param libros
 * \param tam
 * \return
 *
 * Esta funcion sirve para saber que libro supera el promedio de importe.
 * La funcion recorre el for verificiando si el libro es mayor al promedio,
 * si es asi suma uno a la variable contadorLibros y luego la retorna.
 *
 */
int SuperiorPromedio(eJugador jugadores[], int tam) {
	int contadorJugadores = 0;

	for (int i = 0; i < tam; ++i) {
		if (jugadores[i].salario > Promedio(jugadores, tam)) {
			contadorJugadores++;
		}
	}

	return contadorJugadores;
}

void MostrarSalario(eJugador jugadores[], int tam) {
	int salarioTotal;
	float promedio;
	int mayorPromedio;

	salarioTotal = TotalSalarios(jugadores, tam);
	promedio = Promedio(jugadores, tam);
	mayorPromedio = SuperiorPromedio(jugadores, tam);

	printf("\nEl total de todos los salarios es: %d, El promedio total es: %.2f y la cantidad de jugadores que cobran mas que el promedio son %d\n"
			,salarioTotal , promedio, mayorPromedio);
}

int CompararMayorNumero (int numeroUno, int numeroDos, int numeroTres, int numeroCuatro, int numeroCinco, int numeroSeis) {
	int opcion;

	if (numeroUno > numeroDos && numeroUno > numeroTres && numeroUno > numeroCuatro && numeroUno > numeroCinco && numeroUno > numeroSeis) {
		opcion = 0;
	}
	else {
		if (numeroDos > numeroTres && numeroDos > numeroCuatro && numeroDos > numeroCinco && numeroDos > numeroSeis && numeroDos > numeroUno) {
			opcion = 1;
		}
		else {
			if (numeroTres > numeroUno && numeroTres > numeroDos && numeroTres > numeroCuatro && numeroTres > numeroCinco && numeroTres > numeroSeis) {
				opcion = 2;
			}
			else {
				if (numeroCuatro > numeroUno && numeroCuatro > numeroDos && numeroCuatro > numeroTres && numeroCuatro > numeroCinco && numeroCuatro > numeroSeis) {
					opcion = 3;
				}
				else {
					if (numeroCinco > numeroUno && numeroCinco > numeroDos && numeroCinco > numeroTres && numeroCinco > numeroCuatro && numeroCinco > numeroSeis) {
						opcion = 4;
					}
					else {
						if (numeroSeis > numeroUno && numeroSeis > numeroDos && numeroSeis > numeroTres && numeroSeis > numeroCuatro && numeroSeis > numeroCinco) {
							opcion = 5;
						}
					}
				}
			}
		}
	}

	return opcion;
}

void ConfederacionMayorContratos(eJugador jugadores[], int tam) {
	char confederacionMayorContrato[20];
	int mayorContratos;
	int acumuladorConmebol = 0;
	int acumuladorUefa = 0;
	int acumuladorAfc = 0;
	int acumuladorCaf = 0;
	int acumuladorConcacaf = 0;
	int acumuladorOfc = 0;
	int opcion;

	for(int i=0; i<tam; i++) {
		if(jugadores[i].isEmpty == LLENO) {
			if (strcmp(jugadores[i].idConfederacion.nombre, "CONMEBOL") == 0){
				acumuladorConmebol = acumuladorConmebol + jugadores[i].aniosContrato;
			}
			else {
				if (strcmp(jugadores[i].idConfederacion.nombre, "UEFA") == 0) {
					acumuladorUefa = acumuladorUefa + jugadores[i].aniosContrato;
				}
				else {
					if (strcmp(jugadores[i].idConfederacion.nombre, "AFC") == 0) {
						acumuladorAfc = acumuladorAfc + jugadores[i].aniosContrato;
					}
					else {
						if (strcmp(jugadores[i].idConfederacion.nombre, "CAF") == 0) {
							acumuladorCaf = acumuladorCaf + jugadores[i].aniosContrato;
						}
						else {
							if (strcmp(jugadores[i].idConfederacion.nombre, "CONCACAF") == 0) {
								acumuladorConcacaf = acumuladorConcacaf + jugadores[i].aniosContrato;
							}
							else {
								if (strcmp(jugadores[i].idConfederacion.nombre, "OFC") == 0) {
									acumuladorOfc = acumuladorOfc + jugadores[i].aniosContrato;
								}
							}
						}
					}
				}
			}
		}
	}

	opcion = CompararMayorNumero (acumuladorConmebol, acumuladorUefa, acumuladorAfc, acumuladorCaf, acumuladorConcacaf, acumuladorOfc);

	switch (opcion) {
		case 0:
			strcpy(confederacionMayorContrato, "CONMEBOL");
			mayorContratos = acumuladorConmebol;
			break;
		case 1:
			strcpy(confederacionMayorContrato, "UEFA");
			mayorContratos = acumuladorUefa;
			break;
		case 2:
			strcpy(confederacionMayorContrato, "AFC");
			mayorContratos = acumuladorAfc;
			break;
		case 3:
			strcpy(confederacionMayorContrato, "CAF");
			mayorContratos = acumuladorCaf;
			break;
		case 4:
			strcpy(confederacionMayorContrato, "CONCACAF");
			mayorContratos = acumuladorConcacaf;
			break;
		case 5:
			strcpy(confederacionMayorContrato, "OFC");
			mayorContratos = acumuladorOfc;
			break;
	}

	printf("La confederacion con mayor cantidad de años de contrato es %s con una cantidad de %d años de contratos.\n", confederacionMayorContrato, mayorContratos);
}

float calcularPorcentajeJugador (int totalJugadores, int jugadoresConfederacion) {
	float porcentaje;

	porcentaje = (float)jugadoresConfederacion * 100 / totalJugadores;

	return porcentaje;
}

void InformarPorcentajeJugadores (eJugador jugadores[], int tam) {
	int contadorConmebol = 0;
	int contadorUefa = 0;
	int contadorAfc = 0;
	int contadorCaf = 0;
	int contadorConcacaf = 0;
	int contadorOfc = 0;
	int contadorJugadores = 0;
	float porcentajeConmebol = 0;
	float porcentajeUefa = 0;
	float porcentajeAfc = 0;
	float porcentajeCaf = 0;
	float porcentajeConcacaf = 0;
	float porcentajeOfc = 0;



	for(int i=0; i<tam; i++) {
		if(jugadores[i].isEmpty == LLENO) {
			contadorJugadores++;
			if (strcmp(jugadores[i].idConfederacion.nombre, "CONMEBOL") == 0){
				contadorConmebol++;
			}
			else {
				if (strcmp(jugadores[i].idConfederacion.nombre, "UEFA") == 0) {
					contadorUefa++;
				}
				else {
					if (strcmp(jugadores[i].idConfederacion.nombre, "AFC") == 0) {
						contadorAfc++;
					}
					else {
						if (strcmp(jugadores[i].idConfederacion.nombre, "CAF") == 0) {
							contadorCaf++;
						}
						else {
							if (strcmp(jugadores[i].idConfederacion.nombre, "CONCACAF") == 0) {
								contadorConcacaf++;
							}
							else {
								if (strcmp(jugadores[i].idConfederacion.nombre, "OFC") == 0) {
									contadorOfc++;
								}
							}
						}
					}
				}
			}
		}
	}
	porcentajeConmebol = calcularPorcentajeJugador(contadorJugadores, contadorConmebol);
	porcentajeUefa = calcularPorcentajeJugador(contadorJugadores, contadorUefa);
	porcentajeAfc = calcularPorcentajeJugador(contadorJugadores, contadorAfc);
	porcentajeCaf = calcularPorcentajeJugador(contadorJugadores, contadorCaf);
	porcentajeConcacaf = calcularPorcentajeJugador(contadorJugadores, contadorConcacaf);
	porcentajeOfc = calcularPorcentajeJugador(contadorJugadores, contadorOfc);

	printf("\nLos porcentajes de jugadores por confederacion son los siguientes: | CONMEBOL: %.2f | UEFA: %.2f | AFC: %.2f | CAF: %.2f | CONCACAF: %.2f | OFC: %.2f |\n",
			porcentajeConmebol, porcentajeUefa, porcentajeAfc, porcentajeCaf, porcentajeConcacaf, porcentajeOfc);
}

void RegionMasJugadores(eJugador jugadores[], int tam) {
	char regionMasJugadores[20];
	int cantidadJugadores;
	int contadorConmebol = 0;
	int contadorUefa = 0;
	int contadorAfc = 0;
	int contadorCaf = 0;
	int contadorConcacaf = 0;
	int contadorOfc = 0;
	int opcion;

	for(int i=0; i<tam; i++) {
		if(jugadores[i].isEmpty == LLENO) {
			if (strcmp(jugadores[i].idConfederacion.nombre, "CONMEBOL") == 0){
				contadorConmebol++;
			}
			else {
				if (strcmp(jugadores[i].idConfederacion.nombre, "UEFA") == 0) {
					contadorUefa++;
				}
				else {
					if (strcmp(jugadores[i].idConfederacion.nombre, "AFC") == 0) {
						contadorAfc++;
					}
					else {
						if (strcmp(jugadores[i].idConfederacion.nombre, "CAF") == 0) {
							contadorCaf++;
						}
						else {
							if (strcmp(jugadores[i].idConfederacion.nombre, "CONCACAF") == 0) {
								contadorConcacaf++;
							}
							else {
								if (strcmp(jugadores[i].idConfederacion.nombre, "OFC") == 0) {
									contadorOfc++;
								}
							}
						}
					}
				}
			}
		}
	}

	opcion = CompararMayorNumero (contadorConmebol, contadorUefa, contadorAfc, contadorCaf, contadorConcacaf, contadorOfc);

	switch (opcion) {
		case 0:
			strcpy(regionMasJugadores, "CONMEBOL");
			cantidadJugadores = contadorConmebol;
			break;
		case 1:
			strcpy(regionMasJugadores, "UEFA");
			cantidadJugadores = contadorUefa;
			break;
		case 2:
			strcpy(regionMasJugadores, "AFC");
			cantidadJugadores = contadorAfc;
			break;
		case 3:
			strcpy(regionMasJugadores, "CAF");
			cantidadJugadores = contadorCaf;
			break;
		case 4:
			strcpy(regionMasJugadores, "CONCACAF");
			cantidadJugadores = contadorConcacaf;
			break;
		case 5:
			strcpy(regionMasJugadores, "OFC");
			cantidadJugadores = contadorOfc;
			break;
	}
	printf("\nLa region con mas jugadores es %s con una cantidad de %d jugadores.\n", regionMasJugadores, cantidadJugadores);
}




