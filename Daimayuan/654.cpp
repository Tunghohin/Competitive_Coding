#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <algorithm>
#define PI 3.1415926535898
#define inf64 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define precision 8
#define eps 1e-precision
#define debug(x) cout << (x) << ' '
#define fix(x) fixed << setprecision((precision - 2)) << x

using namespace std;

const int MOD = 1000000007;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 200010;

int n, m;
int a[N];

struct Node
{
	int l, r;
	int minv;
	int cnt;
}tr[4 * N];

void push_up(Node &root, Node &ls, Node &rs)
{
	root.l = ls.l, root.r = rs.r;
	if (ls.minv == rs.minv)
	{
		root.minv = ls.minv;
		root.cnt = ls.cnt + rs.cnt;
	}
	else
	{
		if (ls.minv < rs.minv)
		{
			root.minv = ls.minv;
			root.cnt = ls.cnt;
		}
		else
		{
			root.minv = rs.minv;
			root.cnt = rs.cnt;
		}
	}
}

void build(int u, int l, int r)
{
	if (l == r)
	{
		tr[u].l = tr[u].r = l;
		tr[u].minv = a[l];
		tr[u].cnt = 1;
		return;
	}

	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void modify(int u, int x, int v)
{
	if (tr[u].l == x && tr[u].r == x)
	{
		tr[u].minv = v;
		tr[u].cnt = 1;
		return;
	}
	int mid = (tr[u].l + tr[u].r) >> 1;
	if (x <= mid) modify(u << 1, x, v);
	else modify(u << 1 | 1, x, v);

	push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

Node query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r)
	{
		return tr[u];
	}

	int mid = (tr[u].l + tr[u].r) >> 1;
	if (r <= mid) return query(u << 1, l, r);
	if (l > mid) return query(u << 1 | 1, l, r);
	else
	{
		Node root, ls, rs;
		ls = query(u << 1, l, r);
		rs = query(u << 1 | 1, l, r);
		push_up(root, ls, rs);
		return root;
	}
}

void solve() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> a[i];

	build(1, 1, n);

	while (m--)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			int x, d;
			cin >> x >> d;
			modify(1, x, d);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			Node res = query(1, l, r);
			cout << res.minv << ' ' << res.cnt << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	T = 1;

	while (T--)
	{
		solve();
	}

	return 0;
}
