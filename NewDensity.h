#include "Cov.h" // importing to get the coverage matrix

// Calculates the new density by removing the area covered by the passes fan
float** NewDensity(float ** Density, struct Device* F, int m , int n)
{

    float **NewDen;
    NewDen = malloc(sizeof(float*) * m);// creating a new matrix to store the new density
    for(int i = 0; i < m; i++)
        NewDen[i] = malloc(sizeof(float*) * n);
    float ** covMat = Coverage(F,m,n);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
        {
            // area covered by this matrix need to be made zero [which is represented with 1]
            if (covMat[i][j] == 1)
                NewDen[i][j] = 0;
            else
                NewDen[i][j] = Density[i][j];
        }
    }
    return NewDen;
}


// Calculates the fraction of population density covered by the passed Device
void Percent(float ** Density, struct Device *F,int m, int n)
{
    float **cov = Coverage(F,m,n);
    float sum = 0, tot=0;
    for(int i=0; i<m; i++)
        for (int j=0; j<n; j++)
        {
            //summation of values where both cells are non zero
            sum = sum + Density[i][j] * cov[i][j];
            tot = tot + Density[i][j];

        }
    F->Den= (sum/tot);
}
