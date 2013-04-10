#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "takamina.h"


void free_array(char** array, int len);
int word_value( char* word);
int isTriangularWord_value(int value);
int isTriangularWord_word(char* word);
int solve(char* filename);

int main(){
	clock_t time = clock();
	printf("Project Euler | Problem 42 | Coded Triangle Numbers \n");

	char* filename = "words.txt";
	int rs = solve(filename);
	printf("solve(%s)=%d\n", filename,rs);

	printf("sys (%5f s)\n", (double)(clock() - time) / CLOCKS_PER_SEC);
	return 0;
}

void free_array(char** array, int len){
	--len;
	while( len >= 0){
		free(array[len--]);
	}
}


int solve(char* filename){
	int count = 0;

	FILE* file = fopen(filename, "r");
	if( !file) {return -1;}
	char* line= 0;
	unsigned line_len=0;

	char** array = 0;
	int array_len = 0;
	int i;

	while( my_getline(&line, &line_len, file) != -1 ){
		array = my_split_line(line,&array_len, " ,\"");
		if( !array) {continue;}

		for( i =0; i < array_len; ++i){
			if( isTriangularWord_word(array[i])){
				++count;
			}
		}
		free_array(array, array_len);
	}

	free(line);
	fclose(file);
	return count;
}

int isTriangularWord_word(char* word){
	return isTriangularWord_value(word_value(word));
}

int isTriangularWord_value(int value){
	int i;
	int fn =0;

	for(i =1;;++i){
		fn = i*(i+1)/2;
		if( fn > value ){
		 	return 0;
		}
		if( fn == value){
			return 1;
		}

	}
	return 0;
}

int word_value(char* word){
	if(!word) { return 0;}
	int len = strlen(word);
	int value = 0;
	int i =0;

	for( i= 0; i < len ; ++i){
		if( word[i] >= 'A' && word[i] <= 'Z' ){
			value += word[i] - 'A' +1;
		}else{
			value += word[i] - 'a' +1;
		}
	}
	return value;
}
