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
Node* push(Node* head, int item);
Node* padList(Node* head, int padding);
Node* addListsReverse(Node* list1, Node* list2, int carry);
Node* addListsForward(Node* list1, Node* list2);
Node* addListsHelper(Node* list1, Node* list2);
int search(Node* head, int item);
void printlist(Node* head);
int listLength(Node* head);
void main()
{
    int i;
    Node* list1 = NULL;
    Node* list2 = NULL;
    list1 = insert(list1, 7);
    list1 = insert(list1, 1);
    list1 = insert(list1, 6);
    list2 = insert(list2, 5);
    list2 = insert(list2, 9);
    list2 = insert(list2, 2);
    printlist(list1);
    printlist(list2);
    Node* result = addListsReverse(list1, list2, 0);
    Node* result = addListsForward(list1, list2);
    printlist(result);
}

Node* getnode()
{
	Node* newnode = (Node *)malloc(sizeof(Node));
	return newnode;
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

Node* padList(Node* head, int padding) {
    while (padding > 0) {
        head = push(head, 0);
        padding--;
    }
    return head;
}
Node* addListsForward(Node* list1, Node* list2) {
    int len1 = listLength(list1);
    int len2 = listLength(list2);

    if (len1 < len2) {
        list1 = padList(list1, len2 - len1);
    } else {
        list2 = padList(list2, len1 - len2);
    }

    Node* sum = addListsHelper(list1, list2);

    if (sum->item == 0) {
        return sum->link;
    } else {
        Node* result = push(sum->link, sum->item);
        return result;
    }
}
Node* addListsHelper(Node* list1, Node* list2) {
    if (list1 == NULL && list2 == NULL) {
        Node* sum = getnode();
        sum->link = NULL;
        sum->item = 0;
        return sum;
    }

    Node* sum = addListsHelper(list1->link, list2->link);

    int val = sum->item + list1->item + list2->item;

    Node* result = push(sum->link, val % 10);

    sum->link = result;
    sum->item = val / 10;
    return sum;
}

Node* addListsReverse(Node* list1, Node* list2, int carry) {
    if (list1 == NULL && list2 == NULL && carry == 0) {
        return NULL;
    }

    Node *result = getnode();
    int value = carry;

    if (list1 != NULL) {
        value += list1->item;
    }
    if (list2 != NULL) {
        value += list2->item;
    }
    result->item = value % 10;
    Node* node = addListsReverse((list1 == NULL) ? NULL : list1->link,
                          (list2 == NULL) ? NULL : list2->link,
                          (value >= 10) ? 1 : 0);
    result->link = node;
    return result;
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
