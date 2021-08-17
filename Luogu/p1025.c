#include <stdio.h>
int a[10];
int n,k,sum,cnt;
void dfs(int step)
{
    a[0]=1;
    if (step>k)
    {
        if (cnt==n)
        {
            sum++;
            return;
        }
        else
            return;
    }
    for (int i=a[step-1];i<=n-cnt;i++)//剪枝！
    {
        if (cnt<n)
        {
            cnt+=i;
            a[step]=i;
            dfs(step+1);
            cnt-=i;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    dfs(1);
    printf("%d",sum);
    return 0;
}
