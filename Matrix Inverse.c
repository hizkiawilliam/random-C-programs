#include<stdio.h>
 
int main(){
 
  	int a[3][3] = {{3,1,0},{2,1,1},{6,2,2}},i,j;
	float adjoin_a[3][3],kof_a[3][3],inv_a[3][3];
  	float determinant=0;
 	/*
  	printf("Enter the 9 elements of matrix: ");
  	for(i=0;i<3;i++)
      	for(j=0;j<3;j++)
           scanf("%d",&a[i][j]);
 	*/
  	printf("\nThe matrix is\n");
  	for(i=0;i<3;i++){
      	for(j=0;j<3;j++)
      	{
           printf("%d  ",a[i][j]);
           if(j==2)
           	{
                printf("\n\n");
        	}
    	}	
  	}
 
  	determinant = determinant + ((a[0][0]*a[1][1]*a[2][2])+(a[0][1]*a[1][2]*a[2][0])+(a[0][2]*a[1][0]*a[1][2]));
  	determinant = determinant - ((a[0][2]*a[1][1]*a[2][0])+(a[1][2]*a[2][1]*a[0][0])+(a[2][2]*a[1][0]*a[0][1]));
      	
 	printf("\nDet a = %.2f",determinant);
 	
 	for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
        {
            kof_a[0][0] =   (a[1][1]*a[2][2])-(a[1][2]*a[2][1]);
            kof_a[0][1] = -((a[1][0]*a[2][2])-(a[1][2]*a[2][0]));
            kof_a[0][2] =   (a[1][0]*a[2][1])-(a[1][1]*a[2][0]);
            kof_a[1][0] = -((a[0][1]*a[2][2])-(a[0][2]*a[2][1]));
            kof_a[1][1] =   (a[0][0]*a[2][2])-(a[0][2]*a[2][0]);
            kof_a[1][2] = -((a[0][0]*a[2][1])-(a[0][1]*a[2][0]));
            kof_a[2][0] =   (a[0][1]*a[1][2])-(a[0][2]*a[1][1]);
            kof_a[2][1] = -((a[0][0]*a[1][2])-(a[1][2]*a[1][0]));
            kof_a[2][2] =   (a[0][0]*a[1][1])-(a[1][1]*a[1][0]);
        }
 	
 	for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
        {
            adjoin_a[j][i] = kof_a[i][j];
        }
 	
 	for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
        {
            inv_a[i][j] = adjoin_a[i][j]/determinant;
        }
   	printf("\nInverse of matrix is: \n\n");
   	for(i=0; i<3; ++i)
        for(j=0; j<3; ++j)
        {
            printf("%.2f  ",inv_a[i][j]);
            if(j==2)
                printf("\n\n");
        }
   	return 0;
}
