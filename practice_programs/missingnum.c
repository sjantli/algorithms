#include<stdio.h>
#include<stdlib.h>

int missingnum(int* array, int min, int max);
int missingxor(int* array, int min, int max);

void main()
{
	int min, max;
	int diff, i;
	int *array;
	printf("enter the range\n");
	scanf("%d", &min);
	scanf("%d", &max);
	diff = max - min;
	array = (int *) malloc(sizeof(int) * diff);
	printf("enter the numbers \n");
	for(i = 0;i<diff;i++)
	{
		scanf("%d", &array[i]);
	}
	i = missingnum(array, min, max);
	printf("\n missing number is %d", i);
	i = missingxor(array, min, max);
        printf("\n missing number is %d", i);
}

int missingnum(int* array, int min, int max)
{
	double min_sum=0;
	double max_sum=0;
	double given_sum = 0;
	int i;
	min_sum = (min * (min +1) ) / 2;
	max_sum = (max * (max +1) ) / 2;
	for(i=0;i<(max-min);i++)
	{
		given_sum+=array[i];
	}
	
	i = (max_sum - min_sum + min) - given_sum;
	return i;
}

int missingxor(int* array, int min, int max)
{
	int i, x1, x2, res;
	x1 = array[0];
	x2 = min;
	for(i=1;i<(max-min);i++)
	{
		x1= x1^array[i];
	}
	for(i=min+1;i<=max;i++)
	{
		x2 = x2^i;
	}
	res = x1^x2;
	return res;
}  
