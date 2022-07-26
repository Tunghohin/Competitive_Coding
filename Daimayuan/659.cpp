#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 200010;

int a[N];

template<typename T>
class segment_tree {
private:
	struct Node
	{
		int l, r;
		T max_val;
		T add_tag;
	} tr[4 * N];

public:
	void push_up(Node &root, Node &ls, Node &rs)
	{
		root.l = ls.l, root.r = rs.r;
		root.max_val = max(ls.max_val, rs.max_val);
	}

	void push_up(int u)
	{
		push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
	}

	void push_down(Node &root, Node &ls, Node &rs)
	{
		ls.add_tag += root.add_tag;
		rs.add_tag += root.add_tag;
		ls.max_val += root.add_tag;
		rs.max_val += root.add_tag;
		root.add_tag = 0;
	}

	void push_down(int u)
	{
		push_down(tr[u], tr[u << 1], tr[u << 1 | 1]);
	}

	void build(int u, int l, int r)
	{
		if (l == r)
		{
			tr[u].l = l;
			tr[u].r = r;
			tr[u].max_val = a[l];
			tr[u].add_tag = 0;
			return;
		}

		int mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);

		push_up(u);
	}

	void modify(int u, int l, int r, int v)
	{
		if (tr[u].l >= l && tr[u].r <= r)
		{
			tr[u].max_val += v;
			tr[u].add_tag += v;
			return;
		}

		if (tr[u].add_tag) push_down(u);

		int mid = (tr[u].l + tr[u].r) >> 1;

		if (l <= mid) modify(u << 1, l, r, v);
		if (r > mid) modify(u << 1 | 1, l, r, v);

		push_up(u);
	}

	Node query(int u, int l, int r)
	{
		if (tr[u].l >= l && tr[u].r <= r) return tr[u];

		if (tr[u].add_tag) push_down(u);

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

	T query(int l, int r)
	{
		Node res = query(1, l, r);
		return res.max_val;
	}
};

segment_tree<long long> t;
void solve()
{
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) cin >> a[i];

	t.build(1, 1, n);

	while (m--)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			int l, r, d;
			cin >> l >> r >> d;

			t.modify(1, l, r, d);
		}
		else
		{
			int l, r;
			cin >> l >> r;

			cout << t.query(l, r) << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}