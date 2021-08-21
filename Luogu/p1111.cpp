#include <iostream>
#include <algorithm>

using namespace std;

int p[1010],p_size[1010];
int n,m;

struct edge{
    int a,b,t;
}e[100010];

bool comp(edge a, edge b)
{
    return a.t<b.t;
}

int find(int x)
{
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>n>>m;

    for (int i=0;i<=n;i++) p[i]=i,p_size[i]=1;

    int x,y,T;
    for (int i=0;i<m;i++)
    {
        cin>>x>>y>>T;
        e[i]={x,y,T};
    }

    sort(e,e+m,comp);

    for (int i=0;i<m;i++)
    {
        int a=e[i].a,b=e[i].b,t=e[i].t;

        if (find(a)!=find(b))
        {
            p_size[find(b)]+=p_size[find(a)];
            p[find(a)]=find(b);
        }
        if (p_size[find(b)]==n)
        {
            cout<<t;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}
