#include <stdio.h>
#include <stdlib.h>

struct DaftarNilai {
   int data;
   struct DaftarNilai *next;
};

struct DaftarNilai *head = NULL;
struct DaftarNilai *current = NULL;

//display the list
void printList() {

   struct DaftarNilai *ptr = head;

   printf("\n[head] =>");
   //start from the beginning
   while(ptr != NULL) {        
      printf(" %d %u=>",ptr->data,ptr);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}

//insert link at the first location
void insert(int data) {
   //create a link
   struct DaftarNilai *link = (struct DaftarNilai*) malloc(sizeof(struct DaftarNilai));

   //link->key = key;
   link->data = data;

   //point it to old first DaftarNilai
   link->next = head;

   //point first to new first DaftarNilai
   head = link;
}

int main() {
   insert(10);
   insert(20);
   insert(30);
   insert(1);
   insert(40);
   insert(56); 

   printList();
   return 0;
}
