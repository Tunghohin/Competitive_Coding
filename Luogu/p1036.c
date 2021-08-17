#include <stdio.h>

int n,k,sum=0,a[20],b[20],c[20];
int isprime(int x)
{
    int b,i;
    for(i=2;i<=x;i++)
    {
        if (x%i==0)
        {
            break;
        }
    }
    if (i==x)
    {
        b=1;
    }
    else
    {
        b=0;
    }
    return b;
}
void dfs(int step)
{

    if (step==k)
    {
        int pn,ans=0;
        for (int i=0;i<k;i++)
        {
            ans=ans+a[c[i]];
        }
        pn=isprime(ans);
        if (pn==1)
        {
            sum++;
        }
        return;
    }
    else
    {
        for (int i=c[step-1];i<n;i++)
        {
            if (b[i]==0)
            {
                c[step]=i;
                b[i]=1;
                dfs(step+1);
                b[i]=0;
            }
        }
        return;
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    dfs(0);
    printf("%d",sum);
    return 0;
}

