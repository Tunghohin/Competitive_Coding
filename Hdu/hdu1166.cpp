#include <iostream>

using namespace std;

const int N = 50010;

int a[N];
struct Node
{
	int l, r;
	int sum;
}tr[4 * N];

void push_up(int u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r)
{
	if (l == r) tr[u] = {l, r, a[l]};

	else
	{
		tr[u] = {l, r};
		int mid = (l + r) >> 1;

		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);

		push_up(u);
	}
}

void modify(int u, int x, int v)
{
	if (tr[u].l == x && tr[u].r == x) tr[u].sum += v;

	else
	{
		int mid = (tr[u].l + tr[u].r) >> 1;

		if (x <= mid) modify(u << 1, x, v);
		else modify(u << 1 | 1, x, v);

		push_up(u);
	}
}

int query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

	int mid = (tr[u].l + tr[u].r) >> 1;

	int sum = 0;
	if (l <= mid) sum = query(u << 1, l, r);
	if (r > mid) sum += query(u << 1 | 1, l, r);

	return sum;
}

void solve(int kase)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);

	cout << "Case " << kase << ":\n";
	string s;
	while (cin >> s, s != "End")
	{
		int i, j;
		cin >> i >> j;

		if (s[0] == 'A')
		{
			modify(1, i, j);
		}

		else if (s[0] == 'S')
		{
			modify(1, i, -j);
		}

		else if (s[0] == 'Q')
		{
			cout << query(1, i, j) << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		solve(i);
	}

	return 0;
}