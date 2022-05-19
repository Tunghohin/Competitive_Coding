#include <iostream>

using namespace std;

const int N = 200010;

int n, m;
long long k;
int val[N];
int dg[N];
int v[N];
bool vis[N];

struct edge
{
	int to, next;
}e[N];
int head[N], tot;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

void check_cyc(int u, int max_val)
{
	if (vis[u]) return;
	vis[u] = true;

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (val[j] <= max_val)
		{
			dg[j]--;
			v[j] = max(v[j], v[u] + 1);
			if (dg[j] == 0) check_cyc(j, max_val);
		}
	}
}

void init(int max_val)
{
	for (int i = 1; i <= n; i++) dg[i] = 0;
	for (int i = 1; i <= n; i++) if (val[i] <= max_val) {
		for (int j = head[i]; j; j = e[j].next) if (val[e[j].to] <= max_val) {
			dg[e[j].to]++;
		}
	}

	for (int i = 1; i <= n; i++) v[i] = (val[i] <= max_val);
	for (int i = 1; i <= n; i++) vis[i] = false;
}

bool check(int max_val)
{
	for (int i = 1; i <= n; i++) if (val[i] <= max_val && !dg[i]) check_cyc(i, max_val);
	for (int i = 1; i <= n; i++) if (val[i] <= max_val && dg[i]) return true;
	for (int i = 1; i <= n; i++) if (v[i] >= k) return true;
	return false;
}

void solve()
{
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) cin >> val[i];

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
	}

	int l = 0, r = 1e9;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		init(mid);
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}

	if (l <= 1e9) cout << l << '\n';
	else cout << -1 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}