#include <iostream>
#include <cstdio>
using namespace std;
const int N=200005;
int n,m;
long long sum;
int a[N];
void quick_sort(int q[],int l,int r)
{
    if (l>=r) return;

    int i=l-1,j=r+1,x=a[l+r>>1];
    while (i<j)
    {
        do j--;while (q[j]>x);
        do i++;while (q[i]<x);
        if (i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);quick_sort(q,j+1,r);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    quick_sort(a,0,n-1);
    for (int i=0;i<n-1;i++)
    {
        int l=i,r=n-1;
        while(l<r)
        {
            int mid=l+r>>1;
            if (a[mid]-a[i]<m) l=mid+1;
            else r=mid;
        }
        if (a[l]-a[i]!=m) continue;
        else
        {
            int o=l;
            l=i,r=n-1;
            while(l<r)
            {
                int mid=l+r+1>>1;
                if (a[mid]-a[i]<=m) l=mid;
                else r=mid-1;
            }
            int p=l;
            sum+=((p-o)+1);
        }
    }
    printf("%lld",sum);
    return 0;
}
