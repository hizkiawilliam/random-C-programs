/* Fig. 12.13: fig12_13.c
Operating and maintaining a queue */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/* self-referential structure */
struct Node {
	int data; /* define data as a char */
	struct Node *nextPtr; /* Node pointer */
}; /* end structure Node */

typedef struct Node Node;
typedef Node *NodePtr;

/* function prototypes */
bool search(struct Node* topPtr, int x);
void push( NodePtr *topPtr, int info );
int pop( NodePtr *topPtr );
int isEmpty( NodePtr topPtr );
void printStack( NodePtr currentPtr );
void instructions( void );

/* function main begins program execution */
int main( void )
{
	NodePtr stackPtr = NULL; /* points to stack top */
	int choice; /* user's menu choice */
	int value; /* char input by user */

	instructions(); /* display the menu */
	printf( "? " );
	scanf( "%d", &choice );

	/* while user does not enter 3 */
	while ( choice != 4 ) {
	switch( choice ) {
		/* push value onto stack*/
		case 1:
			printf( "Enter an integer: " );
			scanf( "%d", &value );
			push( &stackPtr, value );
			printStack( stackPtr );
			break;
		/* pop value */
		case 2:
			/* if queue is not empty */
			if ( !isEmpty( stackPtr ) ) {
			printf( "The poped value is %d.\n", pop(&stackPtr) );
			} /* end if */
			printStack( stackPtr );
			break;
		case 3:
			printf( "Enter an integer: " );
			scanf( "%d", &value );
			search( stackPtr, value)? printf("Yes\n\n") : printf("No\n\n");
			break;
		default:
			printf( "Invalid choice.\n\n" );
			instructions();
			break;
	} /* end switch */

	printf( "? " );
	scanf( "%d", &choice );
	} /* end while */
	
	printf( "End of run.\n" );
	return 0; /* indicates successful termination */
} /* end main */
	
	/* display program instructions to user */
void instructions( void )
{
	printf ( "Enter your choice:\n"
	" 1 to push a value on the stack\n"
	" 2 to pop a value off the stack\n"
	" 3 to search an element\n"
	" 4 to end program\n" );
} /* end function instructions */

/* insert a node a queue tail */
void push( NodePtr *topPtr, int info )
{
	NodePtr newPtr; /* pointer to new node */
	newPtr = malloc( sizeof( Node ) );
	/* insert the node at stack top */
	if ( newPtr != NULL ) 
	{ /* is space available */
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	} /* end if */
	else 
	{
		printf( "%d not inserted. No memory available.\n", info );
	} /* end else */
} /* end function push */

/* remove node from queue head */
int pop( NodePtr *topPtr )
{
	NodePtr tempPtr; /* temporary node pointer */
	int popValue; /*node value*/
	
	tempPtr = *topPtr;
	popValue = ( *topPtr )->data;
	*topPtr = ( *topPtr )->nextPtr;
	free( tempPtr );

	return popValue;
} /* end function pop */

/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( NodePtr topPtr )
{
	return topPtr == NULL;
} /* end function isEmpty */

/* Checks whether the value x is present in linked list */
bool search(struct Node* topPtr, int x)
{ 
    struct Node* current = topPtr;  // Initialize current 
    while (current != NULL) 
    { 
        if (current->data == x) 
            return true; 
        current = current->nextPtr; 
    } 
    return false; 
} 

/* Print the queue */
void printStack( NodePtr currentPtr )
{
	/* if queue is empty */
	if ( currentPtr == NULL ) 
	{
		printf( "Stack is empty.\n\n" );
	} /* end if */
	else 
	{
		printf( "The stack is:\n" );
		/* while not end of queue */
		while ( currentPtr != NULL ) 
		{
			printf( "%d --> ", currentPtr->data );
			currentPtr = currentPtr->nextPtr;
		} /* end while */
		printf( "NULL\n\n" );
	} /* end else */
} /* end function printStack */
