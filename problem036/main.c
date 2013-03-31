#include <stdio.h>
#include <time.h>

int lenOfNum(int num);
int isPalindromic(int* seq, int len);
int isPalindromic_BaseN(int num, int base);
int isPalindromic_Base10(int num);
int isPalindromic_Base2(int num);
int solve( int limit);

int main(){
	clock_t time = clock();
	printf("Project Euler | Problem 36 | double palindromic numbers \n");

	int limit = 1000000;
	int rs = solve(1000000);
	printf("solve(%d) = %d\n", limit, rs);


	printf("sys (%5f s) \n", (double)(clock() - time) / CLOCKS_PER_SEC);
	return 0;
}

int solve(int limit){

	unsigned i;
	int sum =0;
	for( i = 0; i < limit; ++i){
		if( isPalindromic_BaseN(i,10) && isPalindromic_BaseN(i,2) ) {
			sum += i;
		}		
	}
	return sum;
}


int lenOfNum(int num){
	int count = 0;
	do{
		num = num/10;
		++count;
	}while( num);
	return count;
}


int isPalindromic(int* seq, int len){
	int i = 0;
	int j = len-1;

	while( i <= j ){
		if( seq[i++] != seq[j--]){
			return 0;
		}
	}	
	return 1;
}


int isPalindromic_BaseN(int num,int base){
	if( num < 0){ num = -num;}
	if( base < 0) { base = -base;}
	if( base == 0) {return 0;}

	int temp;
	int len;

	/* find the length in base N*/
	len = 0;
	temp = num;
	do{
		++len;
		temp  = temp/base;
	}while(temp);


	/* create the sequence */
	int seq[len];
	int pos = len-1;
	temp = num;
	do{
		seq[pos--] = temp%base;
		temp = temp/base;
	}while(temp);


	/* check for palindromicity */
	int i = 0;
	int j = len-1;

	while( i <= j ){
		if( seq[i++] != seq[j--]){
			return 0;
		}
	}
	return 1;
}


int isPalindromic_Base10(int num){
	int len = lenOfNum(num);	
	int str[len];

	int temp = num;
	int pos =len-1;
	/* create the sequence */
	do{
		str[pos--] = temp%10;
		temp = temp/10;
	}while(temp);

	return isPalindromic(str,len);
}



int isPalindromic_Base2(int num){
	int temp;
	int pos;
	int len;

	/* find the lenght */
	len = 0;
	temp = num;
	do{
		++len;
		temp  = temp/2;
	}while(temp);


	int seq[len];
	pos = len-1;
	temp = num;
	do{
		seq[pos--] = temp%2;
		temp = temp/2;
	}while(temp);


	return isPalindromic(seq, len);
}
