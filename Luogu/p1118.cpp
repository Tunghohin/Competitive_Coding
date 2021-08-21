#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int n,sum,y[20][20];
int a[100005],vis[1000];
void dfs(int step,int cnt)
{
    if (cnt>sum) return;
    if (step>n)
    {
        if (cnt==sum)
        {
            for (int i=1;i<=n;i++)
            {
                cout<<a[i]<<' ';
            }
            exit(0);
        }
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            a[step]=i;
            vis[i]=1;
            dfs(step+1,cnt+i*y[n][step]);
            vis[i]=0;
        }
    }
}
int main()
{
    cin>>n>>sum;
    y[1][1]=1;
    for (int i=2;i<=13;i++)
    {
        for (int j=1;j<=i;j++)
        {
            y[i][j]=y[i-1][j-1]+y[i-1][j];
        }
    }
    dfs(1,0);
    return 0;
}
