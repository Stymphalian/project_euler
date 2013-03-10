#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "convertNumToStr.h"


int foo(double number, int power);
int solve(int power);

int main(){
	printf("Project Euler: Problem 30 fifths exponent\n");
	clock_t time = clock();

	int power = 4;
	printf("power = ");
	scanf("%d",&power);

	int rs = solve(power);
	printf("solve(%d) = %d\n",power, rs);

	printf("sys ( %5f s)\n", (double)(clock() -time)/CLOCKS_PER_SEC);
	return 0;
}



int foo(double number, int power)
{
	static double deltaError =  0.00001;

	char* num_str = convertNumToStr_double(number);	
	int len = strlen(num_str);
	int i;
	double sum =0;
	for( i = 0; i < len ; ++i)
	{
		sum += pow(num_str[i]-'0',power);	
	}

	free(num_str);
	return (sum <= number + deltaError && sum >= number - deltaError); 
}

int solve(int power)
{
	if( power <= 0 ) { return -1;}
		
	double i;
	double max = pow(9,power)*(power+1);
	double sum = 0;


	for( i = 2; i < max; ++i)
   	{
		if( foo(i,power) )
		{
			sum += i;
		}
	}
	return sum;
}
