/* Fig. 12.13: fig12_13.c
Operating and maintaining a queue */
#include <stdio.h>
#include <stdlib.h>

/* self-referential structure */
struct stackNode {
	int data; /* define data as a char */
	struct stackNode *nextPtr; /* stackNode pointer */
}; /* end structure stackNode */

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

/* function prototypes */
void push( StackNodePtr *topPtr, int info );
int pop( StackNodePtr *topPtr );
void enqueue( StackNodePtr *headPtr, StackNodePtr *tailPtr, int value );
int dequeue( StackNodePtr *headPtr, StackNodePtr *tailPtr );
int isEmpty( StackNodePtr topPtr );
void printStack( StackNodePtr currentPtr );
void instructions( void );

/* function main begins program execution */
int main( void )
{
	StackNodePtr headPtr = NULL; /* initialize headPtr */
	StackNodePtr tailPtr = NULL; /* initialize tailPtr */
	//StackNodePtr stackPtr = NULL; /* points to stack top */
	int choice; /* user's menu choice */
	int value; /* char input by user */

	instructions(); /* display the menu */
	printf( "Choice :  " );
	scanf( "%d", &choice );

	/* while user does not enter 3 */
	while ( choice != 5 ) {
	switch( choice ) {
		/* push value onto stack*/
		case 1:
			printf( "Enter an integer: " );
			scanf( "%d", &value );
			if ( !isEmpty( headPtr ) ) {
				push( &headPtr, value );
			} /* end if */
			else{
				enqueue( &headPtr, &tailPtr, value );	
			}
			printStack( headPtr );
			break;
		/* pop value */
		case 2:
			/* if queue is not empty */
			if ( !isEmpty( headPtr ) ) {
			printf( "The poped value is %d.\n", pop(&headPtr) );
			} /* end if */
			printStack( headPtr );
			break;
		case 3:
			printf( "Enter an integer: " );
			scanf( "\n%d", &value );
			enqueue( &headPtr, &tailPtr, value );
			printStack( headPtr );
			break;
		/* dequeue value */
		case 4:
			/* if queue is not empty */
			if ( !isEmpty( headPtr ) ) {
			value = dequeue( &headPtr, &tailPtr );
			printf( "%d has been dequeued.\n", value );
			} /* end if */
			printStack( headPtr );
			break;
		default:
			printf( "Invalid choice.\n\n" );
			instructions();
			break;
	} /* end switch */

	printf( "Choice :  " );
	scanf( "%d", &choice );
	} /* end while */
	
	printf( "End of run.\n" );
	return 0; /* indicates successful termination */
} /* end main */

/* insert a node a queue tail */
void enqueue( StackNodePtr *headPtr, StackNodePtr *tailPtr, int value )
{
	StackNodePtr newPtr; /* pointer to new node */
	newPtr = malloc( sizeof( StackNode ) );
	if ( newPtr != NULL ) 
	{ /* is space available */
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		/* if empty, insert node at head */
		if ( isEmpty( *headPtr ) ) {
			*headPtr = newPtr;
		} /* end if */
		else {
			( *tailPtr )->nextPtr = newPtr;
		} /* end else */
		*tailPtr = newPtr;
	} /* end if */
	else 
	{
		printf( "%c not inserted. No memory available.\n", value );
	} /* end else */
} /* end function enqueue */

int dequeue( StackNodePtr *headPtr, StackNodePtr *tailPtr )
{
	char value; /* node value */
	StackNodePtr tempPtr; /* temporary node pointer */
	
	value = ( *headPtr )->data;
	tempPtr = *headPtr;
	*headPtr = ( *headPtr )->nextPtr;

	/* if queue is empty */
	if ( *headPtr == NULL ) 
	{
		*tailPtr = NULL;
	} /* end if */
	
	free( tempPtr );
	return value;
} /* end function dequeue */
	
/* display program instructions to user */
void instructions( void )
{
	printf ( "Enter your choice:\n"
	" 1 to push a value on the stack\n"
	" 2 to pop a value off the stack\n"
	" 3 to enqueue a value on the stack\n"
	" 4 to dequeue a value off the stack\n"
	" 5 to end program\n" );
} /* end function instructions */

/* insert a node a queue tail */
void push( StackNodePtr *topPtr, int info )
{
	StackNodePtr newPtr; /* pointer to new node */
	newPtr = malloc( sizeof( StackNode ) );
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
int pop( StackNodePtr *topPtr )
{
	StackNodePtr tempPtr; /* temporary node pointer */
	int popValue; /*node value*/
	
	tempPtr = *topPtr;
	popValue = ( *topPtr )->data;
	*topPtr = ( *topPtr )->nextPtr;
	free( tempPtr );

	return popValue;
} /* end function pop */

/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( StackNodePtr topPtr )
{
	return topPtr == NULL;
} /* end function isEmpty */

/* Print the queue */
void printStack( StackNodePtr currentPtr )
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


