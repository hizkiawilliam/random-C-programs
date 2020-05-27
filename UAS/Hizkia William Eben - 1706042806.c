//Hizkia William Eben
//1706042806

#include <stdio.h>
#include <stdlib.h>
#define LIMIT_LAYER 3 //set limit layer
char *huruf(float nilai);

struct treeNode {
	struct treeNode *leftPtr;
   	int data;
   	struct treeNode *rightPtr;
};

typedef struct treeNode TreeNode;
typedef TreeNode *TreeNodePtr;

void insertNode( TreeNodePtr *treePtr, int value );
void inOrder( TreeNodePtr treePtr );

void insertNode( TreeNodePtr *treePtr, int value )
{
	if ( *treePtr == NULL ) {//jika input merupakan data pertama
		*treePtr = malloc( sizeof( TreeNode ) );
	
		if ( *treePtr != NULL ){
			( *treePtr )->data = value; //set data A dari value
			( *treePtr )->leftPtr = NULL;
			( *treePtr )->rightPtr = NULL;
		}
		else {
			printf( "%d not inserted. No memory available.\n", value );
		}
	} 
	else{ //jika bukan data pertama yang diinput
		insertNode( &( ( *treePtr )->leftPtr ), value ); //data cabang kiri
		insertNode( &( ( *treePtr )->rightPtr ), value ); //data cabang kanan
	}
}

void insertNodeRight( TreeNodePtr *treePtr, int value )
{
	insertNode( &( ( *treePtr )->rightPtr ), value );
}

void insertNodeLeft( TreeNodePtr *treePtr, int value )
{
	insertNode( &( ( *treePtr )->leftPtr ), value );
}

void inOrder( TreeNodePtr treePtr ){ 
	int count = 0;
	int layer = LIMIT_LAYER;
	if ( treePtr != NULL ) {
		inOrder( treePtr->leftPtr );
		if (count == 0){
			printf( "\t%d", treePtr->data );
			count += 1;	
		}
		inOrder( treePtr->rightPtr );
	}
}

int main(){
	int input, input_l, input_r, layer;
	TreeNodePtr rootPtr = NULL;
	printf("Input integer : ");
	scanf("%d",&input);
	insertNode( &rootPtr, input );
	input_l = input;
	input_r = input;
	for(layer = 1;layer<LIMIT_LAYER;layer++)
	{
		if (input_l % 2 == 0){//cek apakah input habis dibagi 2
			input_l /= 2;
			insertNodeLeft( &rootPtr, input_l );
		}
		else{ //jika tidak bisa dibagi 2, maka nilai diset 0
			insertNodeLeft( &rootPtr, 0 );
		}
		if (input_r % 3 == 0){//cek apakah input habis dibagi 3
			input_r /= 3;
			insertNodeRight( &rootPtr, input_r );
		}
		else{ //jika tidak bisa dibagi 3, maka nilai diset 0
			insertNodeRight( &rootPtr, 0 );
		}
	}	
	printf( "\nPrint trees with inOrder traversal is:\n" );
	inOrder( rootPtr );
}
