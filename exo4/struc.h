#ifndef __STRCT_H__
#define __STRCT_H__

struct s_char
{
    char *name;
    int strength;
    int intelligence;
    int wisdom;
    int agility;
    int endurance;
};

typedef struct s_char character;

#endif