#ifndef BOOLEAN_H
#define BOOLEAN_H

#include <stdio.h>
#include <unistd.h>

typedef enum
{
  TRUE = 1,
  FALSE = 0
} t_bool;

#define EVEN(nbr) ((nbr) % 2 == 0)

#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"
// by convention, main returns 0 on a successful execution
#define SUCCESS 0

#endif
