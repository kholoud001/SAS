#include<stdio.h>


void Choice(int c){

    printf("\n\n**************Menu principal********************\n\n");
    printf("0. Menu principal \n");
    printf("1. Afficher tache: \n");
    printf("2. Ajouter  plusieurs taches \n");
    printf("3. Rechercher une tache \n");
    printf("4. Modifier tache\n");
    printf("5. Supprimer tache\n");
    printf("6. Statistiques \n");
    printf("7. Retourner\n");
}

int main(){
    int choice;
    

    while(1){
        Choice(choice);
        printf("\n\n Entrez votre choix  =====>  ");
        if (scanf("%d", &choice) != 1) {
            printf("Entrée invalide. Veuillez entrer un nombre valide.\n");
            while (getchar() != '\n'); // Vider le tampon d'entrée
            //continue;
             } 
    switch (choice){
        case 0: printf("\n Vous avez choisi le Menu principal \n");
        //function 
        break;
         case 1: printf("\n Vous avez choisi d'afficher tache \n");
        //function 
        break; 
        case 2: printf("\n Vous avez choisi d'ajouter plusieurs taches \n");
        //function 
        break;
        case 3: printf("\n Vous avez choisi de rechercher une tache \n");
        //function 
        break; 
        case 4: printf("\n Vous avez choisi de modifier une tache \n");
        //function 
        break; 
        case 5: printf("\n Vous avez choisi du supprimer une tache \n");
        //function 
        break; 
        case 6: printf("\n Vous avez choisi statistiques \n");
        //function 
        break;
        case 7: printf("\n Vous avez choisi de retourner au  menu principal \n");
        //function 
        break;
    }
    }
    
  

}
