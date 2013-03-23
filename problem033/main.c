#include <stdio.h>
#include <time.h>

int d( int n1, int n2, int num, int den);
void reduceFraction(int* num, int* den);
int convertNumToStr(char* array, int cap, int num);
int solve();

int main(){
	printf("Project Euler | Problem 33 | Digit Cancelling Fractions\n");
	clock_t time = clock();

	int rs = solve();
	printf("solve() = %d\n",rs);


	printf("sys (%5f s)\n", (double)(clock() - time)/CLOCKS_PER_SEC);
	return 0;
}


int solve(){
	int i,j;
	int num, den;
	int numer = 1;
	int denom = 1;

	for( i = 10; i < 100; ++i){
		for( j = i+1; j < 100; ++j){
			
			num = i;
			den = j;
			reduceFraction(&num,&den);

			if( d(i,j,num,den)) {
				numer = num*numer;
				denom = den*denom;
			}	
		}
	}

	reduceFraction(&numer,&denom);
	return  denom;
}




int d(int n1, int n2, int num, int den){
	if( n1%10 == 0 && n2%10 == 0) {return 0;}
	int len1=0;
	int len2=0;
	char num1[3];
	char num2[3];

	len1 = convertNumToStr(num1,3,n1);
	len2 = convertNumToStr(num2,3,n2);
	int n,d;

	if( len1 != 2 || len2 != 2){ return 0;}

	if( num1[0] == num2[0] ){
		n = num1[1] -'0';
		d = num2[1] - '0';
		if( n*den == d*num ){
			printf("%d/%d = %d/%d = %d/%d\n",n,d,num,den,n1,n2);
			return 1;
		}
	}
	if( num1[0] == num2[1]){
		n = num1[1] -'0';
		d = num2[0] - '0';
		if( n*den == d*num ){
			printf("%d/%d = %d/%d = %d/%d\n",n,d,num,den,n1,n2);
			return 1;
		}
	}
	if( num1[1] == num2[0]){
		n = num1[0] -'0';
		d = num2[1] - '0';
		if( n*den == d*num ){
			printf("%d/%d = %d/%d = %d/%d\n",n,d,num,den,n1,n2);
			return 1;
		}

	}
	if( num1[1] == num2[1]){
		n = num1[0] -'0';
		d = num2[0] - '0';
		if( n*den == d*num ){
			printf("%d/%d = %d/%d = %d/%d\n",n,d,num,den,n1,n2);
			return 1;
		}
	}
	return 0;
	
}

void reduceFraction(int* num, int* den){
	if( !num || !den){return;}
	if( *num == 0){return;}
	if( *num >= *den ){return;}

	int i;
	for( i = 2; i < *den;++i){
		if( *den%i == 0 && *num%i == 0){
			*num = *num/i;
			*den = *den/i;
			reduceFraction(num,den);
			return;
		}
	}
	return;

}


int convertNumToStr(char* array, int cap, int num){
	int n = snprintf(array,cap,"%d",num);
	array[n] = '\0';
	return n;
}
