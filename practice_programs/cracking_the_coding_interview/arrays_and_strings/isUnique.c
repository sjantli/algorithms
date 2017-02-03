#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool isUnique(char* str)
{
	bool arr[256];
	int len = strlen(str);
	
	if (len > 256) {
		return false;
	} else {
		for(int i = 0; i < 255; i++) {
			arr[i] = false;
		}
		// we can either use length of string or check for null char in string as follows(length would be more safe I guess)
	//	while(len > 0) {
		while(*str) {
			char c = *str;
			if (arr[c] != false) {
				return false;
			} else {
				arr[c] = true;
			}
			str++;
		//	len--;
		}
	}
	return true;
}

int main() {
//use %ms in scanf or use fgets to input a string of arbitrary length in c
	char* str;
	int len;
	printf("enter the string\n");
	scanf("%m[^\n]s", &str);
	len = strlen(str);
	printf("string is : %s and length: %d\n", str, len);
	//gets(str);
	if (isUnique(str)) {
		printf("string is unique\n");
	} else {
		printf("string is not unique\n");
	}
}
