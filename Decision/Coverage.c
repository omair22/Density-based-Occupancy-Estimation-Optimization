#include<stdio.h>
#define m 9 // no. rooms in the room
#define n 9 // no. columns in the room

struct Fan // Structure to store the device specifications
{
    int status;
    int radius;
    int pos[2];
    float power;
};
float** Coverage(struct Fan F) // This function is for finding the coverage of one fan in the room
{
    float **cov; // creating 2d array dynamically
    cov = malloc(sizeof(float*) * m);

    for(int i = 0; i < m; i++) {
        cov[i] = malloc(sizeof(float*) * n);
    }
    for(int i=0;i<m;i++) // this part fills cells with 1 if that cell is covered by the fan else with 0
     {
         for(int j=0;j<n;j++)
        {
             if((i<=(F.pos[0] + F.radius) && i>=(F.pos[0] - F.radius)) && (j<=(F.pos[1] + F.radius) && j>=(F.pos[1] - F.radius)))
                 cov[i][j] = 1;
             else
                cov[i][j] = 0;
        }
    }
    cov[F.pos[0]][F.pos[1]] = 9; //for visual understanding making pos fan as 10
    return cov;
}
/*void Decision(float D[2][2])
{
    printf("%d",&D[0][0]);
}*/
void main()
{
    struct Fan fan; // creating struct object and filling them
    fan.pos[0] = 4;
    fan.pos[1] = 4;
    fan.radius = 3;
    fan.status = 0;
    fan.power  = 0;
    float **b=Coverage(fan);// reading the coverage matrix from function
    for(int i=0;i<m;i++)// displaying the matrix
     {
         for(int j=0;j<n;j++)
        {
             printf("%.0f",(b[i][j]));
             printf("  ");
        }
         printf("\n");
    }
}
