#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100;

int val[N];
vector<int> nums;

struct edge
{
	int to, next;
}e[2 * N];
int head[N], tot = 0;

struct Node
{
	int l, r;
	int cnt;
}tr[4 * N + N * 17];
int root[N], idx;

int build(int l, int r)
{
	int p = ++idx;
	if (l == r) return p;

	int mid = (l + r) >> 1;
	tr[p].l = build(l, mid);
	tr[p].r = build(mid + 1, r);

	return p;
}

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int get(int x)
{
	return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

int insert(int p, int l, int r, int x)
{
	int q = ++idx;
	tr[q] = tr[p];

	if (l == r)
	{
		tr[q].cnt++;
		return q;
	}

	int mid = (l + r) >> 1;
	if (x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
	else tr[q].r = insert(tr[p].r, mid + 1, r, x);

	tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;

	return q;
}

int depth[N];
int f[N][32];
void dfs(int u, int from)
{
	root[u] = insert(root[from], 0, (int)nums.size() - 1, get(val[u]));
	f[u][0] = from;
	depth[u] = depth[from] + 1;

	for (int i = 1; i <= 18; i++) f[u][i] = f[f[u][i - 1]][i - 1];

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == from) continue;

		dfs(j, u);
	}
}

int __lca(int a, int b)
{
	if (depth[a] < depth[b]) swap(a, b);
	for (int i = 20; i >= 0; i--)
	{
		if (depth[f[a][i]] >= depth[b]) a = f[a][i];
	}

	if (a == b) return b;

	for (int i = 20; i >= 0; i--)
	{
		if (f[a][i] != f[b][i])
		{
			a = f[a][i];
			b = f[b][i];
		}
	}

	return f[b][0];
}

int get_k_th(int a, int b, int lca, int lca_p, int l, int r, int k)
{
	if (l == r) return l;
	int sum = tr[tr[a].l].cnt + tr[tr[b].l].cnt - tr[tr[lca].l].cnt - tr[tr[lca_p].l].cnt;

	int mid = (l + r) >> 1;
	if (sum >= k) return get_k_th(tr[a].l, tr[b].l, tr[lca].l, tr[lca_p].l, l, mid, k);
	else return get_k_th(tr[a].r, tr[b].r, tr[lca].r, tr[lca_p].r, mid + 1, r, k - sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> val[i];
		nums.push_back(val[i]);
	}

	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	root[0] = build(0, (int)nums.size() - 1);

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b), add_edge(b, a);
	}

	dfs(1, 0);

	int last = 0;
	while (m--)
	{
		int u, v, k;
		cin >> u >> v >> k;

		u ^= last;
		int lca = __lca(u, v);

		last = nums[get_k_th(root[u], root[v], root[lca], root[f[lca][0]], 0, (int)nums.size() - 1, k)];
		cout << last << '\n';
	}
}