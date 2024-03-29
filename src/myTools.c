#include "myTools.h"

void gotoxy(int x, int y)
{
	COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	return;
}
void blackBG()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return;
}
void blueBG()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | BACKGROUND_BLUE);
    return;
}
void drawDBox(int x1, int y1, int x2, int y2)
{
	int i, j;
	
	gotoxy(x1, y1);
	blueBG();
	
	for(i = y1; i <= y2; i++)
	{
		for(j = x1; j <= x2; j++)
		{
			if(i == y1 || i == y2) printf("%c", 196);
			else if(j == x1 || j == x2) printf("%c", 179);
			else printf(" ");
		}
		gotoxy(x1, i+1);
	}
	gotoxy(x1,y1);
    printf("%c", 218);
    gotoxy(x1,y2);
    printf("%c", 192);
    gotoxy(x2,y1);
    printf("%c", 191);
    gotoxy(x2,y2);
    printf("%c", 217);
}
void menu()
{
	int select;
	int size = 0;
	int arr[size];
	
	while(select != 11)
	{
		system("cls");
		
		int x = 33;
		int y = 0;
		drawDBox(x,y, x+45, y+20);
		gotoxy(x+8,y+=2); printf("~~~~~ ARRAY OPERATIONS ~~~~~");
		gotoxy(x+10, y+=2); printf("1. CREATEArray");
		gotoxy(x+10, ++y); printf("2. PRINTArray");
		gotoxy(x+10, ++y); printf("3. INSERTAtPos");
		gotoxy(x+10, ++y); printf("4. INSERTFront");
		gotoxy(x+10, ++y); printf("5. REMOVEAtPos");
		gotoxy(x+10, ++y); printf("6. REMOVEItem");
		gotoxy(x+10, ++y); printf("7. REMOVEFront");
		gotoxy(x+10, ++y); printf("8. LOCATEIndx");
		gotoxy(x+10, ++y); printf("9. LOCATEItem");
		gotoxy(x+10, ++y); printf("10. SORT(Ascending&Descending)");
		gotoxy(x+10, ++y); printf("11. EXIT");
		gotoxy(x+8, y+=2); printf("Enter a valid choice[1-11]: ");
		
		scanf("%d", &select);
		
		blackBG();
		gotoxy(0, y+5);
		
		switch(select)
		{
			case 2 ... 10:
				if(!size)
				{
					printf("Array is empty. Please create the array first.\n");
				}
				else
				{
					int item, index, remRes, itemDoesExists;
					switch(select)
					{
						case 2:
							printArray(arr, size);
							break;
						case 3:
							do
							{
								printf("Input item to insert: ");
								scanf("%d", &item); 
								
								itemDoesExists = locateItem(arr, size, item);
								if(itemDoesExists == 1)
								{
									printf("Inputted integer already exists, try another number.\n");
								}
							} while(itemDoesExists == 1);
							
							do
							{
								printf("Input index position for the item to be placed. Limit it to %d: ", size);
								scanf("%d", &index);
								if(index > size) printf("The inputted index value is invalid. Please input another index.\n");
							} while (index > size);
							
							size = inserAtPos(arr, size, item, index);
							break;
						case 4:
							do
							{
								printf("Input item to insert: ");
								scanf("%d", &item); 
								
								itemDoesExists = locateItem(arr, size, item);
								if(itemDoesExists == 1)
								{
									printf("Inputted integer already exists, try another number.\n");
								}
							} while(itemDoesExists == 1);
							
							
							insertFront(arr, &size, item);
							break;
						case 5:
							printf("Input index to remove: ");
							scanf("%d", &index);
							removeAtPos(arr, &size, index);
							break;
						case 6: 
							printf("Input item to remove: ");
							scanf("%d", &item);
							remRes = removeItem(arr, size, item);
							if(remRes != -1) size = remRes;
							else printf("Item does not exist.\n");
							break;
						case 7: 
							size = removeFront(arr, size);
							break;
						case 8: 
							printf("Input item to locate its index: ");
							scanf("%d", &item);
							int res = locateIndex(arr, size, item);
							
							if(res != -1)
							{
								printf("Item is located at index %d\n", res);	
							}
							else printf("item does not exist in the array.\n");
							break;
						case 9:
							printf("Input item to locate: ");
							scanf("%d", &item); 
							if(locateItem(arr, size, item)) printf("Item exists.\n");
							else printf("Item does not exist in the array.\n");
							break;
						case 10: 
							printf("Ascending: ");
							sortAscending(arr, size);
							printArray(arr, size);
							printf("\nDescending: ");
							sortDescending(arr, size);
							printArray(arr, size);
							break;
					}
				}
				break;
			case 1:
				printf("Enter size of array: ");
				scanf("%d", &size);
				createArray(arr, size);
				break;
			case 11:
				printf("Exiting the application...");
				return;
			default:
				gotoxy(x, y+22);
				printf("Please enter a valid number.");
				gotoxy(x, y+23);
		}
		printf("\nPress Enter to continue...");
		getch();
	}
	return;
}
