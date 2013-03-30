#ifndef TAKAMINA_H
#define TAKAMINA_H

#include <stdio.h>


/* my_string_utils.c */
char* convertIntToString(int num);

/* my_getline.c */
int my_getline(char** line, unsigned* lineSize,FILE* file);


/* my_math_utils.c*/
int isPrime(unsigned num);

unsigned numDigits_unsigned(unsigned num);
unsigned magnitude_unsigned(unsigned num);

int numbDigits_int(int num);
int magnitude_int(int num);


unsigned factorial(int num);
int reduceFraction(int n,int d, int* n2, int* d2);


/* my_math_permutations.c */
int permutations(int* set, int setlen, int permlen, int (*callback) (int* perm,int permlen) );




#endif
