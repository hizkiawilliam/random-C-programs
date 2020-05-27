#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define LIMIT 30
void gacha();
void loading();
typedef int test;

test data = 0;
int token = 10,i;
char store[100][LIMIT] = {};
int main()
{
	system("cls");
	printf("Tokenmu adalah : %d\n",token);
	switch(getch())
	{
		case '1':
			if (token>0)
			{
				token--;
				loading();
				gacha();
				system("pause\n");
				main();
				break;
			}
			else
			{
				printf("Duitmu kurang mzz\n");
				system("pause\n");
				main();
				break;
			}
		case '2':
			for(i = 0;i<=data;i++)
			{
				printf("%s\n",store[i]);	
			}
			system("pause");
			main();
		case '3':
			if (token>2)
			{
				token -= 3;
				loading();
				gacha();
				loading();
				gacha();
				loading();
				gacha();
				system("pause\n");
				main();
				break;
			}
			else
			{
				printf("Duitmu kurang mzz\n");
				system("pause");
				main();
				break;
			}
	}
}

void gacha()
{
	time_t t;
	srand((unsigned) time(&t));
	char weap1[5][30] = {"Iron Sword","Steel Sword","Glass Sword","Silver Sword","Stone Sword"};
	char weap2[5][30] = {"Blazing Steel Sword","Razor Sword","Zaptor Sword","Dark Sword","Fire Sword"};
	char weap3[5][30] = {"Dragon Sword","Legendary Sword","Heavenly Sword","Sky Night Sword","Ruined Sword"}; 
	char temp[30];
	int sword;
	int r = rand()%5;
	int chance = rand()%100;
	//printf("%d\n",chance);
	if (chance <= 50)
	{
		sword = 1;
	}
	else if (chance >= 51 && chance <=80)
	{
		sword = 2;
	}
	else if (chance >= 81 && chance <=100)
	{
		sword = 3;
	}
	switch(sword)
	{
		case 1:
			strcpy(temp,weap1[r]);
			strcpy(store[data],temp);
			data++;
			printf("%s\n",temp);
			break;		
		case 2:
			strcpy(temp,weap2[r]);
			strcpy(store[data],temp);
			data++;
			printf("%s\n",temp);	
			break;
		case 3:
			strcpy(temp,weap3[r]);
			strcpy(store[data],temp);
			data++;
			printf("%s\n",temp);	
			break;
	}
}

void loading()
{
	for(i=0; i<5; i++)
    {
        printf(".");
        Sleep(200);											
    }
}
