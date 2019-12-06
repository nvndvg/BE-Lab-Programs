/*  1. Design, Develop and Implement a menu driven Program in C for the following
		Array operations
		a. Creating an Array of N Integer Elements
		b. Display of Array Elements with Suitable Headings
		c. Inserting an Element (ELEM) at a given valid Position (POS)
		d. Deleting an Element at a given valid Position(POS)
		e. Exit.
	Support the program with functions for each of the above operations.
*/

/* SIMPLE ARRAY IMPLEMENTATION */

#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>

int linearArray[100];
int noOfElements = 0;

void createArray ( void )
{
	int i;
	
	printf ( "\n\tEnter the size of the array: ?\b" );
	scanf ( "%d", &noOfElements );
	
	printf ( "\n\tEnter the array elements one by one\n\t" );
	for ( i = 1; i <= noOfElements; ++ i )
	{
		scanf ( "%d", &linearArray[i] );
		printf ( "\n\t" );
	}
}

void displayElements ( void )
{
	int i;

	if ( noOfElements == 0 )
	{
		printf ( "\n\n\tArray List is Empty\n" );
		return;
	} 
	
	printf ( "\n\tThe array elements are..\n\n" );
	printf ( "\t(index  : value)\n\n" );

	for ( i = 1; i <= noOfElements; ++ i )
	{
		printf ( "\t  [%d]\t:%5d\n\n", i, linearArray[i] );
	}
	printf ( "\n" );	
}

void insertAnElement ( void )
{
	int element, position;
	int counter;
	
	if ( noOfElements == 0 )
	{
		printf ( "\n\n\tArray List is Empty\n" );
		return;
	} 
		
	displayElements ( );
	
	printf ( "\n\tEnter the valid position: ?\b" );
	scanf ( "%d", &position );
	
	if ( (position <= 0) || (position > noOfElements) )
	{
		printf ( "\n\tInvalid Position\n" );
		return;
	}
	
	printf ( "\n\tEnter an Element to insert: ?\b" );
	scanf ( "%d", &element );
	
	/*Initialize counter*/
	counter = noOfElements;	
	while ( counter >= position )
	{
		/*Move elements downwards*/
		linearArray[counter + 1] = linearArray[counter];
		counter = counter - 1;
	}
	linearArray[position] = element;
	
	/*Reset the number of elements in Array*/
	noOfElements = noOfElements + 1;
	
	printf ( "\n\tItem Inserted successfully\n" );
}

void deleteAnElement ( void )
{
	
	int element, position;
	int i;

	if ( noOfElements == 0 )
	{
		printf ( "\n\n\tArray List is Empty\n" );
		return;
	} 
	
	displayElements ( );
	
	printf ( "\n\tEnter the valid position: ?\b" );
	scanf ( "%d", &position );
	
	if ( (position <= 0) || (position > noOfElements) )
	{
		printf ( "\n\tInvalid Position\n" );
		return;
	}
	
	printf ( "\n\tDeleted Element: %d\n\n", linearArray[position] );
	
	for ( i = position; i < noOfElements; ++ i )
	{
		/*Move elements upward*/
		linearArray[i] = linearArray[i + 1];
	}		
	
	/*Reset the number of elements in Array*/
	noOfElements = noOfElements - 1;
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