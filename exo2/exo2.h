#ifndef EXO2_H
#define EXO2_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_number number;

struct s_number {
    int value;
    number *next;
};

number *num_new(int nume);
void delet(number **nume);
void add_to_end(number **list, int number);
void add47(number **list);
void affichlist(number **list);

#endif