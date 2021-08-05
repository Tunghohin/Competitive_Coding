#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const long long INF=0x3f3f3f3f3f3f3f3f;
const int maxn=3e5+5;
const int maxm=6e5+5;

long long dis[maxn],ans[maxn];
bool vis[maxn];
int pre[maxn];
long long sum;

typedef pair<long long, int> PLLI;

int n,m,s;

struct edge{
    int to,next;
    long long val;
}e[maxm];
int head[maxn],tot=0;

void add_edge(int from, int to, long long val)
{
    e[++tot].to=to;
    e[tot].val=val;
    e[tot].next=head[from];
    head[from]=tot;
}

inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9')
    {
        if(c=='-')
        {
            f=-1;
        }
        c=getchar();
    }
    while(c <= '9' && c >= '0')
    {
        x = (x<<1)+(x<<3)+(c^48),c=getchar();
    }
    return x*f;
}

void dijkstra(int st)
{
    priority_queue<PLLI, vector<PLLI>, greater<PLLI>> q;

    for (int i=1;i<=n;i++)
    {
        dis[i]=INF;
        vis[i]=false;
    }
    dis[st]=0;
    q.push({0,st});

    while (!q.empty())
    {
        auto u=q.top();
        q.pop();

        if (vis[u.second]) continue;

        vis[u.second]=true;

        for (int i=head[u.second];i;i=e[i].next)
        {
            int j=e[i].to;
            long long val=e[i].val;

            if (dis[j]>dis[u.second]+val)
            {
                dis[j]=dis[u.second]+val;
                q.push({dis[j],j});
                pre[j]=i;
            }

            if (dis[j]==dis[u.second]+val && val<e[pre[j]].val) pre[j]=i;
        }
    }
}

int main()
{
    n=read(),m=read();

    for (int i=1;i<=m;i++)
    {
        int f=read(),t=read();
        long long v=read();
        add_edge(f,t,v),add_edge(t,f,v);
    }

    s=read();

    dijkstra(s);

    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (i==s) continue;
        int id=pre[i];
        long long val=e[id].val;
        sum+=val;
        ans[++cnt]=id;
    }

    sort(ans+1,ans+cnt+1);

    printf("%lld\n",sum);

    for (int i=1;i<=cnt;i++)
    {
        printf("%lld ",(ans[i]+1)/2);
    }

    return 0;
}


