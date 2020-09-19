#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "disemvowel.h"

bool checkForVowel(char letter){
return( letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||
    letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' );
}
int getNewSize(char *str,int len){
	int count = 0;
	int i;
	for(i=0; i<len; i++){
		if(!checkForVowel(str[i])){
		count++;
		}
	}
	return count;
}
char *disemvowel(char *str) {
	int len = strlen(str);
	char* output;
	
	int newSize = getNewSize(str,len);
        output = (char*)calloc(newSize+1, sizeof(char));
	
	int i,j;
	for(i=0; i<len; i++){	
		if(!checkForVowel(str[i])){
			output[j] = str[i];
			j++;
		}
	}
	output[newSize] = '\0';
	
  return output;
}
