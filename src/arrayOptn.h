#include <stdio.h>
#include <stdlib.h>

void createArray(int la[], int size);
void printArray(int la[], int size);
int inserAtPos(int la[], int size, int item, int k);
void insertFront(int la[], int *size, int item);
void removeAtPos(int la[], int *size, int index);
int removeItem(int la[], int size, int item);
int removeFront(int la[], int size);
int locateIndex(int la[], int size, int item);
int locateItem(int la[], int size, int item);
void sortAscending(int la[], int size);
void sortDescending(int la[], int size);
