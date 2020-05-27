#include <stdio.h>

int main()
{
    int input[10][10], transpose[10][10], row, col, i, j;
    printf("Masukkan jumlah baris dan kolom matriks: ");
    scanf("%d %d", &row, &col);

    printf("\nMasukkan elemen dari matriks:\n");
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
        {
            printf("Masukkan elemen a%d%d: ",i+1, j+1);
            scanf("%d", &input[i][j]);
        }

    printf("\nMatriks input: \n");
    for(i=0; i<row; ++i)
        for(j=0; j<col; ++j)
        {
            printf("%d  ", input[i][j]);
            if (j == col-1)
                printf("\n\n");
        }

    for(i=0; i<row; ++i)
        for(j=0; j<col; ++j)
        {
            transpose[j][i] = input[i][j];
        }

    printf("\nHasil transpose:\n");
    for(i=0; i<col; ++i)
        for(j=0; j<row; ++j)
        {
            printf("%d  ",transpose[i][j]);
            if(j==row-1)
                printf("\n\n");
        }
    return 0;
}
