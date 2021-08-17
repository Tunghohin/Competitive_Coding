#include <stdio.h>

int main(void)
{
    int i,j;
    for(j=1;j<=9;j++)
    {
        if(2*j%10!=0)
        {
            printf("%d %d %d\n",j,2*j,3*j);
        }
    }
    for(i=1;i<=333;i++)
    {
        if(i%10!=0&&(i/10)%10!=0&&2*i%10!=0&&(2*i/10)%10!=0&&3*i%10!=0&&(3*i/10)%10!=0)
        {
            printf("%d %d %d\n",i,2*i,3*i);
        }
    }
    return 0;
}
