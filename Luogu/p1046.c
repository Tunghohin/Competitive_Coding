#include "stdio.h"
int bubble(int a[],int len)
{
    int i,j,temp,sum;
    sum=0;
    for(i=len-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                sum=sum+1;
            }
        }
    }
    return sum;
}
int main(void)
{
    int sum,len;
    scanf("%d",&len);
    int a[len];
    for(int i=0;i<len;i++)
    {
        scanf("%d",&a[i]);
    }
    sum=bubble (a,len);
    printf("%d",sum);
    return 0;
}




