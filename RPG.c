#include <stdio.h>
#include <stdlib.h>
float attack();

int level = 1;
int health = 100;;
int health_enemy = 1000;
int att = 100;

int main()
{
	printf("\n%.5f",attack());
	printf("\nHealth : %.0f",(float)health);
	printf("\nHealth enemy : %.0f",(float)health_enemy);
	printf("\n||===================================================||");
	printf("\n||Select move :                                      ||");
	printf("\n||1. Attack                   2. Skill               ||");
	printf("\n||3. Item                     4. Run                 ||");
	printf("\n||===================================================||");
	switch(getch())											//switch case berdasarkan getch()
    {
    case '1':
        health_enemy -= attack();
        printf("%.0f",attack());
        system("cls");
        main();
        break;
    default:												
    	printf("\n\n\t\t\t\t\tWrong input!\n");
    	printf("\t\t\t\t\tPlease input choice between 1 to 7 only!\n\n");
    	printf("\t\t\t\t\t");
    	system("pause");
		system("cls");
    }
}

float attack()
{
	time_t t;
	srand((unsigned) time(&t));	
	int r = rand()%40;
	int ran[41] = {-20,-19,-18,-17,-16,-15,-14,-13,-12,-11-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	float final_att = att + (float)(ran[r]*att/100);
	return final_att;
}

