#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

struct edge
{
	int to, next;
}e[1000010];
int head[N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int dfn[N], low[N], timestamp = 0;
int root;
bool is_cut[N];
void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;

	int cnt = 0;
	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);

			if (dfn[u] <= low[j])
			{
				cnt++;
				if (u != root || cnt > 1) is_cut[u] = true;
			}
		}

		else low[u] = min(low[u], dfn[j]);
	}
}

int main()
{
	int n;
	while (cin >> n, n)
	{
		memset(head, 0, sizeof(head));
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(is_cut, false, sizeof(is_cut));
		tot = timestamp = 0;

		int sz,v;
		while(scanf("%d",&sz),sz){
			while(1)
			{
				char ch=getchar();
				if(ch=='\n') break;
				scanf("%d",&v);
				add_edge(sz,v);
				add_edge(v, sz);
			}
		}

		for (root = 1; root <= n; root++)
		{
			if (!dfn[root]) tarjan(root);
		}

		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			if (is_cut[i]) res++;
		}

		cout << res << '\n';
	}
}