#include <stdio.h>

int main()
{
	int num,i,j,length=0;
	printf("Masukkan integer(decimal) : ");
	scanf("%d",&num);
	int rem[10] = {};
	int rem_rev[10] = {};
	for (i=0;num!=0;i++)
	{
		rem[i] = num % 8;
		num = num/8;
		length += 1;
	}
	for(i=0,j=length-1;i<length;i++,j--)
	{
		rem_rev[j] = rem [i];
	}
	printf("Hasil dalam octal : ");
	for(i=0;i<length;i++)
	{
		printf("%d",rem_rev[i]);
	}
}
