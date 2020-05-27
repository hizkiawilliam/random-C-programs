#include <stdio.h>

int total;
int main()
{
	int bawah, atas, gibu;
	printf("Masukkan batas bawah:");
	scanf("%d",&bawah);
	printf("Masukkan batas atas:");
	scanf("%d",&atas);
	
	for(gibu=bawah;gibu<=atas;gibu++){
		total = 0;
		split(gibu);
//		printf("%d %d\n",total, gibu);  
		if(total == gibu){
			printf("%d ",gibu);   	
		}	 	
	}
    return 0;
}

int faktorial(int input)
{
	int i;
    unsigned long long factorial = 1;
    if(input == 0){
    	return 1;
	}
    for(i=1; i<=input; ++i)
    {
        factorial *= i;              // factorial = factorial*i;
    }
    return factorial;
}

int split(int num){
  	int temp,factor=1;
 	temp=num;
  	while(temp){
      	temp=temp/10;
      	factor = factor*10;
  	}
  	while(factor>1){
		total += num/factor;
      	num = num % factor;
  	}
  	return 0;
}
