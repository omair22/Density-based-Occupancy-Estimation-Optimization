#include<stdio.h>
#include<stdlib.h>
#include "ReturnMatrix.h"
#include"Decision.h"
//#include"Structures.h"
void main()
{
    struct Device fan[2];
    struct Device light[3];

    struct Room R = inp();
    int m=R.row, n=R.column;
    struct Device D1[R.numberoffans];
    struct Device D2[R.numberoflights];
    values(D1,D2);

    float **  distribution_matrix=diff_mat(5,5);
    printf("Density\n");
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
             printf("%.1f ",distribution_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    float** cov1=Coverage(&(D1[0]),m,n);
    printf("\nFan 1 Coverage area matrix\n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%.0f ",cov1[i][j]);
        }
        printf("\n");
    }

    float** cov2=Coverage(&(D1[1]),m,n);
    printf("\nFan 2 Coverage area matrix\n");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%.0f ",cov2[i][j]);
        }
        printf("\n");
    }
printf("\n\n");
    Decision(distribution_matrix,D1,m,n,2);
    for(int i=0;i<R.numberoffans;i++)
     {
        printf("FAN %d   ",i);
        if(D1[i].status == 1)
            printf("Turned ON\n");
        else
            printf("Turned OFF\n");
     }
}


