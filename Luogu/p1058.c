#include <stdio.h>

int main()
{
    int a[7],most,i,x,y,day;
    for(int j=0;j<7;j++)
    {
        scanf("%d %d",&x,&y);
        a[j]=x+y;
    }
    most=a[0];
    for(i=1;i<7;i++)
    {
        if (a[i]>most)
        {
            most=a[i];
            day=i;
        }
    }
    printf("%d",day+1);
    return 0;
}
