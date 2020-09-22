#include<stdio.h>
struct fan
{
    int pos[2];
    int status;
    int radius;
};

void Decision(float D[2][2])
{
    printf("%d",&D[0][0]);
}
void main()
{
    float F[2][2]={{10,12},{14,16}};
    Decision(F);
}
