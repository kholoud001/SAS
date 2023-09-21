#include<stdio.h>
#include<time.h>
#include<string.h>




//TO DO struct
typedef struct ToDo{
  int id;
  char titre[20],description[50],status[10];
  struct tm deadline;  

} ToDo;


//Ajouter TODO list 
void AddToDoList(ToDo T[], int n){
int i;
for(i=0;i<n;i++){
    T[i].id=i+1;
    printf("entrer un titre de tache: \n");
    scanf("%s",T[i].titre);
    printf("entrer une description de tache: \n");
    scanf("%s",T[i].description);
    printf("entrer un status de tache: \n");
    scanf("%s",T[i].status);
        char dateStr[11]; // Adjust the buffer size as needed
        printf("Enter date (DD/MM/YYYY): ");
        scanf("%10s", dateStr);
        // Parse the date string and store it in the deadline field
        sscanf(dateStr, "%d/%d/%d", &T[i].deadline.tm_mday, &T[i].deadline.tm_mon, &T[i].deadline.tm_year);
        // Adjust month and year since struct tm uses 0-based months and years since 1900
        T[i].deadline.tm_mon--;  // Adjust month to be 0-based (e.g., January is 0)
        T[i].deadline.tm_year -= 1900;  // Adjust year to be years since 1900
}
}
//TO display TODO LIST
void DisplayList(ToDo T[], int n){
int i;
for(i=0;i<n;i++){
    printf("id: %d ",T[i].id);
    printf("Titre: %s ",T[i].titre);
    printf("Description: %s ",T[i].description);
    // printf("Deadline: %s", T[i].deadline);
    printf("Status: %s ",T[i].status);
// Format and display the deadline
        char deadlineStr[20]; // Adjust the buffer size as needed
        strftime(deadlineStr, sizeof(deadlineStr), "%d/%m/%Y", &T[i].deadline);
        printf("Deadline: %s\n", deadlineStr);
        printf("\n"); // Add a separator between tasks
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

//void SortByDeadline(ToDo T[], int n){
//     int i, j;
//     ToDo temp;
//     for(i = 0; i < n-1; i++) {
//         for(j = 0; j < n-i-1; j++) {
//             if(T[j].deadline > T[j+1].deadline) {
//                 // Échanger les éléments
//                 temp = T[j];
//                 T[j] = T[j+1];
//                 T[j+1] = temp;
//             }
//         }
//     }
// }

// void DisplayTasksWithinThreeDays(ToDo T[], int n) {
//     time_t now = time(NULL);
//     time_t threeDaysLater = now + (3 * 24 * 60 * 60); // 3 jours en secondes (24 heures * 60 minutes * 60 secondes)
//     printf("Tâches avec deadline dans 3 jours ou moins :\n");
//     for(int i = 0; i < n; i++) {
//         if(T[i].deadline <= threeDaysLater) {
//             printf("Task ID: %d\n", T[i].id);
//             printf("Title: %s\n", T[i].titre);
//             printf("Description: %s\n", T[i].description);
//             printf("Status: %s\n", T[i].status);
//             printf("Deadline: %s", ctime(&T[i].deadline));
//         }
//     }
// }

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

// void ModifyDeadlineById(ToDo T[], int n, int taskId, time_t newDeadline){
//     int taskIndex = SearchById(T, n, taskId); // Search for the task by ID
//         if(taskIndex != -1){
//             T[taskIndex].deadline = newDeadline;
//             return; // On a trouvé et modifié la tâche, donc on sort de la boucle.
//         }   
//     printf("Aucune tâche avec l'identifiant %d n'a été trouvée.\n", taskId);
// }

//Supprimer une tâche par identifiant.
void DeleteById(ToDo T[], int n, int taskId){

    int taskIndex = SearchById(T, n, taskId); // Search for the task by ID
    if (taskIndex != -1) {
        for (int i = taskIndex; i < n - 1; i++) {
            T[i] = T[i + 1];
        }
        n--; // Decrement the size of the array
    }
}

////////Statiques

//Afficher le nombre des taches
int CountTasks(ToDo T[], int n) {
    return n;
}

void DisplayTotalTasks(ToDo T[], int n) {
    printf("Total number of tasks: %d\n", CountTasks(T, n));
}

// void DisplayDaysUntilDeadline(ToDo T[], int n) {
//     time_t currentTime = time(NULL);
//     for (int i = 0; i < n; i++) {
//         double secondsRemaining = difftime(T[i].deadline, currentTime);
//         int daysRemaining = secondsRemaining / (60 * 60 * 24); // Convert seconds to days
//         printf("Task ID: %d, Title: %s, Days until deadline: %d\n", T[i].id, T[i].title, daysRemaining);
//     }
// }




int main(){

int n,search_id,search_title,identifiant;
char title[20], describe[50], status[10];
///////////la saisie du nombre des taches que vous voullez ajouter
    printf("entrer le nombre des taches que vous voullez ajouter:  ");
    scanf("%d",&n);
ToDo t[n];

///////////////////AddToDO(&t);
    AddToDoList(t,n);
//////////////////  Affichage avant triage
//avant triage par titre
    // printf("\t Avant le triage \n");
DisplayList(t,n);
////////////////////////Affichage apres triage
//apres triage par titre
    // printf("\t Apres le triage \n");
    // ToDoSort(t,n);
    // DisplayList(t,n);
/////////////////// chercher une tache par id
//////////////////saisir id que vous voullez chercher
    // printf("entrer l'identifiant que vous voullez trouver dans la liste:");
    // scanf("%d",&identifiant);
///// ///   Appel de fonctions Search 
    // par id
          //search_id=SearchById(t,n,identifiant);
          // printf("l'identifiant %d se trouve à la position %d \n",identifiant,search_id);
    // par titre
          // printf("entrer le titre que vous voullez trouver dans la liste:");
          // scanf("%s",title);    
    // search_title=SearchByTitle(t,n,title);
    // printf("le titre %s se trouve à la position %d \n",title,search_title);

////// Modifier description d'une tache par son id 
      // //saisie la description que vous voullez modifier
      //   printf("saisir la description:  ");
      //   scanf("%s",describe);
//ModifDesc(t,n,identifiant,describe);
      //saisie la description que vous voullez modifier
        //printf("saisir le status:  ");
        //scanf("%s",status);
        //ModifStatus(t,n,identifiant,status);
//Suppression d'une tache
//printf("entrer l'identifiant que vous voullez supprimer dans la liste:");
//scanf("%d",&identifiant);
//DeleteById(t, n, identifiant); 
//DisplayList(t,n);

//time_t newDeadline = time(NULL) + (5 * 24 * 60 * 60); // Nouvelle deadline : dans 5 jours




}
