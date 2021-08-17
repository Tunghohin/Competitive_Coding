#include <iostream>

using namespace std;

int w[50],dp[20010];

int main()
{
    int n,m;
    cin>>m>>n;
    for (int i=1;i<=n;i++) cin>>w[i];

    for (int i=1;i<=n;i++)
    {
        for (int j=m;j>=w[i];j--)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
        }
    }
    cout<<m-dp[m];
    return 0;
}
