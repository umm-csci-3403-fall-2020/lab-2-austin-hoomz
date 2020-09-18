#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

char *disemvowel(char *str) {
	int len = strlen(str);
	int j = 0;
	char* output;
        output = (char*)calloc(strlen(str)+1, sizeof(char));
	for(int i=0;i<len;i++){
		if(str[i]!= 'a' || str[i]!= 'e' || str[i]!= 'i' || str[i]!= 'o' || str[i]!= 'u' || str[i]!= 'A' || str[i]!= 'E' || str[i]!= 'I' || str[i]!= 'O' || str[i]!= 'U'){
			output[j] = str[i];
			j++;
		}
	}
	output[j] = '\0';
	
  return output;
}
