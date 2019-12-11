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

int isEmpty ( void )
{
	return ( nElement == 0 );
}

int isValid ( int pos )
{
	return ( pos > 0 && pos <= nElement )  ;
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
	
	printf ( "\n\tThe array elements are..\n\n" );
	printf ( "\t(index  : value)\n\n" );

	for ( i = 1; i <= nElement; ++ i )
	{
		printf ( "\t  [%d]\t:%5d\n\n", i, LA[i] );
	}
	printf ( "\n" );
	
}

void addElement ( void )
{
	int ele, pos;
	int counter;
		
	writeData ( );
	
	printf ( "\n\tEnter the valid pos: ?\b" );
	scanf ( "%d", &pos );
	
	if ( isValid ( pos ) )
	{
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
		LA[pos].key = ele;
		
		/*Reset the number of elements in Array*/
		nElement = nElement + 1;
		
		printf ( "\n\tItem Inserted successfully\n" );
	}
	else
	{
		printf ( "\n\tInvalid Position\n" );
	}	
}

void deleteElement ( void )
{	
	int ele, pos;
	int i;

	writeData ( );
	
	printf ( "\n\tEnter the valid pos: ?\b" );
	scanf ( "%d", &pos );
	
	if ( isValid ( pos ) )
	{
		printf ( "\n\tDeleted Element: %d\n\n", LA[pos].key );
	
		for ( i = pos; i < nElement; ++ i )
		{
			/*Move elements upward*/
			LA[i] = LA[i + 1];
		}		
		
		/*Reset the number of elements in Array*/
		nElement = nElement - 1;
	}
	else
	{
		printf ( "\n\tInvalid Position\n" );
	}	
}

int main ( void )
{
	
	int ch;
	system("cls");
	do{
		//clrscr();
		//system("cls");
		printf ("\n\t\t\t  ARRAY DEMONSTRATION\n\n" );
		printf ("\n\t\t1. Read Array Elements\t\t2. Write Array Elements\n" );
		printf ("\n\t\t3. Insert an Element\t\t4. Delete an Element\n" );
		printf ("\n\t\t\t\t5. Exit\n\n" );

		printf ( "\n\tEnter your choice: ?\b" );
		scanf ( "%d", &ch );

		switch ( ch )
		{
			case 1: if ( isEmpty ( ) )
					{
						readData ( );
					}	
					else 
					{
						printf ( "\nArray List is not Empty\n" );
					}									
					break;
			case 2: if ( isEmpty ( ) )
					{
						printf ( "\nArray List is Empty\n" );
					}	
					else 
					{
						writeData ( );
					}					
					break;
			case 3: if ( isEmpty ( ) )
					{
						printf ( "\nArray List is Empty\n" );
					}	
					else 
					{
						addElement ( );
					}
					break;
			case 4: if ( isEmpty ( ) )
					{
						printf ( "\nArray List is Empty\n" );
					}	
					else 
					{
						deleteElement ( );
					}
					break;
			case 5: return 0;
			default: printf ( "\n\tInvalid Option\n\n" );
		}
		fflush(stdin);
		getchar();
		//getch();
	}while ( 1 );
}

/*

                          		ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                                	5. Exit

        Enter your choice: 1

        Enter the size of the array: 5

        Enter the array elements one by one
        10

        20

        30

        40

        50

                        		ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                                	5. Exit

        Enter your choice: 2

        The array elements are..

        (index  : value)

          [1]   :   10

          [2]   :   20

          [3]   :   30

          [4]   :   40

          [5]   :   50

                        		ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                                	5. Exit

        Enter your choice: 3

        The array elements are..

        (index  : value)

          [1]   :   10

          [2]   :   20

          [3]   :   30

          [4]   :   40

          [5]   :   50

        Enter the valid pos: 3

        Enter an Element to insert: 300

        Item Inserted successfully


                          		ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                                		5. Exit

        Enter your choice: 2

        The array elements are..

        (index  : value)

          [1]   :   10

          [2]   :   20

          [3]   :  300

          [4]   :   30

          [5]   :   40

          [6]   :   50

                          			ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                                		5. Exit

        Enter your choice: 4

        The array elements are..

        (index  : value)

          [1]   :   10

          [2]   :   20

          [3]   :  300

          [4]   :   30

          [5]   :   40

          [6]   :   50

        Enter the valid pos: 6

        Deleted Element: 50


                          		ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                                	5. Exit

        Enter your choice: 2

        The array elements are..

        (index  : value)

          [1]   :   10

          [2]   :   20

          [3]   :  300

          [4]   :   30

          [5]   :   40

                          		ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                                	5. Exit

        Enter your choice: 3

        The array elements are..

        (index  : value)

          [1]   :   10

          [2]   :   20

          [3]   :  300

          [4]   :   30

          [5]   :   40

        Enter the valid pos: 0

        Invalid Position


                          		ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                               	 	5. Exit

        Enter your choice: 3

        The array elements are..

        (index  : value)

          [1]   :   10

          [2]   :   20

          [3]   :  300

          [4]   :   30

          [5]   :   40

        Enter the valid pos: 5

        Enter an Element to insert: 500

        Item Inserted successfully


                          		ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                                	5. Exit

        Enter your choice: 2

        The array elements are..

        (index  : value)

          [1]   :   10

          [2]   :   20

          [3]   :  300

          [4]   :   30

          [5]   :  500

          [6]   :   40

                          		ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                                	5. Exit

        Enter your choice: 3

        The array elements are..

        (index  : value)

          [1]   :   10

          [2]   :   20

          [3]   :  300

          [4]   :   30

          [5]   :  500

          [6]   :   40

        Enter the valid pos:  7

        Invalid Position


                          		ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                                	5. Exit

        Enter your choice: 4

        The array elements are..

        (index  : value)

          [1]   :   10

          [2]   :   20

          [3]   :  300

          [4]   :   30

          [5]   :  500

          [6]   :   40

        Enter the valid pos: 0

        Invalid Position


                          		ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                                		5. Exit

        Enter your choice: 4

        The array elements are..

        (index  : value)

          [1]   :   10

          [2]   :   20

          [3]   :  300

          [4]   :   30

          [5]   :  500

          [6]   :   40

        Enter the valid pos: 7

        Invalid Position


                          		ARRAY DEMONSTRATION

                1. Read Array Elements          2. Write Array Elements

                3. Insert an Element            4. Delete an Element

                                	5. Exit

        Enter your choice: 5

		exit
/*