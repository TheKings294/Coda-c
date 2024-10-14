#include "exo1.h"

num *num_new(int nume) {
    num *first = malloc(sizeof(num));
    first->nume = nume;
    first->next = NULL;

    return first;
}

void delet(num **nume) {
    num *tmp = *nume;
    while (tmp != NULL) {
        num *to_delete = tmp;
        tmp = tmp->next;
        free(to_delete);
    }
}

void add_to_end(num **list, int number) {
    num *tmp = *list;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    num *to_add = malloc(sizeof(num));
    to_add->nume = number;
    to_add->next = NULL;

    tmp->next = to_add;
}

void affichlist(num **list) {
    num *tmp = *list;

    while (tmp != NULL) {
      printf("%d\n", tmp->nume);
      tmp = tmp->next;
      }
}