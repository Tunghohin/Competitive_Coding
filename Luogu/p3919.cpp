#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1000010;

int a[N];

struct Node
{
	int l, r;
	int val;
}tr[4 * N + N * 20];
int root[N], idx;

int build(int l, int r)
{
	int q = ++idx;

	if (l == r)
	{
		tr[q].val = a[l];
		return q;
	}

	int mid = (l + r) >> 1;
	tr[q].l = build(l, mid), tr[q].r = build(mid + 1, r);
	return q;
}

int modify(int p, int l, int r, int loc, int x)
{
	int q = ++idx;
	tr[q] = tr[p];

	if (l == r)
	{
		tr[q].val = x;
		return q;
	}

	int mid = (l + r) >> 1;
	if (loc <= mid) tr[q].l = modify(tr[p].l, l, mid, loc, x);
	else tr[q].r = modify(tr[p].r, mid + 1, r, loc, x);

	return q;
}

int query(int q, int l, int r, int loc)
{
	if (l == r)
	{
		return tr[q].val;
	}

	int mid = (l + r) >> 1;
	if (loc <= mid) return query(tr[q].l, l, mid, loc);
	else return query(tr[q].r, mid + 1, r, loc);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> nums;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	root[0] = build(1, n);

	int tot_ver = 0;
	for (int i = 1; i <= m; i++)
	{
		int ver, op, loc;
		cin >> ver >> op >> loc;

		if (op == 1)
		{
			int x;
			cin >> x;
			root[i] = modify(root[ver], 1, n, loc, x);
		}

		else
		{
			cout << query(root[ver], 1, n, loc) << '\n';
			root[i] = root[ver];
		}
	}
}