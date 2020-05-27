#include <stdio.h>
#include <string.h>

int main()
{
	char text[100] = "kebertanggungjawaban";
	int i,j;
	printf("Text : %s\n",text);
	for(i = 1;i<=strlen(text);i++)
	{
		if (i%4==0)
		{
			printf("\n  %c\n",text[i-1]);
			for(j=i+3;j>i;j--)
			{
				printf("%c",text[j-1]);
			}
			i+=4;
			printf("\n%c\n",text[i+1]);
		}
		else
		{
			printf("%c",text[i-1]);
		}
	}
}
