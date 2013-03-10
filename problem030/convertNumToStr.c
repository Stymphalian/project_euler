#include <stdlib.h>
#include <math.h>
#include "convertNumToStr.h"



/*Return NULL or a null terminated string */
char* convertNumToStr(int num){
	/* preparing everything */
	int len1=1;
	int power=1;
	int negFlag =0;
	
	if(num <0 )	{negFlag++;num = -num;}
	while( power*10 <= num){
		power = power*10;
		len1++;
	}
	char* str = malloc( sizeof(char) * (len1 + negFlag +1 ));
	if( str == NULL){return NULL;}
	if( negFlag) { str[0] = '-';}


	/* conversion */
	int i ;
	for(i =negFlag; i < len1+negFlag ; ++i){
		str[i] = '0' + num/power;
		num = num - (num/power)*power;
		power = power/10;	
	}
	str[len1 + negFlag] = '\0';

	return str;	
}



/* Return NULL or a null terminated string */
char* convertNumToStr_double(double num){
	/* preparing everything */
	double	 	power=1;
	int			negFlag =0;
	int 		len=1;
	
	if(num < 0 )	
	{
		++negFlag;
		num = -num;
	}

	while( power*10 <= num)
	{
		power = power*10;
		++len;
	}

	char* str = malloc( sizeof(char) * (len + negFlag +1 ));
	if( str == NULL){return NULL;}
	if( negFlag) { str[0] = '-';}


	/* conversion */
	int i ;
	for(i =negFlag; i < len+negFlag ; ++i)
	{
		str[i] = '0' + floor(num/power);
		num = num - (str[i]-'0')*power;
		power = power/10;	
	}
	str[len + negFlag] = '\0';

	return str;	
}
