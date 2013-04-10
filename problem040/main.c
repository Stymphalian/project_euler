#include <stdio.h>
#include <time.h>

int solve(int* places, int len);
int main(){
	clock_t time = clock();
	printf("Project Euler | Problem 40  | Concatenating Irrational Number number \n");

	int places[7] = {1,10,100,1000,10000,100000,1000000};
	int len = 7;

	int rs  = solve(places,len);
	printf("solve(%x,%d) = %d\n", places,len,rs);

	printf("sys (%5f s) \n", (double)(clock() - time) / CLOCKS_PER_SEC);

	return 0;
}


int length(unsigned n){
	int len = 0;
	do{
		++len;
		n = n/10;
	}while(n);
	return len;
}

unsigned magnitude(unsigned n){
	unsigned mag =1;
	while(mag*10 <= n){
		mag*=10;
	}
	return mag;
}


/* returns the position of the last digit of the number in the sequence */
unsigned foo(unsigned n){
	int len = length(n);
	unsigned mag = magnitude(n);
	unsigned pos = 0;


	unsigned power = 1;
	int temp_len  = 1;

	while(temp_len < len){
		pos += 9*power * temp_len;

		power *= 10;
		++temp_len;
	}


	pos +=  len*(n - (mag-1));
	return pos;
}


unsigned goo(unsigned pos){
	if( pos >= 0 && pos <= 9){
		return pos;
	}


	unsigned num = pos;
	unsigned power = 1;
	int len = 1;

	/* remove all the 9*len values */
	for(;;){
		if( (9*power*len) >= num){
			break;
		}
		num = num - ( (9*power)*len);
		power*=10;
		++len;
	}

	/* the position in the len-digit number */
	int position = num%len;

	num = num/len;
	/* round it off to the nearest number */
	if( position != 0){
		num += 1;	
	}

	/* get the actual number */
	num += (power-1);

	/* get the correct digit */
	int digit = -1;
	int temp = num;
	int target = (position == 0) ? len-1 : position-1;
	int i =  len-1;


	for(i = len-1;i>= 0;--i){
		digit = temp%10;
		temp = temp/10;
		if( i == target ){
			return digit;
		}
	}

	return digit;
}


int solve(int* place, int len){
	int rs = 1;
	int i;

	for(i = len-1; i>= 0; --i){
		rs  = rs*goo(place[i]);
	}
	return  rs;

}

int test(int* places, int len){


	int i ;
	int array[1500];
	int pos = 0;
	int num;

	for( i = 200; i>0; --i){
		num =i;
		do{
			array[pos++] = num%10;
			num = num/10;
		}while(num);
		
	}


	int d = 1;
	for( i = pos-1; i>= 0;--i){
		printf("%3d,%3d\n", d++, array[i]);
	}


	for( i = 1; i < 250; ++i){
		printf("%d | %u | %u\n",i,foo(i),goo(i));
	}

	int a = foo(2374);
	printf("%d,%d%d%d%d\n",a, goo(a-3), goo(a-2), goo(a-1), goo(a));

	return 0;
}
