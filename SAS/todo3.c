#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>


//TO DO struct
typedef struct ToDo{
  int id;
  char titre[20],description[50],status[10];
  double deadline;
  //    time_t deadline;  // Change the type to time_t
} ToDo;

// Menu
void Choice() {
    printf("\n\n************** Menu principal ********************\n\n");
    printf("0. Menu principal\n");
    printf("1. Ajouter plusieurs taches\n");
    printf("2. Afficher tache\n");
    printf("3. Rechercher une tache\n");
    printf("4. Modifier tache\n");
    printf("5. Supprimer tache\n");
    printf("6. Statistiques\n");
    printf("7. Quitter\n");
}


//Ajouter TODO list 
void AddToDoList(ToDo T[], int n){
int i;
for(i=0;i<n;i++){
   //printf("entrer id : \n");
    //scanf("%d",&T->id);
    T[i].id=i+1;
    printf("entrer un titre de tache: \n");
    scanf("%s",T[i].titre);
    printf("entrer une description de tache: \n");
    scanf("%s",T[i].description);
    printf("entrer un status de tache: \n");
    scanf("%s",T[i].status);
    printf("entrer une date: \n");
    scanf("%lf",&T[i].deadline);
}
}


//TO display TODO LIST
void DisplayList(ToDo T[], int n){
int i;
for(i=0;i<n;i++){
    printf("id: %d ",T[i].id);
    printf("Titre: %s ",T[i].titre);
    printf("Description: %s ",T[i].description);
    printf("Deadline: %lf ",T[i].deadline);
    printf("Status: %s ",T[i].status);
    printf("\n");
}
}

//Sort alphabetically TODO list (titles)
void ToDoSort(ToDo T[], int n){
  int i,j;
  ToDo tmp;

  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      if(strcmp(T[i].titre,T[j].titre)>0){
            tmp = T[i];
            T[i] = T[j];
            T[j] = tmp;
         }
    }
  }
}

//Rechercher une tâche par son Identifiant.
int SearchById(ToDo T[], int n, int identifiant){
  int i;
  for(i=0; i<n;i++){
    if(T[i].id==identifiant)
    return i;
  }
      return -1;
}

//Rechercher une tâche par son Titre
int SearchByTitle(ToDo T[], int n, const char title[]){
  int i;
  for(i=0; i<n;i++){
    if(strcmp(T[i].titre,title)==0)
    return i;
  }
          return -1;
}

//Modifier la description d'une tâche.

void ModifDesc(ToDo T[], int n, int taskId, char desc[]){

    int taskIndex = SearchById(T, n, taskId); // Search for the task by ID
    if (taskIndex != -1) {
        // Found the task by ID, update its description
        strcpy(T[taskIndex].description, desc);
    }
}

//Modifier le statut d’une tâche.
void ModifStatus(ToDo T[], int n, int taskId, char status[]){

    int taskIndex = SearchById(T, n, taskId); // Search for the task by ID
    if (taskIndex != -1) {
        // Found the task by ID, update its description
        strcpy(T[taskIndex].status, status);
    }
}

int main() {
    int choice,n,search_choice,modif_choice,display_choice;
    int identifiant,search_id,search_title;
    char title[20];
    char desc_modif[50],stat_modif[20];
    ToDo t[100];


    do {
        Choice();
        printf("\nEntrez votre choix =====> ");
        if (scanf("%d", &choice) != 1) {
            printf("Entrée invalide. Veuillez entrer un nombre valide.\n");
            while (getchar() != '\n'); // Clear the input buffer
        } else {
            switch (choice) {
                case 0: printf("\nVous avez choisi le Menu principal\n");
                        break;
                case 1: printf("\nVous avez choisi d'ajouter plusieurs taches\n");                      
                            printf("Entrer le nombre des taches que vous voulez ajouter: ");
                            if (scanf("%d", &n) != 1) {
                                printf("Entrée invalide. Veuillez entrer un nombre valide.\n");
                                while (getchar() != '\n'); // Clear the input buffer
                            } else {
                                AddToDoList(t,n);
                                break;
                            }
                case 2: printf("\nVous avez choisi d'afficher tache\n");
                        //Affichage 
                        ////////// trie par ordre alpha ou par deadline ou  les tâches dont le deadline est dans 3 jours ou moins
                                printf("1. Affichage par ordre alphabétique \n");
                                printf("2. Affichage par deadline \n");
                                printf("3. Affichage des tâches dont le deadline est dans 3 jours ou moins \n");
                                printf("\nEntrez votre choix =====> ");
                                if (scanf("%d", &display_choice) != 1) {
                                    printf("Entrée invalide. Veuillez entrer un nombre valide.\n");
                                    while (getchar() != '\n'); // Clear the input buffer
                                } else {
                                    switch (display_choice)
                                    {
                                    case 1:
                                    printf("\n Vous avez choisi l'affichage de liste apres le triage alphabetique\n:");
                                    ToDoSort(t,n);
                                    case 2: 
                                    printf("\n Vous avez choisi l'affichage par deadline \n");
                                    //// fonction tri par deadline
                                    break;
                                    case 3:
                                     printf("Vous avez choisi l'affichage par deadline \n");
                                    ////////////fonction tri par deadline < 3
                                    }
                                    break;
                                }
                        break;                
                case 3: printf("\nVous avez choisi de rechercher une tache\n");
                //recherche soit par id ou par titre
                                printf("1. Recherche par id \n");
                                printf("2. Recherche par titre\n");
                                printf("\nEntrez votre choix =====> ");
                                if (scanf("%d", &search_choice) != 1) {
                                    printf("Entrée invalide. Veuillez entrer un nombre valide.\n");
                                    while (getchar() != '\n'); // Clear the input buffer
                                } else {
                                    switch (search_choice)
                                    {
                                    case 1:
                                    printf("entrer l'identifiant que vous voullez trouver dans la liste:");
                                    scanf("%d",&identifiant);
                                    search_id=SearchById(t,n,identifiant);
                                    printf("l'identifiant %d se trouve à la position %d \n",identifiant,search_id);                                    break;
                                    case 2: 
                                    printf("entrer le titre que vous voullez trouver dans la liste:");
                                    scanf("%s",title); 
                                    search_title=SearchByTitle(t,n,title);
                                    printf("le titre %s se trouve à la position %d \n",title,search_title);
                                    break;
                                    }
                                    break;
                                }
                case 4: printf("\nVous avez choisi de modifier une tache\n");
                 //modification : par description / par status / par deadline
                                printf("1. Modification par description \n");
                                printf("2. Modification par par status\n");
                                printf("2. Modification par deadline\n");
                                printf("\nEntrez votre choix =====> ");
                                if (scanf("%d", &modif_choice) != 1) {
                                    printf("Entrée invalide. Veuillez entrer un nombre valide.\n");
                                    while (getchar() != '\n'); // Clear the input buffer
                                } else {
                                    switch (modif_choice)
                                    {
                                    case 1:
                                    printf("\n Vous avez choisi de modifier la description \n");
                                    printf("entrer l'identifiant de la description que vous voullez modifier dans la liste:");
                                    scanf("%d",&identifiant);
                                    // //saisie la description que vous voullez modifier
                                        printf("saisir la description:  ");
                                        scanf("%s",desc_modif);
                                    ModifDesc(t,n,identifiant,desc_modif);
                                    break;
                                    case 2:
                                    printf("\n Vous avez choisi de modifier le status \n");
                                    printf("entrer l'identifiant du status que vous voullez modifier dans la liste:");
                                    scanf("%d",&identifiant);
                                    // //saisie le status que vous voullez modifier
                                        printf("saisir le status:  ");
                                        scanf("%s",stat_modif);
                                    ModifDesc(t,n,identifiant,stat_modif);
                                    break;
                                    }
                                    break;
                                }

                case 5: printf("\nVous avez choisi de supprimer une tache\n");
                        // Implement the corresponding functionality
                        break;
                case 6: printf("\nVous avez choisi statistiques\n");
                        // Implement the corresponding functionality
                        break;
                case 7: exit(0); // Exit the program   
            }
        }
    } while (1);
    return 0;
}
