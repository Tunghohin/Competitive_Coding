#include <iostream>

using namespace std;

int a[110];
int dp[110][110];
int mod=1000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n,m;
    cin>>n>>m;

    for (int i=1;i<=n;i++) cin>>a[i];
    dp[0][0]=1;

    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=m;j++)
        {
            for (int k=0;k<=min(a[i],j);k++)
            {
                dp[i][j]=(dp[i-1][j-k]+dp[i][j])%mod;
            }
        }
    }

    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }

    cout<<dp[n][m];

    return 0;
}
