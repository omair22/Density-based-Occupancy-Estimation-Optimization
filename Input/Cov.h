#include "Structures.h"

float** Coverage(struct Device *F,int m, int n) // This function is for finding the coverage of one Device in the room
{
    float** cov; // creating 2d array dynamically
    cov = malloc(sizeof(float*) * m);

    for(int i = 0; i < m; i++)
    {
        cov[i] = malloc(sizeof(float*) * n);
    }
    for(int i=0; i<m; i++) // this part fills cells with 1 if that cell is covered by the Device else with 0
    {
        for(int j=0; j<n; j++)
        {
            if((i<=(F->pos[0] + F->radius) && i>=(F->pos[0] - F->radius)) && (j<=(F->pos[1] + F->radius) && j>=(F->pos[1] - F->radius)))
                cov[i][j] = 1;
            else
                cov[i][j] = 0;
        }
    }
    return cov;
}
