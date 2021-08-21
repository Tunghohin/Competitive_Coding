#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a[110],up[110],dw[110],num;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    up[0]=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (a[j]<a[i]) up[i]=max(up[i],up[j]+1);
        }
    }
    dw[n+1]=0;
    for (int i=n;i>=1;i--)
    {
        for (int j=n+1;j>i;j--)
        {
            if (a[j]<a[i]) dw[i]=max(dw[i],dw[j]+1);
        }
    }
    for (int i=1;i<=n;i++)
    {
        num=max(num,up[i]+dw[i]-1);
    }
    cout<<n-num;
}
