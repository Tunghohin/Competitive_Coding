#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 2010;

struct edge
{
	int to, next;
}e[4 * N * N];
int head[2 * N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int dfn[2 * N], low[2 * N], timestamp = 0;
int stk[2 * N], top = 0;
bool in_stk[2 * N];
int scc_id[2 * N];
int scc_cnt = 0;
void tarjan(int u)
{
	low[u] = dfn[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}

		else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
	}

	if (low[u] == dfn[u])
	{
		int x;
		scc_cnt++;

		do
		{
			x = stk[top--];
			in_stk[x] = false;
			scc_id[x] = scc_cnt;
		} while (x != u);
	}
}

bool two_sat(vector<PII> &v, int dif)
{
	memset(head, 0, sizeof(head));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(in_stk, false, sizeof(in_stk));
	memset(scc_id, 0, sizeof(scc_id));
	tot = timestamp = top = scc_cnt = 0;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			int a = i + 1, b = j + 1;
			if (abs(v[i].first - v[j].first) < dif)
			{
				add_edge(2 * a - 1, 2 * b);
				add_edge(2 * b - 1, 2 * a);
			}
			if (abs(v[i].first - v[j].second) < dif)
			{
				add_edge(2 * a - 1, 2 * b - 1);
				add_edge(2 * b, 2 * a);
			}
			if (abs(v[i].second - v[j].first) < dif)
			{
				add_edge(2 * a, 2 * b);
				add_edge(2 * b - 1, 2 * a - 1);
			}
			if (abs(v[i].second - v[j].second) < dif)
			{
				add_edge(2 * a, 2 * b - 1);
				add_edge(2 * b, 2 * a - 1);
			}
		}
	}

	for (int i = 1; i <= 2 * v.size(); i++)
	{
		if (!dfn[i]) tarjan(i);
	}

	for (int i = 1; i <= 2 * v.size(); i += 2)
	{
		if (scc_id[i] == scc_id[i + 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	while (cin >> n)
	{
		vector<PII> v;
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			v.push_back({a, b});
		}

		int l = 0, r = 10000001;

		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (two_sat(v, mid)) l = mid;
			else r = mid - 1;
		}

		cout << l << '\n';
	}
}