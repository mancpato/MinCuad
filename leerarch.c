/*
01234567890123456789

    Módulo de proyecto

Archivo:            leerarch.c
Proyecto:           MinCuad

Programador:        Miguel Angel Norzagaray Cosío

Fecha de inicio:    Mayo de 2008

Historia de cambios:

Propósito:
            Leer datos de un archivo. Los datos deben
        estar dado en forma de coordenadas.

Metodología:
            Se recibe el nombre del archivo, se abre,
        se lee la cantidad de datos (pares ordenados),
        se pide la memoria necesaria y se procede a leerlos.

            La memoria queda organizada como un arreglo (T) de
        n apuntadores a vectores de la dimensión indicada (T[i]).

Referencias:

Diseño estructural:
            Cada función trabaja de manera independiente.

Entrada:
            El nombre del archivo. En el caso de la función
        LeerPuntosDim también se recibe la dimensión de los vectores.
            El archivo debe indicar la cantidad de coordenadas por
        leer, aunque se verifica el fin de archivo para comprobar
        la cantidad correcta.
            Ejemplo:
                4
                1.2 4.5
                1.3 5.7
                1.4 6.1
                1.5 6.9
                1.6 7.8

Salida:
            La tabla leida, la cantidad de datos (pares
        ordenados o tuplas de dimensión Dim) y un indicador de
        posibles errores.

            Se identifica el fin de archivo, por lo que si se
        encuentra antes de que se lean n datos, se regresa
        la cantidad correcta de valores.

Efectos colaterales:
            No hay comprobaciones adicionales, se supone que el
        archivo tiene los pares ordenados completos, es decir, si
        se están leyendo tupla de 3 números, no se comprueba que al
        final del archivo solo queden 2 números. Por lo tanto, si
        el archivo es
            5
            1.2 4.5
            1.3 5.7
            1.4 6.1
            1.5
        los resultados serán inciertos.

*/

#include "leerarch.h"
#include <stdio.h>
#include <stdlib.h>

/* Se leen datos en dos dimensiones (xi,yi) */
double **LeerArchivoXY(const char *Nombre, int *N, int *S)
{
    int i,n;
    double **T;
    FILE *f;

    if ( !(f=fopen(Nombre,"r")) ) {
        *S = NO_ARCHIVO;
        return NULL;
    }
    fscanf(f,"%d",&n);
    T = (double **)malloc(n*sizeof(double *));
    if ( !T ) {
        *S = NO_MEMORIA;
        return NULL;
    }

    for ( i=0; i<n ; i++ ) {
        T[i] = (double *)malloc(2*sizeof(double));
        if ( !T[i] ) {
            for ( i-- ; i>=0 ; i-- )
                free(T[i]);
            free(T);
            *S = NO_MEMORIA;
            return NULL;
        }
    }

    for ( i=0 ; i<n  && !feof(f) ; i++)
        fscanf(f,"%lf %lf", &T[i][0], &T[i][1]);
    fclose(f);
    *N = i-1;

    return T;
}

/* Se leen puntos desde un archivo, indicando de qué dimensión
  se trata */
double **LeerPuntosDim(const char *Nombre, int *N, int Dim, int *S)
{
    int i,j,n;
    double **T;
    FILE *f;

    if ( !(f=fopen(Nombre,"r")) ) {
        *S = NO_ARCHIVO;
        return NULL;
    }
    fscanf(f,"%d",&n);
    T = (double **)malloc(n*sizeof(double *));
    if ( !T ) {
        *S = NO_MEMORIA;
        return NULL;
    }

    for ( i=0; i<n ; i++ ) {
        T[i] = (double *)malloc(Dim*sizeof(double));
        if ( !T[i] ) {
            for ( i-- ; i>=0 ; i-- )
                free(T[i]);
            free(T);
            *S = NO_MEMORIA;
            return NULL;
        }
    }

    for ( i=0 ; i<n ; i++) {
        for ( j=0 ; j<Dim ; j++) {
            fscanf(f,"%lf", &T[i][j]);
            if ( feof(f) )
                break;
        }
		if ( feof(f) )
			break;
    }

    for ( j=i ; j<n ; j++ )
        free(T[j]);

    fclose(f);
    *N = i;

    return T;
}

/* Fin de archivo */
