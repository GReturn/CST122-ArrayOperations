#include "arrayOptn.h"

void createArray(int la[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		int val, itemDoesExists;
		do
		{
			printf("Enter value for index %d: ", i);
			scanf("%d", &val);
			itemDoesExists = locateItem(la, size, val);
			if(val != 0 && itemDoesExists == 1)
			{
				printf("Inputted integer already exists, try another number.\n");
			}
		} while(val != 0 && itemDoesExists == 1);
		
		la[i] = val;
	}
	return;
}
void printArray(int la[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("\nItem [%d]: %d", i, la[i]);
	}
	printf("\n");
	return;
}

/* Array Manipulation Functions */
int inserAtPos(int la[], int size, int item, int k)
{
	int i;
	for(i = 0; i < size + 1; i++)
	{
		if(i == k)
		{
			int j;
			for(j = size + 1; j > i; j--)
			{
				la[j] = la[j-1];
			}
			la[i] = item;
			break;
		}
	}
	return ++size;
}
void insertFront(int la[], int *size, int item)
{
	int i;
	for(i = (*size); i > 0; i--)
	{
		la[i] = la[i-1];
	}
	*size = *size + 1;
	la[0] = item;
	return;
}
void removeAtPos(int la[], int *size, int index)
{
	int i;
	for(i = 0; i < *size; i++)
	{
		if(i == index)
		{
			int j;
			for(j = i; j < *size; j++)
			{
				la[j] = la[j+1];
			}
			break;
		}
	}
	*size = *size - 1;
	return;
}
int removeItem(int la[], int size, int item)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(la[i] == item)
		{
			int j;
			for(j = i; j < size; j++)
			{
				la[j] = la[j+1];
			}
			return --size;
		}
	}
	return -1;
}
int removeFront(int la[], int size)
{
	int i;
	for(i = 0; i < size - 1; i++)
	{
		la[i] = la[i+1];
	}
	return --size;
}

/* Locate Functions */
int locateIndex(int la[], int size, int item)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(la[i] == item) return i;
	}
	return -1;
}
int locateItem(int la[], int size, int item)
{
	int i;
	for(i = 0; i < size; i++)
	{
		if(la[i] == item) return 1;
	}
	return 0;
}

/* Sorting Functions */

void swap(int *n, int *m)
{
	int temp = *n;
	*n = *m;
	*m = temp;
}

void sortAscending(int la[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		int j;
		for(j = 0; j < size; j++)
		{
			if(la[i] < la[j])
			{	
				swap(&la[j], &la[i]);
			}	
		}
	}
	return;
}
void sortDescending(int la[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		int j;
		for(j = 0; j < size; j++)
		{
			if(la[i] > la[j])
			{	
				swap(&la[j], &la[i]);
			}	
		}
	}
	return;
}
