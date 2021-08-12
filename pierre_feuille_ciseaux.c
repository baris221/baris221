#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PIERRE 0
#define FEUILLE 1
#define CISEAUX 2
#define NBESSAIS 3
#define POINTSGAGNANTS 3 

  /* Il sera probablement nécessaire de modifier les parametres et valeur de retour des fonctions 
    choix_ordinateur, choix_joueur, score et jeu */

  /* Les declarations actuelles permettent de compiler et d'executer le programme */

void affichage_objet(int obj){
  
  if (obj == PIERRE){
    printf("ROCK \n");
  } else {
    if (obj == FEUILLE){
      printf("PAPER \n");
    } else {
      printf("SCISSORS \n");
    }
  }
}

int choix_ordinateur() {
  int a;
  a=rand()%3;

  return a;
}

int choix_joueur() {
  int choix;
  int essaie=NBESSAIS;
  while(essaie>0){
  	    scanf("%d",&choix);
  	    if((choix>=0)&&(choix<=2)){
  	   	    return choix;
  	   }
   essaie=essaie-1;
   }
   
   if (essaie==0){
   	    choix=rand()%3;
   }
   
   return choix;
  
}

void score(int *c_score,int *user_score){
  int c_ordi,c_user;
  srand(time(NULL));
  c_ordi=choix_ordinateur();
  c_user=choix_joueur();
  affichage_objet(c_ordi);
  affichage_objet(c_user);
  
  if(c_ordi==c_user){
  	   printf("Score didn't change. \n");
  }
  if(((c_ordi==0)&&(c_user==2))||((c_ordi==1)&&(c_user==0))||((c_ordi==2)&&(c_user==1))){
  	    printf("CPU won 1 point. \n");
  	    *c_score=*c_score+1;  	   
  }
  if(((c_user==0)&&(c_ordi==2))||((c_user==1)&&(c_ordi==0))||((c_user==2)&&(c_ordi==1))){
  	    printf("You won 1 point. \n");
  	    *user_score=*user_score+1;
  }
  printf("CPU score is %d,your score is %d \n",*c_score,*user_score);
  printf("-------------------------------------------------------\n");
  
}


void jeu() {
  int c_score=0;
  int user_score=0;
  
  while((c_score<3)&&(user_score<3)){
  	    score(&c_score,&user_score);
  }
  if(c_score==3){
  	printf("CPU won the game.");
  }
  
  if(user_score==3){
  	printf("User won the game.");
  }
}

int main() {
  printf("Press 0 if you want chose rock. \n");
  printf("Press 1 if you want chose paper. \n");
  printf("Press 2 if you want chose scissors. \n");

  jeu();
  return 0;
}
