#ifndef MINCUAD_H_INCLUDED
#define MINCUAD_H_INCLUDED

void MinCuadLineales(double **T, int n, double *a, double *b);
void MinCuadLinealesErr(double **T, int n, double *a, double *b,
                        double *da, double *db);

#endif /* MINCUAD_H_INCLUDED */
