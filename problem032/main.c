#include <stdio.h>
#include <time.h>


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
	char str[10];
	int n =	snprintf(str,5,"%d",12315);
	printf("%d|%s\n", n,str);	

	return 0;
}
