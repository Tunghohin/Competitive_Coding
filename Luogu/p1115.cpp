#include <iostream>
#include <cstdio>

using namespace std;

int a[200010],s[200010],n,maxn=-10e4;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i]=max(s[i-1]+a[i],a[i]);//加入或重开
        maxn=max(maxn,s[i]);//防止
    }
    printf("%d",maxn);
}
