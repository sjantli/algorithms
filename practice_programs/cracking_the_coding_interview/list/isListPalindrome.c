#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//typedef enum {false, true} bool;

typedef struct Node
{
        int item;
        struct Node* link;
}Node;


Node* getnode();
Node* insert(Node* head, int item);
Node* pop(Node* head, int* item);
Node* push(Node* head, int item);
Node* reverseListIterative(Node* head);
Node* reverseListRecursive(Node* head);
void printlist(Node* head);
int listLength(Node* head);
int isListPalindromeIterative(Node* head);
int isListPalindromeRecursive(Node* head, int len, Node** node);
void main()
{
    int item;
    Node* head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
//    head = push(head, 4);
  //  head = push(head, 3);
    //head = push(head, 2);
    head = push(head, 1);
    printf("length of the list: %d\n", listLength(head));
    printlist(head);
    head = reverseListIterative(head);
    printlist(head);
    head = reverseListRecursive(head);
    printlist(head);
    /*
    if (isListPalindromeIterative(head)) {
        printf("\n List is palindrome\n");
    } else {
        printf("\n List is not a palindrome\n");
    }
    Node* node = NULL;
    if (isListPalindromeRecursive(head, listLength(head), &node)) {
        printf("\n List is palindrome\n");
    } else {
        printf("\n List is not a palindrome\n");
    }
    */
    /*
    while(head != NULL) {
        head = pop(head, &item);
        printf("%d\t", item);
    }
    if (head == NULL) {
        printf("\ncorrectly popped\n");
    }
    */
}

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

int isListPalindromeRecursive(Node* head, int len, Node** node) {
    if (len == 0 || head == NULL) {
        return 1;
    } else if (len == 1) {
        *node = head->link;
        return 1;
    } else if (len == 2) {
        *node = head->link->link;
        return (head->link->item == head->item);
    }
    int res = isListPalindromeRecursive(head->link, len-2, node);
    if (res != 1 || *node == NULL) {
        return res;
    } else {
        res = (head->item == (*node)->item);
        *node = (*node)->link;
        return res;
    }
}

int isListPalindromeIterative(Node* head) {
    Node* fast = head;
    Node* slow = head;
    Node* stack = NULL;
    int item;

    while(fast != NULL && fast->link != NULL) {
        // add to stack
        stack = push(stack, slow->item);
        slow = slow->link;
        fast = fast->link->link;
    }
    // if it is odd list, skip the middle element
    if (fast != NULL) {
        slow = slow->link;
    }
    //    printlist(stack);
    // Compare slow with stack elements
    while (slow != NULL) {
        stack = pop(stack, &item);
        if (item != slow->item) {
            return 0;
        }
        slow = slow->link;
    }
    return 1;
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
