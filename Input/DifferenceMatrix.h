//Returns the homogenized RSSI value difference matrix
int** diff_rssi(int row,int column)
{
    int i,j,p1,p2;
    int **difference_matrix;
    difference_matrix=(int**)malloc(sizeof(int*)*row); // Creating a matrix to store the difference of conscutive RSSI values
    for(i=0;i<row;i++)
    {
        *(difference_matrix+i)=(int*)malloc(sizeof(int)*column);

    }

     FILE *fp1,*fp2;

     fp1=fopen("t_0.txt","r");
     fp2=fopen("t_1.txt","r");

     int x,y,k,diff;
     k=0;

    p1=0;p2=0;
    while( (!feof(fp1)) && (!feof(fp2)) )       // Reading from file and performing subtraction between consecutive values in the two input files
    {

            fscanf(fp1,"%d",&x);
            fscanf(fp2,"%d",&y);
            diff=y-x;

           	if(diff<0)
         {
             diff=diff+100;     // Adding 100 to homogenize the values as, the considered range of RSSI is -100 to 0.
         }
         else
         {
             diff=diff;
         }


            // For sorting the the result in the form of the required matrix
            difference_matrix[p1][p2]=diff;
            p2++;
            if(p2==column){p2=0;p1++;}
            if((p2==column)||(p1==row)){ break;}

     }




      fclose(fp1);
      fclose(fp2);
      return difference_matrix;
}
