/*
 * Program from crack the coding interview where we the list is a representation of a number and we add two such lists and give a final list.
 */
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
void printlist(Node* head);
Node* addlist(Node* list1, Node* list2);
void main()
{

	int i;
	Node* list1 = NULL;
	Node* list2 = NULL;
	Node* res = NULL;
	list1 = insert(list1, 7);
	list1 = insert(list1, 3);
	list1 = insert(list1, 5);
	list2 = insert(list2, 4);
        list2 = insert(list2, 2);
	res = addlist(list1, list2);
	printlist(res);
}

Node* getnode()
{
        Node* newnode = (Node *)malloc(sizeof(Node));
        return newnode;
}

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

Node* addlist(Node* list1, Node* list2)
{
	Node* res = NULL;
	
	int carry = 0;
	int sum = 0;
	
	while(list1 != NULL || list2 != NULL)
	{
		sum = carry + ((list1)?list1->item:0) + ((list2)?list2->item:0);
		carry = (sum > 10)?1:0;
		sum = sum%10;
		res = insert(res, sum);
		if(list1 != NULL)
			list1 = list1->link;
		if(list2 != NULL)
                        list2 = list2->link;
	}
	if(carry == 1)
	res = insert(res, carry);
	return res;
}
