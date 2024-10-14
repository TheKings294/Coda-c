#include "exo3.h"

int main() {
  int nb;
  int choixuser;
  int fin = 0;
  number *liste = NULL;

    printf("Choisir le premier nombre\n");
    scanf("%d", &nb);
    liste = num_new(nb);

   while (fin == 0) {
     choixuser = 0;
       printf("Que souhaitez-vous faire ?\n");
       printf("Ajouter un nombre : (1)\n");
       printf("Afficher la liste : (2)\n");
       printf("Quitter le programme : (3)\n");
       printf("Effacer l'écran : (4)\n");
       scanf("%d", &choixuser);
       choix(choixuser, &fin, &liste);
   }

  delet(&liste);
  return 0;
}