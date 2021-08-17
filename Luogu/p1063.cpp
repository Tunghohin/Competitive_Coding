#include <iostream>
#include <cstdio>

using namespace std;

int a[500];
int s[500][500];
int maxn;

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }

    for (int i=2;i<2*n;i++)
    {
        for (int j=i-1;i-j<n&&j>=1;j--)
        {
            for (int k=j;k<i;k++)
            {
                s[j][i]=max(s[j][i],s[j][k]+s[k+1][i]+a[j]*a[k+1]*a[i+1]);
                maxn=max(maxn,s[j][i]);
            }
        }
    }
    printf("%d",maxn);
    return 0;
}
