#include "NewDensity.h" // This has some helper files

float sum(struct Device F[],int n)// calculates the total sum covered by the array of Devices
{
    float s=0;
    for(int i=0; i<n;i++)
    {
        s = s + F[i].Den;
    }

    return s;
}

int Stat(struct Device F[],int n)//returns -1 if all the Devices are turned on
{
    for(int i=0; i<n;i++)
    {
        if(F[i].status == 0)
            return 1;
    }
    return -1;
}
int Decision(float** Density, struct Device f[],int m, int n, int deviceCount)
{
    if((sum(f,deviceCount)<1.0)||(Stat(f,deviceCount) == 1)) // checks whether the density is completely covered or All the Devices have been turned on
    {

        int max_index = -1; // Stores the index of device with max percentage of
        float max_density = 0; // temp variable to find the max_index
        for(int i=0; i<deviceCount; i++)// loop to find the device with maximum coverage
        {
            if(f[i].status == 0)
            {
                Percent(Density, &f[i],m,n);

                if(max_density <= f[i].Den)
                {
                    max_index = i;
                    max_density = f[i].Den;
                }
            }

        }
        if(max_density<= 0.05) // if the maximum coverage is less than 5% then we just exist algo
        {
            for(int i=0;i<deviceCount;i++)// to make all the densities of devices that are not turned on as 0
            {
                if(f[i].status == 0 )
                    f[i].Den = 0;
            }
            return 1;
        }
        f[max_index].status = 1;
        for(int i=0;i<deviceCount;i++)// to make all the densities of devices that are not turned on as 0
        {
            if(f[i].status == 0)
                    f[i].Den = 0;
        }
        float ** NewDen=NewDensity(Density,&(f[max_index]) , m , n);// creating new density for recursion
        Decision(NewDen,f,m,n,deviceCount);// Recursion with new density
    }
    else
        return 0;

}
