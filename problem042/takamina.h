#ifndef TAKAMINA_H
#define TAKAMINA_H

#include <stdio.h>
#define LIBN(name) my_##name

/* string_utils.c */
char* LIBN(convertIntToString) (int num);

/* getline.c */
int LIBN(getline) (char** line, unsigned* lineSize,FILE* file);


/* math_utils.c*/
int LIBN(isPalindromic_BaseN)(int num, int base);
int LIBN(isPalindromic) (int* seq, unsigned len);
int LIBN(isPrime) (unsigned num);

unsigned LIBN(numDigits_unsigned)(unsigned num);
unsigned LIBN(magnitude_unsigned)(unsigned num);

int LIBN(numDigits_int)(int num);
int LIBN(magnitude_int)(int num);


unsigned LIBN(factorial)(int num);
int LIBN(reduceFraction) (int n,int d, int* n2, int* d2);

/* pandigitial.c */
int LIBN(isPandigital_n_to_m) (int n,int m, unsigned num);


/* permutations.c */
int LIBN(permutations) (int* set, int setlen, int permlen, void* obj,
				 int (*callback) (int* perm,int permlen,void* obj));

/* subsets.c */
int LIBN(subsets) (int* set, int setlen,void* obj,
				   int (*callback) (int* set,int len,void* obj));


/* split_line.c */
char** LIBN(split_line)(char* line, int* array_len, char* split_chars);
#endif
