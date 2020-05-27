#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct weapons {
   	char  name[50];
   	float damage;
   	struct weapons *next;
};

struct weapons *head;

//display the list
void printList() {

   struct weapons *ptr = head;
   //start from the beginning
   printf( "\nName        \tdamage\n\n");
   while(ptr != NULL) 
   {    
   		printf( "%s\t%.2f\n", ptr->name, ptr->damage);    
      	ptr = ptr->next;
   }

}

//insert link at the first location
void insert(char name[50], float damage) {
   //create a link
   	struct weapons *link = malloc(sizeof(struct weapons));

   //link->key = key;
   	strcpy( link->name, name);
   	link->damage = damage;

   //point it to old first DaftarNilai
   	link->next = head;

   //point first to new first DaftarNilai
   	head = link;
}

int main() {
	
   insert("Iron Sword",10);
   printList();
   return 0;
}

