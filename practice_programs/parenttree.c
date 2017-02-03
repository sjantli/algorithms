#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node
{
        int item;
        struct Node* left;
	struct Node* right;
	struct Node* parent;
	
}Node;

Node* getnode();
Node* insert(Node* root, int item);
void deletenode(Node** node);
Node* delete(Node* root, int item);
void inorder(Node* root);
int search(Node* root, int item);
int checkbst(Node* root);
int bstvalidate(Node* root, int min, int max);
Node* search_for_node(Node* root, int item);
Node* leftmostnode(Node* node);
Node* successor(Node* node);
void main()
{
	
	Node* root;
	Node* node = NULL;
	int i;
	root = insert(root, 12);
	inorder(root);
	root = insert(root, 8);
        inorder(root);
	root = insert(root, 13);
        inorder(root);
	i = search(root, 8);
	i = search(root, 12);
	i = search(root, 15);
	root = delete(root, 8);
	root = delete(root, 12);
	root = delete(root, 13);
	inorder(root);	
//	root = delete(root, 13);
	
	
	root = insert(root, 12);
	root = insert(root, 8);
	root = insert(root, 13);
	root = insert(root, 18);
	root = insert(root, 20);
	root = insert(root, 15);
	root = insert(root, 14);
	root = insert(root, 21);
	root = insert(root, 10);
	root = insert(root, 6);
	root = insert(root, 5);
	root = insert(root, 7);
	root = insert(root, 9);
	root = insert(root, 11);
	inorder(root);
/*	root = delete(root, 11);
	root = delete(root, 15);
	root = delete(root, 20);
	root = delete(root, 8);
*/
	printf("\n successor\n");
	node = search_for_node(root, 6);
	node = successor(node);
	printf("\n%d", node->item);
	node = search_for_node(root, 8);
        node = successor(node);
        printf("\n%d", node->item);
	node = search_for_node(root, 11);
        node = successor(node);
        printf("\n%d", node->item);
	node = search_for_node(root, 13);
        node = successor(node);
        printf("\n%d", node->item);
	node = search_for_node(root, 21);
        node = successor(node);
	if(node != NULL)
        	printf("\n%d", node->item); 
	else
		printf("last node\n");
	
}

Node* getnode()
{
        Node* newnode = (Node *)malloc(sizeof(Node));
        return newnode;
}

void inorder(Node* root)
{
	if(root == NULL)
		return;
	else
	{
		inorder(root->left);
		printf("%d ", root->item);
		inorder(root->right);
	}
}

Node* insert(Node* root, int item)
{

	Node* curr = root;
	Node* trail = root;
	Node* newnode = getnode();
	newnode->item = item;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;
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
	newnode->parent = trail;
	return root;
}

Node* delete(Node* root, int item)
{
	Node* curr = root;
	Node* trail = root;
	int found = 0;
	if(root == NULL)
        {
                printf("tree is empty can't delete\n");
                return NULL;
        }
	
	while(curr != NULL && found==0 )
	{
		if(curr->item == item)
		{
			found = 1;
		}
		else
		{
			trail = curr;
			if(curr->item > item)
				curr = curr->left;
			else
				curr = curr->right;
		}
	}
		
	if(curr == NULL)
	{
		return NULL;
	}
	if(found)
	{
		if(curr == root)
		{
			deletenode(&root);
		}
		else if(trail->item > item)
		{
			deletenode(&(trail->left));
		}
		else
		{
			deletenode(&(trail->right));
		}
	}
	return root;
}

void deletenode(Node** node)
{
	Node* curr = NULL;
	Node* trail = NULL;
	if(*node == NULL)
	{
		printf("can't delete\n");
		return;
	}
	
	else if((*node)->left == NULL && (*node)->right == NULL)
	{
		curr = *node;
		*node = NULL;
		curr->parent = NULL;
		free(curr);
	}
	
	else if((*node)->left == NULL)
	{
		curr = *node;
		*node = (*node)->right;
		curr->parent = NULL;
		free(curr);
	}
	
	else if((*node)->right == NULL)
        {
                curr = *node;
                *node = (*node)->left;
		curr->parent = NULL;
                free(curr);
        }
	else
	{
	
		curr = (*node)->left;
		while(curr->right != NULL)
		{
			trail = curr;
			curr = curr->right;
		}
		(*node)->item = curr->item;
		if(trail == NULL)
			(*node)->left = curr->left;
		else
			trail->right = curr->left;
		curr->parent = NULL;
		free(curr);
	}
}

int search(Node* root, int item)
{

	Node* curr = root;
	if(curr == NULL)
	{
		printf("tree is empty can't search\n");
		return 0;
	}

	while(curr != NULL)
	{
		if(curr->item == item)
                {
                        printf("item found\n");
                        return 1;
                }
                else if(curr->item > item)
                        curr = curr->left;
                else
                        curr = curr->right;
	}

	printf("item not found \n");
	return 0;
}

Node* search_for_node(Node* root, int item)
{

        Node* curr = root;
//	printf("searching node\n");
        if(curr == NULL)
        {
                printf("tree is empty can't search\n");
                return NULL;
        }

        while(curr != NULL)
        {
//		printf("came here\n");
                if(curr->item == item)
                {
                        printf("item found\n");
                        return curr;
                }
                else if(curr->item > item)
                        curr = curr->left;
                else
                        curr = curr->right;
        }

        printf("item not found \n");
        return NULL;
}

int bstvalidate(Node* root, int min, int max)
{
	if(root == NULL)
		return 1;
	else if(root->item <= min || root->item >max)
	{
		return 0;
	}
	if(!(bstvalidate(root->left, min, root->item)) || !(bstvalidate(root->right, root->item, max)))
	{
		return 0;
	}
	return 1;
}

int checkbst(Node* root)
{
	return bstvalidate(root, INT_MIN, INT_MAX);
}

Node* leftmostnode(Node* node)
{
	if(node == NULL)
		return NULL;
	while(node->left != NULL)
	{
		node = node->left;
	}
	return node;
}

Node* successor(Node* node)
{
	Node* q;
	Node* x;
	if(node == NULL)
	{
		printf("\n node is null\n");
		return NULL;
	}
	if(node->right != NULL)
	{
		//printf("has right child\n");
		return leftmostnode(node->right);
	}
	//check until current node is theleft of its parent
	else
	{
		q = node;
		x = q->parent;
		while(x!=NULL && x->left != q)
		{
			q = x;
			x = x->parent;
		}
		return x;
	}
}
