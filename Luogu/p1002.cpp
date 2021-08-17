#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long ull;

ull dp[30][30];
bool vis[40][40];
int xx[8]={-1,1,2,2,1,-1,-2,-2};
int yy[8]={2,2,1,-1,-2,-2,-1,1};

int main()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    n++,m++,a++,b++;
    vis[a][b]=true;
    for (int i=0;i<8;i++)
    {
        if (a+xx[i]>=1&&a+xx[i]<=n&&b+yy[i]>=1&&b+yy[i]<=m)
            vis[a+xx[i]][b+yy[i]]=true;
    }
    dp[0][1]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (vis[i][j]) continue;
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    printf("%llu",dp[n][m]);
    return 0;
}
