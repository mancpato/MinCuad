/*
01234567890123456789

    Archivo principal

Archivo:            mainmc.c
Proyecto:           MinCuad

Programador:        Miguel Angel Norzagaray Cos�o

Fecha de inicio:    Mayo de 2008

Historia de cambios:
	- noviembre, 2008: Comparar eficiencia usando dos arreglos
	  en vez de una tabla.
    - 2022, DEBUG macro como ejemplo para Programaci�n de Sistemas.

Prop�sito:
            Probar las rutinas de regresi�n lineal
        del m�dulo mincuad.c

Metodolog�a:
            Se leen los datos de un archivo en forma de tabla y
        se calcula la regresi�n lineal:
                y = ax + b
        determinando los t�rminos de error tanto para a como b.
        Se presentan los par�metros calculados.

Referencias:

Dise�o estructural:
            Se utilizan funciones de leerarch.c y de
        mincuad.c

Entrada:
            El nombre del archivo donde est�n los datos
        indicado desde la l�nea de comandos.
            Se espera que el archivo inicie con un n�mero
        entero que indica la cantidad de datos por leer.
            Por ejemplo:
                3
                1.4   6.78
                2.3   2.9
                3.5  -1.43

Salida:
            Los par�metros calculados.

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
    puts(" - - - - - -\nPrograma de Regresi�n Lineal");
    puts("Ejemplo para estudiantes de la UABCS/DASC");
    printf("%s versi�n %s %s\n",args[0],FULLVERSION_STRING,STATUS);
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
