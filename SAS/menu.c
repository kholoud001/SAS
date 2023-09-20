#include <stdio.h>
#include <stdlib.h>

void Choice() {
    printf("\n\n************** Menu principal ********************\n\n");
    printf("0. Menu principal\n");
    printf("1. Afficher tache\n");
    printf("2. Ajouter plusieurs taches\n");
    printf("3. Rechercher une tache\n");
    printf("4. Modifier tache\n");
    printf("5. Supprimer tache\n");
    printf("6. Statistiques\n");
    printf("7. Quitter\n");
}

int main() {
    int choice;

    do {
        Choice();
        printf("\nEntrez votre choix =====> ");
        if (scanf("%d", &choice) != 1) {
            printf("Entrée invalide. Veuillez entrer un nombre valide.\n");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            switch (choice) {
                case 0: printf("\nVous avez choisi le Menu principal\n");
                        // Implement the corresponding functionality
                        break;
                case 1: printf("\nVous avez choisi d'afficher tache\n");
                        // Implement the corresponding functionality
                        break;
                case 2: printf("\nVous avez choisi d'ajouter plusieurs taches\n");
                        // Implement the corresponding functionality
                        break;
                case 3: printf("\nVous avez choisi de rechercher une tache\n");
                        // Implement the corresponding functionality
                        break;
                case 4: printf("\nVous avez choisi de modifier une tache\n");
                        // Implement the corresponding functionality
                        break;
                case 5: printf("\nVous avez choisi de supprimer une tache\n");
                        // Implement the corresponding functionality
                        break;
                case 6: printf("\nVous avez choisi statistiques\n");
                        // Implement the corresponding functionality
                        break;
                case 7: printf("\nVous avez choisi de quitter le programme\n");
                        exit(0); // Exit the program
                default: printf("\nChoix invalide. Veuillez entrer un nombre entre 0 et 7.\n");
                         break;
            }
        }
    } while (1);

    return 0;
}
