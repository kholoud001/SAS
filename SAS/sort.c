#include<stdio.h>
#include<time.h>
#include<string.h>

//TO DO struct
typedef struct ToDo{
  int id;
  char titre[20],description[50],status[10];
  double deadline;
} ToDo;


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



int main(){

int n;
//la saisie du nombre des taches que vous voullez ajouter
printf("entrer le nombre des taches que vous voullez ajouter:  ");
scanf("%d",&n);
ToDo t[n];

//AddToDO(&t);
AddToDoList(t,n);
printf("\t Avant le triage \n");
DisplayList(t,n);
printf("\t Apres le triage \n");
ToDoSort(t,n);
DisplayList(t,n);


}
