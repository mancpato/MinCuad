#ifndef LEERARCH_H_INCLUDED
#define LEERARCH_H_INCLUDED

#define NO_ARCHIVO 1
#define NO_MEMORIA 2

double **LeerArchivoXY(const char *Nombre, int *n, int *S);
double **LeerPuntosDim(const char *Nombre, int *N, int Dim, int *S);

#endif /* LEERARCH_H_INCLUDED */
