#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *huruf(float nilai);
struct DaftarNilai {
   	int NPM;
   	char  nama[50];
   	float nilai;
   	char  nilaiHuruf[1];
   	struct DaftarNilai *next;
};

struct DaftarNilai *head;
typedef struct DaftarNilai StackNode;
typedef StackNode *StackNodePtr;

//display the list
void printList() {

   struct DaftarNilai *ptr = head;
   //start from the beginning
   printf( "\nNPM        \tNama Mahasiswa    \tNilai\tNilai Huruf\tAddress\n\n");
   while(ptr != NULL) 
   {    
   		printf( "%d\t%s\t%.2f\t%s\t\t%u\n", ptr->NPM, ptr->nama, ptr->nilai, ptr->nilaiHuruf,ptr);    
      	ptr = ptr->next;
   }

}

//insert link at the first location
void insert(int NPM, char nama[50], float nilai) {
   //create a link
   	struct DaftarNilai *link = malloc(sizeof(struct DaftarNilai));

   //link->key = key;
   	link->NPM = NPM;
   	strcpy( link->nama, nama);
   	link->nilai = nilai;
   	strcpy( link->nilaiHuruf, huruf(nilai));

   //point it to old first DaftarNilai
   	link->next = head;

   //point first to new first DaftarNilai
   	head = link;
}
int pop( StackNodePtr *topPtr )
{
	StackNodePtr tempPtr; /* temporary node pointer */
	int popValue; /*node value*/
	char popChar[50]; /*node value*/
	
	tempPtr = *topPtr;
	popValue = ( *topPtr )->NPM;
	//strcpy(( *topPtr )->nama,popChar);
	popValue = ( *topPtr )->nilai;
	*topPtr = ( *topPtr )->next;
	free( tempPtr );

	return popValue;
} /* end function pop */
int main() {
	
   insert(1706042806,"Hizkia William Eben",88);
   insert(1706041231,"Alexander Patrick",78);
   pop(&head);
   insert(1706041231,"Darrell Yonathan",90);
   pop(&head);
   insert(1706041231,"Geraldy Christanto",82);
   
   /*
   insert(20);
   insert(30);
   insert(1);
   insert(40);
   insert(56); 
*/
   printList();
   return 0;
}

char *huruf(float nilai)
{
	if (nilai >= 85)
	{
		return "A";
	}
	else if (nilai >= 80)
	{
		return "A-";
	}
	else if (nilai >= 75)
	{
		return "B+";
	}
	else if (nilai >= 70)
	{
		return "B";
	}
	else if (nilai >= 65)
	{
		return "B-";
	}
	else if (nilai >= 60)
	{
		return "C+";
	}
	else if (nilai >= 55)
	{
		return "C";
	}
	else if (nilai < 55)
	{
		return "D";
	}
}
