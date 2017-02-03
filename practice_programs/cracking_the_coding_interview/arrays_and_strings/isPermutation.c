#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// write another version by sorting and then comparing both strings

// This just iterates through each string once and maintains additional space 
//and compares the count of letters in both strings if same or not.
bool isPermutation(char* s1, char* s2) {
	int arr[256], i, l1,l2;
	char temp;
	if ((l1 = strlen(s1)) != (l2 = strlen(s2))) {
		return false;
	}
	for (i = 0; i < 256; i++) {
		arr[i] = 0;
	}
	for(i=0; i < l1; i++) {
		temp = *(s1+i);
		arr[temp]++;
	}

	for(i = 0; i < l2; i++) {
		temp = *(s2+i);
		if (--arr[temp] < 0) {
			return false;
		}
	}
	return true;
}

int main() {
//use %ms in scanf or use fgets to input a string of arbitrary length in c
	// somehow using [^\n] or [^\t] in scanf is giving weird results and not scaning the inputs properly.
	// so either use without that just %ms which will not accept whitespace or input using the malloc by getting length and
       // accepting inputs of less than that length 	
	/*
	int maxlen;
	char* s1 = NULL;
	char* s2 = NULL;
	printf("enter the max length of two strings\n");
	scanf("%d", &maxlen); 
	s1 = (char*)malloc(sizeof(char)*maxlen);
	s2 = (char*)malloc(sizeof(char)*maxlen);
	*/
	char* s1 = NULL;
	char* s2 = NULL;
	printf("enter string1\n");
	scanf("%ms", &s1);
	printf("enter string2\n");
	scanf("%ms", &s2);
	/*
	printf("enter string1\n");
	scanf("%s", s1);
	printf("enter string2\n");
	scanf("%s", s2);
	*/
	if (isPermutation(s1, s2)) {
		printf("strings are anagrams\n");
	} else {
		printf("strings are not anagrams\n");
	}

}

