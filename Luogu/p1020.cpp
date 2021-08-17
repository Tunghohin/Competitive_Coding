#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[100010],q[100010],n;

int main()
{
    while(scanf("%d",&a[n++])!=EOF);
    n-=1;
    int len=0;
    for (int i=0;i<n;i++)
    {
        int l=0,r=len;
        while (l<r)
        {
            int mid=l+r+1>>1;
            if (q[mid]>=a[i]) l=mid;
            else r=mid-1;
        }
        len=max(len,r+1);
        q[r+1]=a[i];
    }
    cout<<len<<endl;
    memset(q,0,sizeof(q));
    len=0;
    for (int i=0;i<n;i++)
    {
        int l=0,r=len;
        while (l<r)
        {
            int mid=l+r+1>>1;
            if (q[mid]<a[i]) l=mid;
            else r=mid-1;
        }
        len=max(len,r+1);
        q[r+1]=a[i];
    }
    cout<<len;
}
