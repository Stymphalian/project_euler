#include <stdio.h>
#include <math.h>
#include <time.h>

unsigned getMask(int num);
int isPan(int m, int num);
unsigned getNum(int m, int num);
int isPandigital_n_to_m(int n, int m, int num);
unsigned solve(int n);

int main(){
	clock_t time = clock();
	printf("Project Euler | Problem 38 | Pandigital Mulitples \n");

	int n = 0;
	int rs = solve(n);
	printf("solve(%d)= %u\n", n,rs);


	printf("sys (%5f s)\n", (double)(clock()- time) / CLOCKS_PER_SEC);
	return 0;
}


unsigned solve(int n){
	unsigned max = 0;
	int m;
	int i;

	for( m = 2; m <=9 ; ++m){	
		for( i = 1 ; i < 10000; ++i){
			if( isPan(m,i) ){
				unsigned cand = getNum(m,i);
				if( cand > max){
					max = cand;
				}
			}
		}
	}
	return max;
}

int isPan(int m, int num){
	int array[10] = {0,1,1,1,1,1,1,1,1,1};
	int mask[10];
	int j;
	for( j =0; j < 10; ++j){
		mask[j] = 0;
	}

	int temp;
	int d;


	/* fill the mask */
	for(j = 1; j <= m; ++j){
		temp = j*num;

		do{
			d = temp%10;	
			mask[d] +=1;
			temp = temp/10;
		}while(temp);
	}

	/* make sure the masks match */
	for( j = 0; j < 10; ++j){
		if( mask[j] != array[j]) {
			return 0;
		}
	}
	return 1;

}


unsigned getNum(int m, int num){
	unsigned rs =0;

	int i ;
	unsigned temp;
	unsigned power =1;
	for(i = m; i >=1; --i){
		temp = num*i;
		do{
			rs += power*(temp%10);
			power = power*10;
			temp = temp/10;
		}while(temp);
	}
	return rs;
}


unsigned getMask(int num){
	unsigned mask=0;
	int d;
	do{
		d= num%10;	
		mask = mask | ( 1 << d );
		num = num/10;
	}while(num);
	return mask;
}

int isPandigital_n_to_m (int n, int m, int num){
	if( num< 0){ num = -num;}
	if( n > m ){return 0;}
	if( n <0 || n > 9){return 0;}
	if( m <0 || m > 9){return 0;}

	unsigned target_mask= 0;
	unsigned mask = 0;		
	int d;

	/* create the target mask */
	for(d = n; d <= m; ++d){
		target_mask = target_mask | (1 <<d ) ;
	}

	/* form the number's mask*/
	do{
		d = num%10;
		if( (mask & (1<<d) ) != 0 ) {return 0;} /* each digit only once */
		mask = mask | ( 1 << d );
		num = num/10;
	}while(num);

	return target_mask == mask;
}

