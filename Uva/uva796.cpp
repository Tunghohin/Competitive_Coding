#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010, M = 1000010;

struct edge
{
	int to, next;
}e[M];
int head[N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int dfn[N], low[N], timestamp = 0;
int c_link = 0;
vector<pair<int, int>> res;
void tarjan(int u, int from)
{
	dfn[u] = low[u] = ++timestamp;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (!dfn[j])
		{
			tarjan(j, u);
			low[u] = min(low[u], low[j]);

			if (dfn[u] < low[j])
			{
				c_link++;
				int a = u, b = j;
				if (a > b) swap(a, b);
				res.push_back({a, b});
			}
		}

		else if (j != from) low[u] = min(low[u], dfn[j]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	while (cin >> n)
	{
		res.clear();
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(head, 0, sizeof(head));
		tot = timestamp = c_link = 0;

		int edge_cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			int a, cnt;
			char c1, c2;

			cin >> a >> c1 >> cnt >> c2;
			while (cnt--)
			{
				int b;
				cin >> b;
				add_edge(a, b);
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (!dfn[i]) tarjan(i, 0);
		}

		sort(res.begin(), res.end());

		cout << c_link << " critical links\n";
		for (auto i : res)
		{
			cout << i.first << " - " << i.second << '\n';
		}

		cout << '\n';
	}
}