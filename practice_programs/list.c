#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int abc = 0;

void xyz() {
    printf("inside xyz:%d", abc);
    abc = 6;
    printf("inside xyz:%d", abc);

}
int main() {
    int abc = 5;
    printf("inside main:%d", abc);
    xyz();
    printf("inside main:%d", abc);
}

/*
typedef struct Node
{
        int item;
        struct Node* link;
}Node;


Node* getnode();
Node* reverseListIterative(Node* head);
Node* reverseListRecursive(Node* head);
Node* insert(Node* head, int item);
Node* delete(Node* head);
Node* pop(Node* head, int* item);
Node* dequeue(Node* head, int* item);
Node* push(Node* head, int item);
Node* addqueue(Node* head, int item);
int search(Node* head, int item);
void printlist(Node* head);
int listLength(Node* head);
void main()
{

int i;
Node* head = NULL;
*/
/*
head = insert(head, 1);
head = insert(head, 2);
head = insert(head, 3);
printlist(head);
head = delete(head);
printlist(head);
i = search(head, 2);
i = search(head, 3);
head = delete(head);
printlist(head);
//head = delete(head);
//printlist(head);
*/

//stack operations:
/*
head = push(head, 1);
head = push(head, 2);
i = search(head, 1);
i = search(head, 3);
head = push(head, 3);
printlist(head);
head = pop(head, &i);
printf("%d ", i);
head = pop(head, &i);
printf("%d ", i);
head = pop(head, &i);
printf("%d ", i);
printlist(head);

head = push(head, 1);
head = pop(head, &i);
printf("%d ", i);
printlist(head);

head = push(head, 1);
head = push(head, 2);
printlist(head);
head = pop(head, &i);
printf("%d \n", i);
printlist(head);

*/

/*
head = addqueue(head, 1);
head = addqueue(head, 2);
i = search(head, 1);
i = search(head, 3);
head = addqueue(head, 3);
printlist(head);
head = dequeue(head, &i);
printf("%d ", i);
head = dequeue(head, &i);
printf("%d ", i);
head = dequeue(head, &i);
printf("%d ", i);
printlist(head);

head = addqueue(head, 1);
head = dequeue(head, &i);
printf("%d ", i);
printlist(head);

head = addqueue(head, 1);
head = addqueue(head, 2);
printlist(head);
head = dequeue(head, &i);
printf("%d \n", i);
printlist(head);

}

Node* getnode()
{
	Node* newnode = (Node *)malloc(sizeof(Node));
	return newnode;
}

// Reverse the list iterative
Node* reverseListIterative(Node* head) {
    Node* temp = NULL;
    Node* next = NULL;
    while (head != NULL) {
        temp = head;
        head = head->link;
        temp->link = next;
        next = temp;
    }
    return next;
}

// Reverse list recursive
Node* reverseListRecursive(Node* head) {
    Node* first = NULL;
    if (head == NULL || head->link == NULL) {
        return head;
    }
    first = reverseListRecursive(head->link);
    head->link->link = head;
    head->link = NULL;
    return first;
}

// get the length of the linkedlist
int listLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->link;
    }
    return len;
}
//print the list
void printlist(Node* head)
{
	Node* curr = head;
	while(curr!= NULL)
	{
		printf("%d ", curr->item);
		curr = curr->link;
	}
	printf("\n");
}

//insert at back
Node* insert(Node* head, int item)
{
	Node* curr;
	Node* newnode;
	newnode = getnode();
	if(newnode == NULL)
	{
		printf("could not create new node\n");
		return NULL;
	}
	newnode->item = item;
	newnode->link = NULL;
	if(head == NULL)
	{
		head = newnode;
		return head;
	}
	curr = head;
	while(curr->link!=NULL)
	{
		curr = curr->link;
	}
	curr->link = newnode;
	return head;
}

//delete from back
Node* delete(Node* head)
{
	Node* curr;
	Node* prev;
	
	if(head == NULL)
		return NULL;
	//only one node left to delete
	if(head->link == NULL)
	{
		prev = head;
		head = NULL;
		free(prev);
		return head;
	}
	prev = head;
	curr = head->link;
	while(curr->link != NULL)
	{
		prev = curr;
		curr = curr->link;
	}
	prev->link = curr->link;
	free(curr);
	return head;
}

//push(insert and delete from front)

Node* push(Node* head, int item)
{

        Node* newnode;
        newnode = getnode();
	if(newnode == NULL)
	{
		printf("could not create new node\n");
		return NULL;
	}
        newnode->item = item;
        newnode->link = NULL;

        if(head == NULL)
        {
                head = newnode;
                return head;
        }
	newnode->link = head;
	head = newnode;
        return head;
}

//pop from front

Node* pop(Node* head, int* item)
{
	Node* curr;
	if(head == NULL)
	{
		*item = -1;
		return NULL;
	}
	*item  = head->item;
	head = head->link;
	return head;
}

// addqueue
Node* addqueue(Node* head, int item)
{
        Node* curr;
        Node* newnode;
        newnode = getnode();
        if(newnode == NULL)
        {
                printf("could not create new node\n");
                return NULL;
        }
        newnode->item = item;
        newnode->link = NULL;

        if(head == NULL)
        {
                head = newnode;
                return head;
        }
        curr = head;
        while(curr->link!=NULL)
        {
                curr = curr->link;
        }
        curr->link = newnode;
        return head;
}

//dequeue

Node* dequeue(Node* head, int* item)
{
        Node* curr;
        if(head == NULL)
        {
                *item = -1;
                return NULL;
        }
        *item  = head->item;
        head = head->link;
        return head;
}

int search(Node* head, int item)
{
	Node* curr = head;
	while(curr!=NULL)
	{
		if(curr->item == item)
		{
			printf("item found\n");
			return 1;
		}
		curr = curr->link;
	}
	printf("\n item not found\n");
	return 0;
}
*/
