#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// fixed size stacks
#define stacksize 5
int buffer[stacksize*3];
int stackptr[3] = {-1, -1, -1};

void push(int stacknum, int item);
int pop(int stacknum);
int peek(int stacknum);
int isEmpty(int stacknum);
int absTopOfStack(int stacknum);
void printStack(int stacknum);

void printStack(int stacknum) {
    int i;
    for (i = (stacksize*stacknum); i <= absTopOfStack(stacknum); i++) {
        printf("%d\t", buffer[i]);
    }
    printf("\n");
}

void push(int stacknum, int item) {
    if (stackptr[stacknum] + 1 >= stacksize) {
        printf("\n out of space\n");
        return;
    }
    stackptr[stacknum]++;
    buffer[absTopOfStack(stacknum)] = item;
}

int pop(int stacknum) {
    if (stackptr[stacknum] == -1) {
        printf("\n no elements\n");
        return -1;
    }
    int item = buffer[absTopOfStack(stacknum)];
    buffer[absTopOfStack(stacknum)] = 0;
    stackptr[stacknum]--;
    return item;
}

int peek(int stacknum) {
    return buffer[absTopOfStack(stacknum)];
}

int isEmpty(int stacknum) {
    return (stackptr[stacknum] == -1);
}

int absTopOfStack(int stacknum) {
    return ((stacksize * stacknum) + stackptr[stacknum]);
}

void main() {
   push(0, 1);
   push(0, 2);
   push(0, 3);
   push(0, 4);
   push(0, 5);
   push(0, 6);
   push(1, 1);
   push(2, 1);
   push(2, 2);
   push(1, 2);
   push(0, 6);
   printStack(0);
   printStack(1);
   printStack(2);
   printf("pop(0)%d\n", pop(0));
   push(0, 6);
   printf("is empty(2): %d\n", isEmpty(2));
   printf("pop(2)%d\n", pop(2));
   printf("pop(2)%d\n", pop(2));
   printf("is empty(2): %d\n", isEmpty(2));
   printf("pop(2)%d\n", pop(2));
   printf("peek(1) : %d\n", peek(1));
   printStack(0);
   printStack(1);
   printStack(2);
}
