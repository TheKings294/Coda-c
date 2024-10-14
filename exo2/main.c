#include "exo2.h"

int main() {
  number *liste = NULL;

  liste = num_new(42);
  add_to_end(&liste, 28);
  add_to_end(&liste, 36);
  add_to_end(&liste, 13);
  add_to_end(&liste, 91);
  add_to_end(&liste, 152);
  add_to_end(&liste, -7);

  affichlist(&liste);

  printf("J'ajoute 47 apres 91\n");

  add47(&liste);
  affichlist(&liste);

  delet(&liste);
  return 0;
}