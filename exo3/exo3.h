#ifndef EXO3_H
#define EXO3_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_number number;

struct s_number {
    int value;
    number *next;
};

/*Proto*/
void affichlist(number **list);
void add47(number **list);
void add_to_end(number **list, int num);
number *num_new(int nume);
void choix(int a, int *b, number **list);
void delet(number **nume);

#endif