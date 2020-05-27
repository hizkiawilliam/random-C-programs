#include <stdio.h>
//#define LIMIT 7
void elloy(int j, char chr);
void eben(int k);
int shift = 4, LIMIT = 7, i,count = 0;
int test;
char chr,a,b,c,d,e,f,g;

int main(){
	
//	scanf("%d\n",&shift);
	for(i=0;i<LIMIT;i++){
		scanf("%s",&chr);	
		chr += shift;
		elloy(i, chr);
		printf("%d",i);
		chr = 0;
		count++;
	}
//	printf("%d\n",count);
	printf("%s\n",a);
	for(i=0;i<count;i++){
		eben(i);
	}
}

void elloy(int j, char chr){
	switch(j){
			case'0':
				a = chr;
				break;
			case'1':
				b = chr;
				break;
			case'2':
				c = chr;
				break;
			case'3':
				d = chr;
				break;
			case'4':
				e = chr;
				break;
			case'5':
				f = chr;
				break;
			case'6':
				g = chr;
				break;
		}
}

void eben(int k){
	switch(i){
			case'0':
				printf("%s\n",a);
				break;
			case'1':
				printf("%s\n",b);
				break;
			case'2':
				printf("%s\n",c);
				break;
			case'3':
				printf("%s\n",d);
				break;
			case'4':
				printf("%s\n",e);
				break;
			case'5':
				printf("%s\n",f);
				break;
			case'6':
				printf("%s\n",g);
				break;
		}
}
