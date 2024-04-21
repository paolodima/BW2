#include <stdio.h>
#include <stdlib.h>

// Funzione per controllare se l'input è un intero valido
int isValidIntInput() {
    int input;
    while (scanf("%d", &input) != 1) {
        printf("Input non valido. Inserire un intero:\n");
        while (getchar() != '\n'); 
    }
    return input;
}

// Funzione per controllare se l'input del vettore è un intero valido
void inputValidVector(int *vector, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("[%d]: ", i + 1);
        vector[i] = isValidIntInput();
    }
}

// Codice corretto che non causa segmentation fault
void codice_corretto() {
    int vector[10], i, j, k;
    int swap_var;

    printf("Inserire 10 interi:\n");
    inputValidVector(vector, 10);

    printf("Il vettore inserito e':\n");
    for (i = 0; i < 10; i++) {
        printf("[%d]: %d\n", i + 1, vector[i]);
    }

    for (j = 0; j < 10 - 1; j++) {
        for (k = 0; k < 10 - j - 1; k++) {
            if (vector[k] > vector[k + 1]) {
                swap_var = vector[k];
                vector[k] = vector[k + 1];
                vector[k + 1] = swap_var;
            }
        }
    }
    printf("Il vettore ordinato e':\n");
    for (j = 0; j < 10; j++) {
        printf("[%d]: %d\n", j + 1, vector[j]);
    }
}

int main() {
    int scelta;

    printf("Menu:\n");
    printf("1. Esegui il codice errato\n");
    printf("2. Esegui il codice corretto\n");
    printf("Scelta: ");

    if (scanf("%d", &scelta) != 1) {
        printf("Input non valido.\n");
        return 1;
    }

    switch (scelta) {
        case 1:
            // Esegui il programma errato
            printf("Programma errato:\n");
            {
                int vector[10], i, j, k;
                int swap_var;

                printf("Inserire 10 interi:\n");
                inputValidVector(vector, 10);

                printf("Il vettore inserito e':\n");
                for (i = 0; i >= 0; i++) {
                    printf("[%d]: %d\n", i + 1, vector[i]);
                }

                for (j = 0; j < 10 - 1; j++) {
                    for (k = 0; k < 10 - j - 1; k++) {
                        if (vector[k] > vector[k + 1]) {
                            swap_var = vector[k];
                            vector[k] = vector[k + 1];
                            vector[k + 1] = swap_var;
                        }
                    }
                }
                printf("Il vettore ordinato e':\n");
                for (j = 0; j < 10; j++) {
                    printf("[%d]: %d\n", j + 1, vector[j]);
                }
            }
            break;
        case 2:
            // Esegui il codice corretto che non va in segmentation fault
            printf("Codice corretto:\n");
            codice_corretto();
            break;
        default:
            printf("Scelta non valida.\n");
            return 1;
    }

    return 0;
}

