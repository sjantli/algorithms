#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// using regular iterative method
char* reverseString(char* str) {
	char *last, *first;
	first = str;
	char temp;
	int len = strlen(str);
	last = str+(len-1);
	while (str < last) {
		temp = *str;
		*str++ = *last;
		*last-- = temp;
	}
	return first;
}

// using recursive method
void reverseStrRecursive(char* str, int start, int end) {
	char temp;
	if (start >= end) 
		return;

	temp = *(str+start);
	*(str+start) = *(str+end);
	*(str+end) = temp;
	reverseStrRecursive(str, ++start, --end);
}

int main() {
//use %ms in scanf or use fgets to input a string of arbitrary length in c
	char* str;
	int len;
	printf("enter the string\n");
	scanf("%m[^\n]s", &str);
	len = strlen(str);
	printf("string is: %s\t length: %d\n", str, len);
	//gets(str);
	printf("reversed string is: %s\n", reverseString(str));
	reverseStrRecursive(str, 0, len-1);
	printf("recursive reversed string is: %s\n", str);

}

