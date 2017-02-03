/*
There are  strings. Each string's length is no more than  characters. There are also  queries. For each query, you are given a string, and you need to find out how many times this string occurred previously.

Input Format

The first line contains , the number of strings.
The next  lines each contain a string.
The nd line contains , the number of queries.
The following  lines each contain a query string.

Constraints
Sample Input

4
aba
baba
aba
xzxb
3
aba
xzxb
ab
Sample Output

2
1
0
Explanation
Here, "aba" occurs twice, in the first and third string. The string "xzxb" occurs once in the fourth string, and "ab" does not occur at all.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, q;
    char** str_arr;
    char** q_arr;
    scanf("%d", &n);
    int count=0;
    str_arr = (char**)malloc(n*sizeof(char*));
    for(int i=0; i<n; i++) {
        *(str_arr+i) = (char*)malloc(21*sizeof(char));
        scanf("%s", *(str_arr + i));
    }
    scanf("%d", &q);
    q_arr = (char**)malloc(q*sizeof(char*));
    for(int i=0; i<q; i++) {
        *(q_arr+i) = (char*)malloc(21*sizeof(char));
        scanf("%s", *(q_arr + i));
    }
    
    for(int i=0; i<q; i++) {
        count =0;
        for(int j=0; j<n; j++) {
            if(strcmp(*(q_arr+i), *(str_arr+j)) == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}

