#include <stdio.h>
#include <stdlib.h>

int lvl = 1;
long int expi = 0;
long int maxexp = 100;

int main(){
	system("cls");
	int input;
	printf("Level\t: %d",lvl);
	printf("\nExp\t: %lu/%lu",expi,maxexp);
	printf("\nInput\t: ");
	getch();
	expi += 1;
	while(1){
		if (expi>=maxexp){
			lvl += 1;
			maxexp *= 1.18;
			maxexp += lvl*10;
		}	
		else{
			break;
		}
	}
	main();
}
