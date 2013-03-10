#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "convertNumToStr.h"


#define MAXDECIMALS 1000


int compareInts(const void* key, const void* elem);
int magnitudeOfInt(int num);
int checkAndExpandIfNecessary(char** array, int* cap, int current);
char* findDecimal(int n, int d,int* repeatPoint);
int solve(int limit);

int main(){
	printf("Project Euler: Problem 26\n");
	clock_t time = clock();


	int limit = 1000;
	int rs = solve(limit);
	printf("solve(%d) = %d\n",limit, rs);

	printf("sys ( %5f s)\n", (double)(clock() -time)/CLOCKS_PER_SEC);
	return 0;
}




int checkAndExpandIfNecessary(char** array,int* cap,int current){
	if( !array || !*array|| !cap ){return 0;}
	if(current >= *cap){
		*array = realloc(*array,sizeof(char)*(*cap)*2);
		if(*array == NULL){return 0;}
		*cap = 2*(*cap);
	}
	return 1;
}



int magnitudeOfInt(int num){
	int power = 1;
	while(power*10 < num){power *= 10;}
	return power;
}

int compareInts(const void* key, const void* elem){
	return *(int*)key - *(int*) elem;
}

int isInArray(int* array, int len, int key){
	int i;
	for(i=0 ; i < len; ++i){
		if( key == array[i] ){
			return i;
		}
	}
	return -1;
}



char* findDecimal(int _n, int _d, int* repeatPoint){
	if(_d == 0) {return NULL;} /* can only deal with +ve, non-zero denom fractions */
	int n = (_n < 0) ? -_n : _n;
	int d = (_d < 0) ? -_d : _d;
	int flag =0;
	*repeatPoint = -1;

	int cap = MAXDECIMALS;
	int pos = 0;
	char str[MAXDECIMALS];
	if( _n*_d < 0 ){ str[pos++] = '-' ;}


	/* Extract the whole number of denominators from the numerator */
	if( n >= d ){

		/* copy the string rep of the whole number into str */
		char* str_whole = convertNumToStr((int)n/d);
		if(!str_whole) {return NULL;}
		if( pos + strlen(str_whole) >= cap ){return NULL;}

		memcpy(str + pos, str_whole, sizeof(char)*strlen(str_whole));
		pos = pos + strlen(str_whole); /* pos + strlen in order to account for -ve sign */
		free(str_whole);

		flag =1;
		n = n%d;	
	}

   	 /* handle the decimal portion of the fraction, showing only a single repeated cycle */
	int refs[MAXDECIMALS];
	int cnt  =0;

	if( n != 0  && n < d){
		if(!flag){str[pos++] = '0';} /* for the case in which there are 0 whole numbers */
		str[pos++] = '.'; /* add the decimal point*/

		int temp = 0;
		refs[cnt++] = n;
		while(n*10 < d ){
			n*= 10;
			if( pos >= cap ){
				return NULL;
			}
			str[pos++] = '0';
			++temp;
		}

		do{
			if(pos >= cap){return NULL;}
			if(cnt >= MAXDECIMALS){return NULL;}

			refs[cnt++] = n; /* add it to the reference numbers */
			if( n < d) {n *= 10;}

			str[pos++] = ((int)n/d) + '0';
			n = n%d;

		}while(n !=  0 && cnt < MAXDECIMALS && pos < cap && isInArray(refs, cnt,n) < 0);
		*repeatPoint = isInArray(refs,cnt,n)  + temp;
	}
	str[pos] = '\0';

	char* rs  = malloc(sizeof(char)* (strlen(str) +1));
	memcpy(rs, str, sizeof(char)* (strlen(str) +1 ));
	return rs;
}



int solve(int limit){
	int i;
	char* str;
	int max = 1;
	int maxcount = -1;
	int repeatPoint = 0;


	for( i = 2; i<= limit; ++i){
		str = findDecimal(1,i,&repeatPoint);	
		if(!str){return -1;}
		if(repeatPoint == -1){continue;}

		int len = strlen(str) - repeatPoint;
		if(len > maxcount){
			max = i;
			maxcount = len;
		}
		free(str);
	}
	return max;
}
