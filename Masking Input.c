#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *scan(char text[])
{
	char ch;
	int i = 0;
	while(1)
	{
		ch = getch();
		if(ch==13)
	    {
	    	break;
	    }
	    else if(ch==8)
	    {
	    	if(i>0)
	    	{
	    		i--;
	        	printf("\b ");
	        	text[i] = ch;	
			}
			else
			{
				continue;
			}
	    }
	    else
	    {
	        text[i] = ch;
			i++;	
			ch = 'S';
		}
		printf("%c",ch);
	}
	text[i] = '\0';
	printf("\n");
	return text;
}

int main()
{
	while(1)
	{
		system("cls");
		char pass[];
		printf("Input something\t:");
		scan(pass);
		printf("Your something\t:");
		printf("%s\n",pass);
		system("pause");	
	}
	
}
