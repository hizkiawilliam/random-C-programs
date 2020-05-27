#include <stdio.h>

main(){
	int A[10] = {5,3,6,4,2,1,7,10,8,9};
	int j,i,k,key;
	for (j = 0; j<10; j++){
		printf("%d ",A[j]);
	}
	printf("\n");
	for (j = 1; j<10; j++){
		key = A[j];
		i = j - 1;
		while ((i>=0)&&(A[i]<key)){
			A[i+1] = A[i];
			i = i-1;
			for (k = 0; k<10; k++){
				printf("%d ",A[k]);
			}
		printf("\n");
		A[i+1] = key;
		}
	}
	for (j = 0; j<10; j++){
		printf("%d ",A[j]);
	}
}
