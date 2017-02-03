#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
        int item;
        struct Node* prev;
        struct Node* next;
}Node;

Node* getnode();
void search(int item, Node** headP, Node** nodeP);
void insertAt(int item, Node** nodeP);
void deleteAt(Node** headP, Node** nodeP);
void insertFront(int item, Node** headP);
void insertRear(int item, Node** headP);
void deleteFront(Node** headP);
void deleteRear(Node** headP);
void printList(Node** headP);

int main()
{
	Node* head = NULL;
	Node* node = NULL;
	insertAt(1, &head);
	insertFront(2, &head);
	insertRear(3, &head);
	search(2, &head, &node);
	if (node != NULL) {
		printf("item found: %d\n", node->item);
	} else {
		printf("item not found\n");
	}

	
	printList(&head);
	deleteAt(&head, &node);
	search(3, &head, &node);
	if (node != NULL) {
		printf("item found: %d\n", node->item);
	} else {
		printf("item not found\n");
	}
	insertAt(4, &node);
	printList(&head);
	deleteAt(&head, &node);
	printList(&head);
	search(2, &head, &node);
	if (node != NULL) {
		printf("item found: %d\n", node->item);
	} else {
		printf("item not found\n");
	}
	deleteAt(&head, &node);
	printList(&head);
	deleteFront(&head);
	printList(&head);
	deleteRear(&head);
	printList(&head);
	insertFront(2, &head);
	insertRear(3, &head);
	insertFront(4, &head);
	insertRear(1, &head);
	insertFront(5, &head);
	insertRear(3, &head);
	printList(&head);
	return 0;
}

Node* getnode()
{
	Node* newnode = (Node *)malloc(sizeof(Node));
	if (newnode != NULL) {
		newnode->prev = NULL;
		newnode->next = NULL;
	}
	return newnode;
}

void printList(Node** headP)
{
	Node* head = *headP;
	Node* temp = head;

	while (temp != NULL) {
		printf("%d\t",temp->item);
		temp = temp->next;
	}
	printf("\n");
}

// Given the head of the list, search the item and return the node if found, else return null.
void search(int item, Node** headP, Node** nodeP)
{
	Node* head = *headP;
	Node* temp = head;

	while (temp != NULL) {
		if (temp->item == item) {
			*nodeP = temp;
			return;
		}
		temp = temp->next;
	}
	*nodeP = temp;
}

// insert the item after the node passed in (assuming insertion always happens after the node passed and if node passed in null then it means list is empty. cannot insert in the front of the list unless its empty.
void insertAt(int item, Node** nodeP)
{
	Node* node = *nodeP;
	Node* newnode = getnode();
	newnode->item = item;
	// if head is null
	if (node == NULL) {
		node = newnode;
		*nodeP = node;
		return;
	}
	
	// last node
	if (node->next == NULL) {
		newnode->next = node->next;
		newnode->prev = node;
		node->next = newnode;
		*nodeP = node;
		return;
	}

	newnode->next = node->next;
	node->next->prev = newnode;
	newnode->prev = node;
	node->next = newnode;
	*nodeP = node;
}


// delete the node passed in
void deleteAt(Node** headP, Node** nodeP)
{
	Node* head = *headP;
	Node* node = *nodeP;


	// if no node to delete
	if (node == NULL) {
		return;
	}

	// if only one node;
	if (node->next == NULL && node->prev == NULL) {
	//	temp = node;
	//	node = NULL;
	//	free(temp);
		*headP = NULL;
		free(node);
		return;
	}

	if (node->next == NULL) {
		node->prev->next = NULL;
	//	temp = node;
	//	temp->prev = temp->next = NULL;
	//	free(temp);
		node->prev = node->next = NULL;
		free(node);
		return;
	}

	if (node->prev == NULL) {
		node->next->prev = NULL;
		*headP = node->next;
		node->next = node->prev = NULL;
		free(node);
		return;
	}

	node->next->prev = node->prev;
	node->prev->next = node->next;
	node->next = node->prev = NULL;
	free(node);
}

void insertFront(int item, Node** headP)
{
	Node* head = *headP;
	Node* newnode = getnode();
	newnode->item = item;
	// empty list
	if (head == NULL) {
		head = newnode;
		*headP = head;
		return;
	}
	
	// make the newnode as the new head of the list	
	newnode->next = head;
	head->prev = newnode;
	head = newnode;	
	*headP = head;
}

void insertRear(int item, Node** headP)
{
	Node* head = *headP;
	Node* newnode = getnode();
	newnode->item = item;
	Node* temp = head;
	// empty list
	if (head == NULL) {
		head = newnode;
		*headP = head;
		return;
	}

	// traverse till the end of list and insert the node there
	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newnode;
	newnode->prev = temp;
}

void deleteFront(Node** headP)
{
	Node* head = *headP;	
	Node* temp = head;

	// empty list, just return
	if (head == NULL) {
		return;
	}

	// only one node exists, delete it and head now points to null(empty list)
	if (temp->next == NULL) {
		head = NULL;
		*headP = head;
		free(temp);
		return;
	}

	head = temp->next;
	head->prev = NULL;
	temp->next = NULL;
	*headP = head;
	free(temp);

}

void deleteRear(Node** headP)
{
	Node* head = *headP;
	Node* temp = head;

	// empty list, just return
	if (head == NULL) {
		return;
	}

	// only one node exists, delete it and head now points to null(empty list)
	if (temp->next == NULL) {
		head = NULL;
		free(temp);
		*headP = head;
		return;
	}

	// traverse till end and delete the node
	while (temp->next != NULL) {
		temp = temp->next;
	}
	
	temp->prev->next = NULL;
	temp->prev = NULL;
	free(temp);
}
