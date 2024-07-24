// Importing to get RSSI values difference matrix
#include"DifferenceMatrix.h" 
// Returns the normalized population distribution matrix  
float** diff_mat(int row,int column)   
{ 
    int i,j; 
    float dif; 
    int max=0; 
    int min=100; 
    int** difference_matrix=diff_rssi(5,5); 
    float **distribution_matrix; 
// Creating a 2-D array to store the values of normalized difference matrix 
    distribution_matrix=(float**)malloc(sizeof(float*)*row); 
    for(i=0;i<row;i++) 
    { 
        *(distribution_matrix+i)=(float*)malloc(sizeof(float)*column); 
    } 
// Finding minimum value of difference matrix 
    for(i=0;i<row;i++) 
    { 
        for(j=0;j<column;j++) 
        { 
            if(difference_matrix[i][j]<min) 
            min=difference_matrix[i][j]; 
        } 
    } 
// Finding maximum value of difference matrix 
    for(i=0;i<row;i++) 
    { 
        for(j=0;j<column;j++) 
        { 
            if(difference_matrix[i][j]>max) 
            max=difference_matrix[i][j]; 
        } 
    } 
// Normalizing difference matrix and storing it in distribution matrix 
    for(i=0;i<row;i++) 
    { 
        for(j=0;j<column;j++) 
        { 
            // Min-Max scaling            
            float dif = difference_matrix[i][j]-min; 
            dif = dif /(max - min); 
            distribution_matrix[i][j]=dif; 
        } 
    } 
    return distribution_matrix; 
} 

