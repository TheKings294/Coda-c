#include "exo3.h"

number *num_new(int nume) {
    number *first = malloc(sizeof(number));
    first->value = nume;
    first->next = NULL;

    return first;
}

void delet(number **nume) {
    number *tmp = *nume;
    while (tmp != NULL) {
        number *to_delete = tmp;
        tmp = tmp->next;
        free(to_delete);
    }
}

void add_to_end(number **list, int num) {
    number *tmp = *list;

  if(tmp->value > num) {
        number *to_add = malloc(sizeof(number));
        to_add->value = num;
        to_add->next = tmp;
        *list = to_add;
    }

    while (tmp->next != NULL) {
      if(tmp->value < num && tmp->next->value > num) {
      number *ttmp = tmp->next;
        number *to_add = malloc(sizeof(number));
        to_add->value = num;
        tmp->next = to_add;
        to_add->next = ttmp;
        return;
    }
      tmp = tmp->next;
    }

    if(tmp->value < num) {
       number *to_add = malloc(sizeof(number));
        to_add->value = num;
        to_add->next = NULL;
        tmp->next = to_add;
    }
}

void add47(number **list) {
    number *tmp = *list;

    while (tmp->value != 91) {
        tmp = tmp->next;
    }

    number *to_add = malloc(sizeof(number));
    to_add->value = 47;
    to_add->next = NULL;

    to_add->next = tmp->next;
    tmp->next = to_add;

}

void affichlist(number **list) {
    number *tmp = *list;

    while (tmp != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}