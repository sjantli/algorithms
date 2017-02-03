#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Node
{
        int item;
        struct Node* link;
}Node;


Node* getnode();
Node* insert(Node* head, int item);
Node* partitionList(Node* head, int item);
void printlist(Node* head);
void main()
{
    Node* head = NULL;
    head = insert(head, 8);
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 3);
    head = insert(head, 1);
    head = insert(head, 6);
    head = insert(head, 4);
    head = insert(head, 3);
    head = insert(head, 9);
    head = insert(head, 2);
    head = insert(head, 5);
    printlist(head);

    head = partitionList(head, 4);
    printlist(head);
}

Node* getnode()
{
	Node* newnode = (Node *)malloc(sizeof(Node));
	return newnode;
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

Node* partitionList(Node* head, int item) {
    Node* smallhead = NULL;
    Node* smalltail = NULL;
    Node* bighead = NULL;
    Node* bigtail = NULL;

    while (head != NULL) {
        Node* node = head;
        head = head->link;
        node->link = NULL;
        if (node->item < item) {
            if (smallhead == NULL) {
                smallhead = node;
                smalltail = node;
            } else {
                smalltail->link = node;
                smalltail = node;
            }
        } else {
            if (bighead == NULL) {
                bighead = node;
                bigtail = node;
            } else {
                bigtail->link = node;
                bigtail = node;
            }
        }
    }
    if (smalltail == NULL) {
        return bighead;
    }
    smalltail->link = bighead;
    return smallhead;
}
