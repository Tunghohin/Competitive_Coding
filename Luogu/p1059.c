#include <stdio.h>
int main(void)
{
    int n,temp;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if (a[i]==a[j])
            {
                for(int k=j+1;k<n;k++)
                {
                    a[k-1]=a[k];
                }
                n=n-1;
                j=i;/*坑位，连续重复时若不把j复位到i处因j已经加1,会直接跳过第二个重复{20 40 321 67 40 40 89 15}重复的40*/
            }
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if (a[i]>a[j])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    printf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
