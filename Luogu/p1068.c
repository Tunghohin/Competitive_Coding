#include <stdio.h>
#include <math.h>

int n,m;
int s[102],k[10002][102];
int main()
{
    int num,score,sum=0,i,j,f;
    scanf("%d%d",&n,&m);
    m=floor(m*1.5);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&num,&score);
        k[num][score]++;
        s[score]++;
    }
    for(i=100;sum<m;i--)
    {
        sum=s[i]+sum;
    }
    printf("%d %d\n",i+1,sum);
    int line=i+1;
    for (i=100;i>=line;i--)
    {
        for (j=1000;j<=10000;j++)
        {
            if (k[j][i]!=0)
            {
                printf("%d %d\n",j,i);
            }
        }
    }
    return 0;
}
