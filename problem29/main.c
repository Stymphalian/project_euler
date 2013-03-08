#include <stdio.h>
#include <time.h>
#include <math.h>


int solve(int limita, int limitb){
	double number;
	int count= 0;
	double array [limita * limitb];
	int len = 0;


	int flag = 0;
	int i;
	int a;
	int b;
	for( a = 2; a <= limita; ++a)
	{
		for( b = 2 ; b <= limitb; ++b)
		{
			flag =0;	
			number = pow(a,b);

			/* is the number a repeat? */
			for( i = 0; i < len ; ++i)
			{	
				if( array[i] == number)
				{
					flag =1;
					break;
				}

			}

			if(flag == 0)
			{
				array[len++] = number;	
				++count;
			}
		}
	}
	return count;
}

int main(){
	printf("Project Euler Problem 29 distinct powers\n");
	clock_t time = clock();

	int a = 100;
	int b = 100;	
	int rs = solve(a,b);


	printf("solve(%d,%d) = %d\n", a,b, rs);
	printf("sys (%5f s)\n", (double)(clock() - time)/CLOCKS_PER_SEC);
	return 0;
}
