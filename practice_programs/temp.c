#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, q;
    char** str_arr;
    char** q_arr;
    int i, j;
    scanf("%d", &n);
    int count=0;
    str_arr = (char**)malloc(n*sizeof(char*));
    for(i=0; i<n; i++) {
        *(str_arr+i) = (char*)malloc(21*sizeof(char));
        scanf("%s", *(str_arr + i));
    }
    scanf("%d", &q);
    q_arr = (char**)malloc(q*sizeof(char*));
    for(i=0; i<q; i++) {
        *(q_arr+i) = (char*)malloc(21*sizeof(char));
        scanf("%s", *(q_arr + i));
    }
    
    for(i=0; i<q; i++) {
        count =0;
        for(j=0; j<n; j++) {
            if(strcmp(*(q_arr+i), *(str_arr+j)) == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
/*
typedef struct
{
        int n;
        int *key;
}Node;

void print(Node node)
{
	int i;
	int a[4] = {5,6,7,8};
	node.key = a;
	for(i=0;i<node.n;i++)
	{
		printf("%d\t", node.key[i]);
	}
	printf("\n");
}

void main()
{
int i;
Node node;
node.n = 4;
node.key = (int *)calloc(4, sizeof(int));

for(i=0;i<node.n;i++)
{
	node.key[i] = i+1;
}

print(node);

}
*/
/*
void check(int** pptr)
{
	int* ptr = *pptr;
	int *newptr = (int*)malloc(sizeof(int));
	*newptr = 5;
	ptr = newptr;
}

void main()
{
	int i=10;
	int *ptr= NULL;
	check(&ptr);
	printf("%d %d\n", i, *ptr);
}
*/


