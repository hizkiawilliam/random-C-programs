#include <stdio.h>
#include <windows.h>
#define true 1
#define false 0

int main()
{
	system("color 0A");
	int num[5] = {1,2,3,4,5};
	int i,input;
	printf("Num = [1,2,3,4,5]\n");
	printf("Masukkan angka: ");
	scanf("%d",&input);
	int ada = false;
	for (i=0;i<5;i++)
	{
		if (input == num[i])
		{
			ada = true;
		}
	}
	(ada == true)?printf("Angka ada\n\n"):printf("Angka tidak ada\n\n");
	return 0;
}
