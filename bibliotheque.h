#ifndef __MY_MATH_LIB_H
#define __MY_MATH_LIB_H

// Fonctions originales
unsigned int fact(unsigned int value);
int power(int value, unsigned int pow);

// Exercice 13 - Permutation
void permut(int *a, int *b);

// Exercice 7 - Équation du second degré
typedef struct {
    double x1;
    double x2;
    int nb_solutions; // -1: infinité, 0: aucune, 1: une, 2: deux
} SolutionSecondDegre;

SolutionSecondDegre resoudreEquationSecondDegre(double a, double b, double c);
void afficherSolutionSecondDegre(SolutionSecondDegre sol);

// Exercice 12a - Nombre premier
int estPremier(unsigned int n);

// Exercice 13 - Structure Point et distance
typedef struct {
    double x;
    double y;
} Point;

double distancePoints(Point p1, Point p2);

#endif
