#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;
const int N = 200010;
int timestamp = 0;
int L[N], R[N];
int val[N];
vector<pair<int, int>> son[N];

struct edge
{
	int to, next;
}e[2 * N];
int head[N], tot;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

long long tr[N];

int low_bit(int x)
{
	return x & (-x);
}

void modify(int x, int v)
{
	for (; x <= n; x += low_bit(x))
	{
		tr[x] += v;
	}
}

long long query(int x)
{
	long long res = 0;
	for (; x; x -= low_bit(x))
	{
		res += tr[x];
	}
	return res;
}

void dfs(int u, int from)
{
	L[u] = ++timestamp;
	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == from) continue;
		dfs(j, u);
		son[u].push_back({L[j], R[j]});
	}
	R[u] = timestamp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> q;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		add_edge(a, b), add_edge(b, a);
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
		modify(L[i], val[i]);
	}

	int root = 1;
	for (int i = 1; i <= q; i++)
	{
		int op;
		cin >> op;

		if (op == 1) {
			int x, y;
			cin >> x >> y;
			modify(L[x], y - val[x]);
			val[x] = y;
		}
		else if (op == 2) {
			int x;
			cin >> x;
			if (x == root)
			{
				cout << query(n) << '\n';
			}
			else if (L[x] < L[root] && R[x] >= R[root])
			{
				auto seg = *prev(upper_bound(son[x].begin(), son[x].end(), pair<int, int>{L[root], R[root]}));
				cout << query(n) - (query(seg.second), query(seg.first - 1)) << '\n';
			}
			else
			{
				cout << query(R[x]) - query(L[x] - 1) << '\n';
			}
		}
		else
		{
			int x;
			cin >> x;
			root = x;
		}
	}
}

