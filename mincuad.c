/*
01234567890123456789

    M�dulo de proyecto

Archivo:            mincuad.c
Proyecto:           MinCuad

Programador:        Miguel Angel Norzagaray Cos�o

Fecha de inicio:    Mayo de 2008

Historia de cambios:

Prop�sito:
            Encontrar los par�metros de la recta que
        mejor se ajusta a un conjunto de puntos.

Metodolog�a:
            Se presentan varias versiones, desde la mas
        sencilla que encuentra los par�metros hasta
        aquellas que calculan la covarianza o suman con
        mayor exactitud.

Referencias:

Dise�o estructural:
            Cada funci�n trabaja de maera independiente.

Entrada:
            Solo la tabla de datos (x,y) y la la cantidad
        que son.

Salida:
            Los par�metros hasta m�rgenes de error y otros
        estad�sticos.

Efectos colaterales:

*/

#include <math.h>

/* Versi�n sencilla, solo calcula los par�metros */
void MinCuadLineales(double **T, int n, double *a, double *b)
{
    int i;
    double Sx, Sy, Sx2, Sxy;
    double Div;

    Sx=Sy=Sx2=Sxy=0.0;
    for (i=0 ; i<n ; i++) {
        Sx += T[i][0];
        Sy += T[i][1];
        Sx2 += T[i][0]*T[i][0];
        Sxy += T[i][0]*T[i][1];

    }
    Div = n*Sx2-Sx*Sx;
    *a = (n*Sxy-Sx*Sy)/Div;
    *b = (Sx2*Sy-Sxy*Sx)/Div;
}

/* Calcula los par�metros lineales y los errores en cada uno */
void MinCuadLinealesErr(double **T, int n, double *a, double *b,
                        double *da, double *db)
{
    int i;
    double Sx, Sy, Sx2, Sxy;
    double Divisor;
    double SumaDif,t;
    double Desviacion;

    Sx=Sy=Sx2=Sxy=0.0;
    for (i=0 ; i<n ; i++) {
        Sx += T[i][0];
        Sy += T[i][1];
        Sx2 += T[i][0]*T[i][0];
        Sxy += T[i][0]*T[i][1];

    }
    Divisor = n*Sx2-Sx*Sx;
    *a = (n*Sxy-Sx*Sy)/Divisor;
    *b = (Sx2*Sy-Sxy*Sx)/Divisor;

    SumaDif = 0.0;
    for ( i=0 ; i<n ; i++ ) {
        t = T[i][1] - *a*T[i][0] - *b;
        SumaDif += t*t;
    }
    Desviacion = sqrt(SumaDif/(n-2));
    *da = sqrt(n)*Desviacion/sqrt(Divisor);
    *db = *da*sqrt(Sx2/n);
}

/* Fin de archivo */
