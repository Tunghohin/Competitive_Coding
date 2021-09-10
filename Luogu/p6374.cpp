#include<bits/stdc++.h>
using namespace std;
int n, q, idx, t;
int head[500010], dep[500010], size[500010], f[500010][25];
struct node {
	int nxt, to;
} edge[1000010];
void add(int u, int v)
{
	edge[++idx].nxt = head[u];
	edge[idx].to = v;
	head[u] = idx;
}
void dfs(int now, int fath)
{
	dep[now] = dep[fath] + 1;
	size[now] = 1;
	f[now][0] = fath;
	for (int i = 1; i <= t; i++)
	{
		f[now][i] = f[f[now][i - 1]][i - 1];
	}
	for (int i = head[now]; i; i = edge[i].nxt)
	{
		int v = edge[i].to;
		if (v == fath)
			continue;
		dfs(v, now);
		size[now] += size[v];
	}
}
int LCA(int x, int y)
{
	if (x == y)
		return x;
	if (dep[x] < dep[y])
		swap(x, y);
	for (int i = t; i >= 0; i--)
	{
		if (dep[f[x][i]] >= dep[y])
		{
			x = f[x][i];
			if (x == y)
				return x;
		}
	}
	for (int i = t; i >= 0; i--)
	{
		if (f[x][i] != f[y][i])
		{
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
int get(int x, int y)//查询x所在的子树的大小，根为y，不包含y这个点
{
	if (x == y)
		return 0;
	for (int i = t; i >= 0; i--)
	{
		if (dep[f[x][i]] > dep[y])
		{
			x = f[x][i];
		}
	}
	return size[x];
}
int dis(int x, int y)//求树上两点间距离
{
	return dep[x] + dep[y] - 2 * dep[LCA(x, y)];
}
int main()
{
	cin >> n >> q;
	t = (int)(log(n) / log(2)) + 1;
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	dfs(1, 0);
	while (q--)
	{
		int a, b, c, ans = 0;
		scanf("%d%d%d", &a, &b, &c);
		int lca = LCA(a, b);
		//无解情况，c不在a->b的路径上
		if (lca == c)//如果c就等于真实的lca,ans=n-size[ra]-size[rb]
		{
			ans = n - get(a, c) - get(b, c);
			printf("%d\n", ans);
			continue;
		}
		//c在a->lca(a,b)的路径上时，ans=size[c]-size[ra]
		//判断c在不在a->lca路径上：dis(a,c)+dis(c,lca)==dis(a,lca) ?
		//写成函数吧，不然太麻烦了
		if (dis(a, c) + dis(c, lca) == dis(a, lca))
		{
			ans = size[c] - get(a, c);
			printf("%d\n", ans);
			continue;
		}
		//c在b->lca(b,c)的路径上时，ans=size[c]-size[rb]
		if (dis(b, c) + dis(c, lca) == dis(b, lca))
		{
			ans = size[c] - get(b, c);
			printf("%d\n", ans);
			continue;
		}
		printf("0\n");
	}
	return 0;
}