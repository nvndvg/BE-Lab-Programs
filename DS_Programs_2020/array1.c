/*  1. Design, Develop and Implement a menu driven Program in C for the following
		Array operations
		a. Creating an Array of N Integer Elements
		b. Display of Array Elements with Suitable Headings
		c. Inserting an Element (ELEM) at a given valid Position (POS)
		d. Deleting an Element at a given valid Position(POS)
		e. Exit.
	Support the program with functions for each of the above operations.
*/


/*
	1. Linear Array as LA
	2.
*/

/* SIMPLE ARRAY IMPLEMENTATION */

#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>

#define TRUE 1
#define FALSE 0

typedef struct LinearArray
{
	int key;
}Record;
Record LA[20];

int nElement = 0;

Record getNextRecord ( void )
{
	Record data;
	
	scanf ( "%d", &data.key );
	
	return data;
}

void readData ( void )
{
	int i;
	
	printf ( "\n\tEnter the size of the array: ?\b" );
	scanf ( "%d", &nElement );
	
	printf ( "\n\tEnter the array elements one by one\n\t" );
	for ( i = 1; i <= nElement; ++ i )
	{
		scanf ( "%d", &LA[i].key );
		printf ( "\n\t" );
	}
}

void writeData ( void )
{
	int i;

	if ( nElement == 0 )
	{
		printf ( "\n\n\tArray List is Empty\n" );
		return;
	} 
	
	printf ( "\n\tThe array elements are..\n\n" );
	printf ( "\t(index  : value)\n\n" );

	for ( i = 1; i <= nElement; ++ i )
	{
		printf ( "\t  [%d]\t:%5d\n\n", i, LA[i] );
	}
	printf ( "\n" );	
}

int validate ( int pos )
{
	if ( pos <= 0 )
	{
		return FALSE;
	}
	if ( pos > nElement )
	{
		
	}
}

void addElement ( void )
{
	int ele, pos;
	int counter;
	
	if ( nElement == 0 )
	{
		printf ( "\n\n\tArray List is Empty\n" );
		return;
	} 
		
	writeData ( );
	
	printf ( "\n\tEnter the valid pos: ?\b" );
	scanf ( "%d", &pos );
	
	if ( (pos <= 0) || (pos > nElement) )
	{
		printf ( "\n\tInvalid Position\n" );
		return;
	}
	
	printf ( "\n\tEnter an Element to insert: ?\b" );
	scanf ( "%d", &ele );
	
	/*Initialize counter*/
	counter = nElement;	
	while ( counter >= pos )
	{
		/*Move elements downwards*/
		LA[counter + 1] = LA[counter];
		counter = counter - 1;
	}
	LA[pos] = ele;
	
	/*Reset the number of elements in Array*/
	nElement = nElement + 1;
	
	printf ( "\n\tItem Inserted successfully\n" );
}

void deleteElement ( void )
{
	
	int ele, pos;
	int i;

	if ( nElement == 0 )
	{
		printf ( "\n\n\tArray List is Empty\n" );
		return;
	} 
	
	writeData ( );
	
	printf ( "\n\tEnter the valid pos: ?\b" );
	scanf ( "%d", &pos );
	
	if ( (pos <= 0) || (pos > nElement) )
	{
		printf ( "\n\tInvalid Position\n" );
		return;
	}
	
	printf ( "\n\tDeleted Element: %d\n\n", LA[pos] );
	
	for ( i = pos; i < nElement; ++ i )
	{
		/*Move elements upward*/
		LA[i] = LA[i + 1];
	}		
	
	/*Reset the number of elements in Array*/
	nItems = nItems - 1;
}

int main ( void )
{
	
	int ch;

	do{
		//clrscr();
		system("cls");
		printf ("\n\t\t\t  ARRAY DEMONSTRATION\n\n" );
		printf ("\n\t\t1. Create Array\t\t2. Display Array\n" );
		printf ("\n\t\t3. Insert Element\t4. Delete Element\n" );
		printf ("\n\t\t\t\t5. Exit\n\n" );

		printf ( "\n\tEnter your choice: ?\b" );
		scanf ( "%d", &ch );

		switch ( ch )
		{
			case 1: createArray ( );
					break;
			case 2: displayElements ( );
					break;
			case 3: insertAnElement ( );
					break;
			case 4: deleteAnElement ( );
					break;
			case 5: return 0;
			default: printf ( "\n\tInvalid Option\n\n" );
		}
		fflush(stdin);
		getchar();
		//getch();
	}while ( 1 );
}