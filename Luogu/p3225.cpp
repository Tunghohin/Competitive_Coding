#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef unsigned long long ULL;

const int N = 1010, M = 1010;

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

int root;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool is_cut[N];
int bcc_cnt;
vector<int> bcc[N];
void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u;

	if (u == root && !head[u])
	{
		bcc[++bcc_cnt].push_back(u);
		return;
	}

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
				++bcc_cnt;
				int x;
				do
				{
					x = stk[top--];
					bcc[bcc_cnt].push_back(x);
				} while (x != j);
				bcc[bcc_cnt].push_back(u);
			}
		}

		else low[u] = min(low[u], dfn[j]);
	}
}

void solve(int m, int kase)
{
	int n;
	for (int i = 0; i < N; i++) bcc[i].clear();
	timestamp = tot = top = bcc_cnt = n = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(is_cut, false, sizeof(is_cut));
	memset(head, 0, sizeof(head));

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		n = max(a, n), n = max(b, n);
		add_edge(a, b), add_edge(b, a);
	}

	for (root = 1; root <= n; root++)
	{
		if (!dfn[root]) tarjan(root);
	}

	int res = 0;
	ULL sum = 1;


	for (int i = 1; i <= bcc_cnt; i++)
	{
		int cnt = 0;
		for (int j = 0; j < bcc[i].size(); j++)
		{
			if (is_cut[bcc[i][j]]) cnt++;
		}

		if (cnt == 0)
		{
			if (bcc[i].size() > 1) res += 2, sum *= bcc[i].size() * (bcc[i].size() - 1) / 2;
			else res++;
		}
		else if (cnt == 1)
		{
			res++, sum *= bcc[i].size() - 1;
		}
	}

	cout << "Case " << kase << ": " << res << ' ' << sum << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int m;
	int kase = 0;
	while (cin >> m, m)
	{
		kase++;
		solve(m, kase);
	}
}