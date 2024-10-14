#ifndef __EXO1_H__
#define __EXO1_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct s_num num;

struct s_num {
    int nume;
    num *next;
};

/*Prototype des fonctions de chaine*/
num *num_new(int num);
void delet(num **nume);
void add_to_end(num **nume, int num);
void affichlist(num **list);

/*Prototype des fonctions de choix*/
void choix(int a, int *b, num **list);

#endif