#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int N = 100010;

int p;
vector<int> G[N];
vector<int> DAG[N];

int dfn[N], low[N], timestamp = 0;
int scc_cnt, scc_id[N], scc_size[N];
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

		if (in_stk[to]) low[u] = min(low[u], dfn[to]);
	}

	if (dfn[u] == low[u])
	{
		++scc_cnt;
		int x;

		do {
			x = stk[top--];
			in_stk[x] = false;
			scc_id[x] = scc_cnt;
			scc_size[scc_cnt]++;
		} while (x != u);
	}
}

int sz[N], cnt[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m >> p;

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

	set<long long> S;
	for (int i = 1; i <= n; i++)
	{
		for (auto to : G[i])
		{
			int a = scc_id[i], b = scc_id[to];
			long long hash = (100000ll * (long long)a) + b;
			if (a != b && !S.count(hash))
			{
				DAG[a].push_back(b);
				S.insert(hash);
			}
		}
	}

	for (int i = scc_cnt; i >= 1; i--)
	{
		if (!sz[i])
		{
			sz[i] = scc_size[i];
			cnt[i] = 1;
		}

		for (auto to : DAG[i])
		{
			if (sz[to] < sz[i] + scc_size[to])
			{
				sz[to] = sz[i] + scc_size[to];
				cnt[to] = cnt[i];
			}
			else if (sz[to] == sz[i] + scc_size[to])
			{
				cnt[to] = (cnt[to] + cnt[i]) % p;
			}
		}
	}

	int mx_sz = -1, mx_cnt = 0;
	for (int i = 1; i <= scc_cnt; i++)
	{
		if (sz[i] > mx_sz)
		{
			mx_sz = sz[i];
			mx_cnt = cnt[i];
		}
		else if (mx_sz == sz[i])
		{
			mx_cnt = (mx_cnt + cnt[i]) % p;
		}
	}

	cout << mx_sz << ' ' << mx_cnt % p << '\n';
}