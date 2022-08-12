#include <iostream>
#include <algorithm>

using namespace std;

const int N = 400010;
int a[5][200010];
int line_snake[400010];
int line_ud[400010], line_du[400010];

template<typename T>
class segment_tree {
public:
	struct Node {
		int l, r;
		T max_val;
	} tr[4 * N];

	void push_up(Node &root, Node &ls, Node &rs)
	{
		root.l = ls.l, root.r = rs.r;
		root.max_val = max(ls.max_val, rs.max_val);
	}

	void push_up(int u)
	{
		return push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
	}

	void build(int u, int l, int r, int q[])
	{
		if (l == r)
		{
			tr[u] = {l, r, q[l]};
			return;
		}

		int mid = (l + r) >> 1;
		build(u << 1, l, mid, q);
		build(u << 1 | 1, mid + 1, r, q);

		push_up(u);
	}

	int query(int u, int l, int r)
	{
		if (tr[u].l >= l && tr[u].r <= r) return tr[u].max_val;

		int mid = (tr[u].l + tr[u].r) >> 1;
		int v = 0;
		if (l <= mid) v = query(u << 1, l, r);
		if (r > mid) v = max(v, query(u << 1 | 1, l, r));

		return v;
	}
};

segment_tree<int> tr1;
segment_tree<int> tr2;
void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= 2; i++)
	{
		for (int j = 1; j <= n; j++) 
		{
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		line_ud[i] = a[1][i];
		line_ud[i + n] = a[2][n - i + 1];
		line_du[i] = a[2][i];
		line_du[i + n] = a[1][n - i + 1];
	}


	for (int i = 3; i <= 2 * n; i++) line_ud[i] -= (i - 2);
	for (int i = 2; i < 2 * n; i++) line_du[i] -= (i - 1);
	tr1.build(1, 1, 2 * n, line_ud);
	tr2.build(1, 1, 2 * n, line_du);

	// for (int i = 1; i <= 2 * n; i++) cout << line_ud[i] << ' ';
	// cout << '\n';
	// for (int i = 1; i <= 2 * n; i++) cout << line_du[i] << ' ';
	// cout << '\n';

	long long res = 0x3f3f3f3f3f3f3f3f;
	long long max_pre = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			long long up = a[1][i - 1] - max(0, (i - 3) * 2 + 2);
			long long dw = a[2][i - 1] - max(0, (i - 3) * 2 + 1);
			max_pre = max({max_pre, up, dw});
			long long max_suf = max(0ll, (long long)tr1.query(1, i, (2 * n) - i + 1) - (((i + 1) / 2 - 1) * 2));
			long long cur_max = max(max_pre, max_suf);
			// cout << max_suf << '\n';
			res = min(res, cur_max);
		}
		else
		{
			long long up = a[1][i - 1] - max(0, (i - 3) * 2 + 1);
			long long dw = a[2][i - 1] - max(0, (i - 3) * 2 + 2);
			max_pre = max({max_pre, up, dw});
			long long max_suf = max(0ll, (long long)tr2.query(1, i, (2 * n) - i + 1) - (((i + 1) / 2 - 1) * 2));
			long long cur_max = max(max_pre, max_suf);
			// cout << max_suf << '\n';
			res = min(res, cur_max);
		}
	}

	//res = min(res, max_pre);
	cout << res + (2 * n) - 1 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}