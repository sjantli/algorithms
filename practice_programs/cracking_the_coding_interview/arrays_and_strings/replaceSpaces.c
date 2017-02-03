#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void replaceSpaces(char* str) {
    int len, newlen, space_count;
    len = newlen = space_count = 0;
    len = strlen(str);
    for (int i=0; i<len; i++) {
        if (str[i] == ' ') {
            space_count++;
        }
    }
    newlen = len + (2 * space_count);
    str[newlen] = '\0';
    for (int i=len-1; i>=0; i--) {
        if (str[i] == ' ') {
            str[newlen - 1] = '0';
            str[newlen - 2] = '2';
            str[newlen - 3] = '%';
            newlen = newlen - 3;
        } else {
            str[newlen - 1] = str[i];
            newlen--;
        }
    }
}

int main() {
	int maxlen;
	char* str = NULL;
	printf("enter the max length of string\n");
	scanf("%d", &maxlen);
    printf("maxlen of string is %d\n", maxlen);
    // allocate 3 times maxlen, assuming worst case all the characters are spaces.
	str = (char*)malloc(sizeof(char)*(maxlen*3)+1);
	printf("enter the string\n");
    scanf("\n%[^\n]", str);
    printf("old string: %s\n", str);
    replaceSpaces(str);
    printf("new string: %s\n", str);
}

