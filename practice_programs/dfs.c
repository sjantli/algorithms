#include <stdio.h>
#include <stdlib.h>

void dfs(int** array, int* visited, int n, int i);
void dfsall(int** array, int n);

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

	dfsall(array, n);
}

void dfs(int** array, int* visited, int n, int i)
{
	int j;
	visited[i] = 1;
	printf("%d\t", i);
	for(j=0;j<n;j++)
	{
		if(array[i][j] == 1)
		{
			if(visited[j] == 0)
			{
				dfs(array, visited, n, j);
			}
		}
	}
}

void dfsall(int** array, int n)
{
	int i;
	int visited[n];
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
	}
	for(i=0;i<n;i++)
	{
		if(visited[i] == 0)
		{
			dfs(array, visited, n, i);
		}
	}
}
