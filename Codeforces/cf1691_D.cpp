#include <iostream>
#include <stack>
#define int long long

using namespace std;

const int N = 200010;
int a[N];
int L[N], R[N];

struct Node
{
	int l, r;
	int sum, l_max, r_max, t_max;
}tr[4 * N];

void push_up(Node &u, Node &l, Node &r)
{
	u.sum = l.sum + r.sum;
	u.l_max = max(l.l_max, l.sum + r.l_max);
	u.r_max = max(r.r_max, r.sum + l.r_max);
	u.t_max = max(max(l.t_max, r.t_max), l.r_max + r.l_max);
}

void push_up(int u)
{
	push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
	if (l == r) tr[u] = {l, r, a[l], a[l], a[l], a[l]};
	else
	{
		tr[u] = {l, r};

		int mid = (l + r) >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);

		push_up(u);
	}
}

Node query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u];

	else
	{
		int mid = (tr[u].l + tr[u].r) >> 1;

		if (r <= mid) return query(u << 1, l, r);
		else if (l > mid) return query(u << 1 | 1, l, r);
		else
		{
			Node left = query(u << 1, l, r);
			Node right = query(u << 1 | 1, l, r);

			Node res;
			push_up(res, left, right);

			return res;
		}
	}
}

void solve()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	build(1, 1, n);

	stack<int> stk;
	for (int i = 1; i <= n; i++)
	{
		while (!stk.empty() && a[stk.top()] < a[i]) stk.pop();
		if (!stk.empty()) L[i] = stk.top() + 1;
		else L[i] = 1;
		stk.push(i);
	}
	while (!stk.empty()) stk.pop();
	for (int i = n; i >= 1; i--)
	{
		while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
		if (!stk.empty()) R[i] = stk.top() - 1;
		else R[i] = n;
		stk.push(i);
	}

	for (int i = 1; i <= n; i++)
	{
		if (a[i] < query(1, L[i], R[i]).t_max)
		{
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

signed main()
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