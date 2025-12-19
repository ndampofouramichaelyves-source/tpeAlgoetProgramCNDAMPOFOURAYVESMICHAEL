#include <stdio.h>
#include <stdlib.h>
#include "bibliotheque.h"

int main(void) {
    printf("=== Fonctions originales ===\n");
    int result = power(2, 3);
    printf("2³ = %d\n", result);
    
    result = fact(6);
    printf("6! = %d\n\n", result);
    
    printf("=== Exercice 13 - Permutation ===\n");
    int a = 5, b = 10;
    printf("Avant permutation: a = %d, b = %d\n", a, b);
    permut(&a, &b);
    printf("Après permutation: a = %d, b = %d\n\n", a, b);
    
    printf("=== Exercice 7 - Équation du second degré ===\n");
    // Test avec différentes équations
    double coeffs[][3] = {
        {1, -3, 2},    // x² - 3x + 2 = 0 -> deux solutions
        {1, -2, 1},    // x² - 2x + 1 = 0 -> une solution
        {1, 1, 1},     // x² + x + 1 = 0 -> aucune solution
        {0, 2, -4},    // 2x - 4 = 0 -> une solution
        {0, 0, 0}      // 0 = 0 -> infinité de solutions
    };
    
    for (int i = 0; i < 5; i++) {
        printf("Équation %d: ", i + 1);
        SolutionSecondDegre sol = resoudreEquationSecondDegre(
            coeffs[i][0], coeffs[i][1], coeffs[i][2]);
        afficherSolutionSecondDegre(sol);
    }
    printf("\n");
    
    printf("=== Exercice 12a - Nombres premiers ===\n");
    unsigned int nombres[] = {2, 3, 17, 20, 29, 100};
    for (int i = 0; i < 6; i++) {
        printf("%u %s premier\n", nombres[i], 
               estPremier(nombres[i]) ? "est" : "n'est pas");
    }
    printf("\n");
    
    printf("=== Exercice 13 - Points et distance ===\n");
    Point p1, p2;
    
    // Points de test
    p1.x = 1.0; p1.y = 2.0;
    p2.x = 4.0; p2.y = 6.0;
    
    printf("Point 1: (%.1f, %.1f)\n", p1.x, p1.y);
    printf("Point 2: (%.1f, %.1f)\n", p2.x, p2.y);
    printf("Distance entre les points: %.2f\n", distancePoints(p1, p2));
    
    return EXIT_SUCCESS;
}
