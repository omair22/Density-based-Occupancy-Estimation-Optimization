struct Room{ /* Creating structure Room with members */
    int column;
    int row;
    int numberoffans;
    int numberoflights;
};
struct Device { /* Creating structure Device with members */
    int status;
    int radius;
    int pos[2];
    float Den;
    float power;
};

struct Room inp()
{
    struct Room R;
    FILE *file = fopen("Metadata.txt","r+"); /*  Reading the file */

    fscanf(file,"%d,%d,%d,%d",&R.row,&R.column,&R.numberoffans,&R.numberoflights); /* Inserting the values of room in structure Room.*/
    fclose(file); /*  Closing the file */
    return R;

}
void values(struct Device* D1,struct Device* D2)
{
    struct Room R;
    FILE *f = fopen("Metadata.txt","r+"); /*  Reading the file */
    int i=0,k=0;
    fscanf(f,"%d,%d,%d,%d",&R.row,&R.column,&R.numberoffans,&R.numberoflights);  /* Inserting the values of room in structure Room.*/

    for(i=0; i<R.numberoffans; i++)  /*  Loop is created for inserting values of fans in structure Device*/
    {
        fscanf(f,"%d,%d,%d,%f",&D1[i].pos[0],&D1[i].pos[1],&D1[i].radius,&D1[i].power);
        D1[i].status = 0;

    }
    for(k=0; k<R.numberoflights; k++)  /*  Loop is created for inserting values of lights in structure Device*/
    {
        fscanf(f,"%d,%d,%d,%f",&D2[k].pos[0],&D2[k].pos[1],&D2[k].radius,&D2[k].power);
        D1[i].status = 1;
    }
    fclose(f); /*  Closing the file */
}


