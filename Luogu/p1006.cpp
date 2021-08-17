#include <iostream>

using namespace std;

int mp[52][52];
int dp[104][52][52];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
        }
    }

    for (int k=2;k<=m+n;k++)
    {
        for (int i1=1;i1<=n;i1++)
        {
            for (int i2=1;i2<=n;i2++)
            {
                int j1=k-i1,j2=k-i2;
                if (j1>=1 && j1<=m && j2>=1 && j2<=m)
                {
                    int t=mp[i1][j1];
                    if (i1!=i2) t+=mp[i2][j2];
                    int &x=dp[k][i1][i2];
                    x=max(x,dp[k-1][i1-1][i2]+t);
                    x=max(x,dp[k-1][i1-1][i2-1]+t);
                    x=max(x,dp[k-1][i1][i2-1]+t);
                    x=max(x,dp[k-1][i1][i2]+t);
                }
            }
        }
    }

    cout<<dp[n+m][n][n];

    return 0;
}