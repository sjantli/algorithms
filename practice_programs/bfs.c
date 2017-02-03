#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
        int item;
        struct Node* link;
}Node;


Node* getnode();
Node* dequeue(Node* head, int* item);
Node* addqueue(Node* head, int item);
void bfs(int** array, int n);

void main()
{
        int n, i, j;
        int edge;
        int **array;
        printf("enter the number of nodes\n");
        scanf("%d", &n);
        array = malloc(sizeof(*array) * n);
        if(array!=NULL)
        {
                for(i=0;i<n;i++)
                {
                        array[i] = malloc(sizeof(int) * n);
                }
        }
        printf("enter the adjacency matrix\n");
        for(i=0;i<n;i++)
        {
                printf("enter the elements of row %d", i);
                for(j=0;j<n;j++)
                {
                        scanf("%d", &edge);
                        array[i][j] = edge;
                }
        }

        bfs(array, n);
}

Node* getnode()
{
        Node* newnode = (Node *)malloc(sizeof(Node));
        return newnode;
}

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

void bfs(int** array, int n)
{
	int i,j,k;
	int visited[n];
	Node* head = NULL;
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
	}

	for(i=0;i<n;i++)
	{
		if(visited[i] == 0)
		{
			visited[i] = 1;
			printf("%d ", i);
			head = addqueue(head, i);
			while(head != NULL)
			{
				head = dequeue(head, &j);
				for(k=0;k<n;k++)
				{
					if(array[j][k] == 1)
					{
						if(visited[k] == 0)
						{
							visited[k] =1;
							printf("%d ", k);
							head = addqueue(head, k);
						}
					}
				}
			}
		}
	}
}
