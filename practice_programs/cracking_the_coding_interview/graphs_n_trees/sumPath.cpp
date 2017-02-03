#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include <iostream>

#define MAX(a, b) a>=b ? a : b

typedef struct Node
{
    int item;
    struct Node* left;
	struct Node* right;
}Node;

Node* getnode();
Node* insert(Node* root, int item);
int depth(Node* node);
void printPath(int start, int end, int path[]);
void sumPath(Node* node, int sum, int path[], int level);
void sumPath(Node* node, int sum);

int main()
{
	Node* root;
	Node* node = NULL;
	Node* head = NULL;
	int i;
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, -5);
	root = insert(root, 5);
	root = insert(root, 40);
    sumPath(root, 10);
    return 0;
}

Node* getnode()
{
        Node* newnode = (Node *)malloc(sizeof(Node));
        return newnode;
}

Node* insert(Node* root, int item)
{

	Node* curr = root;
	Node* trail = root;
	Node* newnode = getnode();
	newnode->item = item;
	newnode->left = NULL;
	newnode->right = NULL;
	if(root == NULL)
	{
		root = newnode;
		return root;
	}

	while(curr!=NULL)
	{
		trail = curr;
		if(curr->item == item)
		{
			printf("\n cannot insert duplicate values");
			return root;
		}
		else if(curr->item > item)
			curr = curr->left;
		else
			curr = curr->right;
	}

	if(trail->item > item)
		trail->left = newnode;
	else
		trail->right = newnode;
	return root;
}

int depth(Node* node) {
    if (node == NULL)
        return 0;
    return 1 + MAX(depth(node->left), depth(node->right));
}

void sumPath(Node* node, int sum) {
    int height = depth(node);
    int path[height];
    sumPath(node, sum, path, 0);
}

void sumPath(Node* node, int sum, int path[], int level) {
    if (node == NULL)
        return;
    path[level] = node->item;

    // Starts from any level and ends at this node;
    int total = 0;
    for (int i = level; i >= 0; i--) {
        total += path[i];
        if (total == sum) {
            printPath(i, level, path);
        }
    }

    sumPath(node->left, sum, path, level+1);
    sumPath(node->right, sum, path, level+1);

    path[level] = INT_MIN;
}

void printPath(int start, int end, int path[]) {
    for (int i = start; i <= end; i++) {
        std::cout << path[i] << "\t";
    }
    std::cout << "\n";
}
