#include "bibliotheque.h"
#include <stdio.h>
#include <math.h>

// Fonctions originales
unsigned int fact(unsigned int value) {
    unsigned int result = 1;
    while (value > 1) {
        result *= value;
        value--;
    }
    return result;
}

int power(int value, unsigned int pow) {
    if (pow == 0) return 1;
    if (pow == 1) return value;
    int accumulator = 1;
    while (pow > 0) {
        accumulator *= value;
        pow--;
    }
    return accumulator;
}

// Exercice 13 - Permutation
void permut(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Exercice 7 - Équation du second degré
SolutionSecondDegre resoudreEquationSecondDegre(double a, double b, double c) {
    SolutionSecondDegre sol;
    
    // Cas dégénérés
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                // 0 = 0 : infinité de solutions
                sol.nb_solutions = -1;
            } else {
                // c = 0 avec c ≠ 0 : aucune solution
                sol.nb_solutions = 0;
            }
        } else {
            // Équation du premier degré bx + c = 0
            sol.nb_solutions = 1;
            sol.x1 = -c / b;
            sol.x2 = sol.x1;
        }
        return sol;
    }
    
    // Cas général du second degré
    double delta = b * b - 4 * a * c;
    
    if (delta < 0) {
        sol.nb_solutions = 0;
    } else if (delta == 0) {
        sol.nb_solutions = 1;
        sol.x1 = -b / (2 * a);
        sol.x2 = sol.x1;
    } else {
        sol.nb_solutions = 2;
        double sqrt_delta = sqrt(delta);
        sol.x1 = (-b - sqrt_delta) / (2 * a);
        sol.x2 = (-b + sqrt_delta) / (2 * a);
    }
    
    return sol;
}

void afficherSolutionSecondDegre(SolutionSecondDegre sol) {
    switch (sol.nb_solutions) {
        case -1:
            printf("Infinité de solutions (équation 0 = 0)\n");
            break;
        case 0:
            printf("Aucune solution réelle\n");
            break;
        case 1:
            printf("Une solution unique: x = %.2f\n", sol.x1);
            break;
        case 2:
            printf("Deux solutions: x1 = %.2f, x2 = %.2f\n", sol.x1, sol.x2);
            break;
    }
}

// Exercice 12a - Nombre premier
int estPremier(unsigned int n) {
    if (n <= 1) return 0; // 0 et 1 ne sont pas premiers
    if (n == 2) return 1; // 2 est premier
    if (n % 2 == 0) return 0; // Les nombres pairs > 2 ne sont pas premiers
    
    // Vérifier les diviseurs impairs jusqu'à sqrt(n)
    for (unsigned int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

// Exercice 13 - Structure Point et distance
double distancePoints(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}
