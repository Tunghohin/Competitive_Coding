#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;

vector<int> G[100010];
vector<int> SCC[100010];

int scc_cnt = 0;
int dfn[N], low[N], timestamp = 0;
int stk[N], top = 0;
bool in_stk[N];
void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;

	for (auto to : G[u])
	{
		if (!dfn[to])
		{
			tarjan(to);
			low[u] = min(low[u], low[to]);
		}
		else if (in_stk[to]) low[u] = min(low[u], dfn[to]);
	}

	if (dfn[u] == low[u])
	{
		++scc_cnt;
		int x;
		do {
			x = stk[top--];
			in_stk[x] = false;
			SCC[scc_cnt].push_back(x);
		} while (x != u);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i]) tarjan(i);
	}

	for (int i = 1; i <= scc_cnt; i++)
	{
		sort(SCC[i].begin(), SCC[i].end());
	}
	sort(SCC + 1, SCC + 1 + scc_cnt);


	for (int i = 1; i <= scc_cnt; i++)
	{
		for (auto u : SCC[i])
		{
			cout << u << ' ';
		}
		cout << '\n';
	}
}
