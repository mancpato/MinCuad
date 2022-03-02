/*
01234567890123456789

    Archivo principal

Archivo:            mainmc.c
Proyecto:           MinCuad

Programador:        Miguel Angel Norzagaray Cosío

Fecha de inicio:    Mayo de 2008

Historia de cambios:
	- noviembre, 2008: Comparar eficiencia usando dos arreglos
	  en vez de una tabla.
    - 2022, DEBUG macro como ejemplo para Programación de Sistemas.

Propósito:
            Probar las rutinas de regresión lineal
        del módulo mincuad.c

Metodología:
            Se leen los datos de un archivo en forma de tabla y
        se calcula la regresión lineal:
                y = ax + b
        determinando los términos de error tanto para a como b.
        Se presentan los parámetros calculados.

Referencias:

Diseño estructural:
            Se utilizan funciones de leerarch.c y de
        mincuad.c

Entrada:
            El nombre del archivo donde están los datos
        indicado desde la línea de comandos.
            Se espera que el archivo inicie con un número
        entero que indica la cantidad de datos por leer.
            Por ejemplo:
                3
                1.4   6.78
                2.3   2.9
                3.5  -1.43

Salida:
            Los parámetros calculados.

Efectos colaterales:

*/

#include "mincuad.h"
#include "leerarch.h"
#include "version.h"
#include <stdio.h>

int main(int nargs, char *args[])
{
    double **T;
    double a, b,da,db;
    int n;
    int S;

    if ( nargs < 2 ) {
        printf("Usar: %s archivo\n", args[0]);
        return 0;
    }
#if DEBUG
    puts(" - - - - - -\nPrograma de Regresión Lineal");
    puts("Ejemplo para estudiantes de la UABCS/DASC");
    printf("%s versión %s %s\n",args[0],FULLVERSION_STRING,STATUS);
    puts("Ejecutable para depurar: DEBUG definida");
#endif

    T = LeerPuntosDim(args[1], &n, 2, &S);
    if ( !T ) {
        switch ( S ) {
            case NO_ARCHIVO:
                printf("Error al leer %s\n",args[1]);
                break;
            case NO_MEMORIA:
                printf("Error de memoria");
                break;
        }
        return 0;
    }
#if DEBUG
    printf("%d puntos leidos de %s\n",n,args[1]);
    puts(" - - - - - -");
#endif

    MinCuadLinealesErr(T,n,&a,&b,&da,&db);
    printf("f(x)= %.17gx + %.17g\n",a,b);
    printf("da = %g\t db = %g\n",da,db);

    return 0;
}

/* Fin de archivo */
