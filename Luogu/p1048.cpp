#include <iostream>
#include <cstdio>
using namespace std;
const int N=1010;
int n,m;
int t[N],v[N],dp[N];

int main()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&t[i],&v[i]);
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=n;j>=v[i];j--)
        {
            dp[j]=max(dp[j],dp[j-t[i]]+v[i]);
        }
    }
    cout<<dp[m];
    return 0;
}
