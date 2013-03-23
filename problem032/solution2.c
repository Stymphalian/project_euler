#include <stdio.h>
#include <time.h>
#include <string.h>

int convertNumToStr(char* array,int cap,int num);
int checkCondition(char* multiplicand, char* multiplier, char* product);
int solve();

int main()
{
	printf("Project Euler | Problem 32 | Pandigital Numbers\n");
	clock_t time = clock();

	int rs = solve();
	printf("sovle() = %d\n", rs);

	printf("sys (%5f s)\n", (double)(clock() - time)/ CLOCKS_PER_SEC);
	return 0;
}


int solve()
{

	int i;
	int j;
	int cap = 30;
	int sum = 0;
	int max = 10000;
	char multiplicand[cap];
	char multiplier[cap];
	char product[cap];


	int index = 0;
	int array[max];
	int n1, n2, n3;

	int x;
	int flag ;

	for( i =1 ; i <= 99; i++ ){
		for( j = 1000; j <= 9999; j++){
			n1 = convertNumToStr(multiplicand,cap,i);
			n2 = convertNumToStr(multiplier,cap,j);
			n3 = convertNumToStr(product,cap,i*j);

			if( n1 + n2 + n3 != 9){
				continue;
			}


			if(checkCondition(multiplicand, multiplier, product)){
				printf("%s\n", product);
				flag  = 0;
				for(x = 0; x < index; ++x){
					if( i*j == array[x]){
						flag = 1;
						break;
					}
				}

				if(flag) {continue;}
				array[index++] = i*j;
				sum += i*j;
			}
		}

	}



	for( i =10 ; i <=99 ; i++ ){
		for( j = 100; j <= 999; j++){
			n1 = convertNumToStr(multiplicand,cap,i);
			n2 = convertNumToStr(multiplier,cap,j);
			n3 = convertNumToStr(product,cap,i*j);

			if( n1 + n2 + n3 != 9){
				continue;
			}


			if(checkCondition(multiplicand, multiplier, product)){
				printf("%s\n", product);
				flag  = 0;
				for(x = 0; x < index; ++x){
					if( i*j == array[x]){
						flag = 1;
						break;
					}
				}

				if(flag) {continue;}
				array[index++] = i*j;
				sum += i*j;
			}
		}

	}

	return sum;
}



int checkCondition(char* multiplicand, char* multiplier, char* product){
	int i;
	int d;
	int digits[10] = {0,0,0,0,0,0,0,0,0,0};
	

	int len = strlen(multiplicand);
	for( i = 0 ; i < len; ++i) {
		d = multiplicand[i] - '0';
		if( d == 0) {return 0;}
		if( digits[d] == 1) {return 0;}
		digits[d] = 1;

	}

	len = strlen(multiplier);
	for( i = 0; i < strlen(multiplier); ++i){
		d = multiplier[i] - '0';
		if( d == 0) {return 0;}
		if( digits[d] == 1) {return 0;}
		digits[d] = 1;

	}

	len  = strlen(product);
	for( i = 0 ; i < strlen(product); ++i){
		d = product[i] - '0';
		if( d == 0) {return 0;}
		if( digits[d] == 1) {return 0;}
		digits[d] = 1;
	}

	
	for( i = 1; i <= 9; i++){
		if(digits[i] == 0){
			return 0;
		}
	}
	return 1;
}


int convertNumToStr(char* array,int cap,int num){
	int n =	snprintf(array,cap-1,"%d",num);
	array[n]= '\0';
	return n;
}
