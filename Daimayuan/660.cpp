#include <iostream>

using namespace std;

const int N = 200010;
const int MOD = 1000000007;

int a[N];

template<typename T>
class segment_tree {
private:
	struct Node
	{
		int l, r;
		T sum;
		T add_tag, mul_tag;
	} tr[4 * N];

public:
	void push_up(Node &root, Node &ls, Node &rs)
	{
		root.l = ls.l, root.r = rs.r;
		root.sum = (ls.sum % MOD + rs.sum) % MOD;
	};

	void push_up(int u)
	{
		push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
	}

	void push_down(Node &root, Node &ls, Node &rs)
	{
		ls.sum = (((ls.sum % MOD) * root.mul_tag) % MOD + (((ls.r - ls.l + 1) % MOD) * root.add_tag) % MOD) % MOD;
		rs.sum = (((rs.sum % MOD) * root.mul_tag) % MOD + (((rs.r - rs.l + 1) % MOD) * root.add_tag) % MOD) % MOD;

		ls.mul_tag = ((ls.mul_tag % MOD) * root.mul_tag) % MOD;
		rs.mul_tag = ((rs.mul_tag % MOD) * root.mul_tag) % MOD;

		ls.add_tag = ((((ls.add_tag % MOD) * root.mul_tag) % MOD) + root.add_tag) % MOD;
		rs.add_tag = ((((rs.add_tag % MOD) * root.mul_tag) % MOD) + root.add_tag) % MOD;

		root.add_tag = 0;
		root.mul_tag = 1;
	}

	void push_down(int u)
	{
		if (tr[u].add_tag != 0 || tr[u].mul_tag != 1)
		{
			push_down(tr[u], tr[u << 1], tr[u << 1 | 1]);
		}
	}

	void build(int u, int l, int r)
	{
		if (l == r)
		{
			tr[u] = {l, r, a[l] % MOD, 0, 1};
			return;
		}

		tr[u].add_tag = 0;
		tr[u].mul_tag = 1;

		int mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);

		push_up(u);
	}

	void modify(int u, int l, int r, T v, int op) //1 add 2 mul 3 set
	{
		if (tr[u].l >= l && tr[u].r <= r)
		{
			if (op == 1)
			{
				tr[u].add_tag = (tr[u].add_tag + v) % MOD;
				tr[u].sum = (tr[u].sum + ((tr[u].r - tr[u].l + 1) * v % MOD)) % MOD;
			}
			else if (op == 2)
			{
				tr[u].add_tag = (tr[u].add_tag * v) % MOD;
				tr[u].mul_tag = (tr[u].mul_tag * v) % MOD;
				tr[u].sum = (tr[u].sum * v) % MOD;
			}
			else
			{
				tr[u].add_tag = v;
				tr[u].mul_tag = 0;
				tr[u].sum = ((tr[u].r - tr[u].l + 1) * v) % MOD;
			}
			return;
		}

		push_down(u);

		int mid = (tr[u].l + tr[u].r) >> 1;

		if (l <= mid) modify(u << 1, l, r, v, op);
		if (r > mid) modify(u << 1 | 1, l, r, v, op);

		push_up(u);
	}

	Node query(int u, int l, int r)
	{
		if (tr[u].l >= l && tr[u].r <= r) return tr[u];

		push_down(u);

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
		return query(1, l, r).sum;
	}
};

segment_tree<long long> tr;
void solve()
{
	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> a[i];

	tr.build(1, 1, n);

	while (q--)
	{
		int op;
		cin >> op;

		if (op <= 3)
		{
			int l, r;
			long long d;
			cin >> l >> r >> d;

			tr.modify(1, l, r, d, op);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << tr.query(l, r) << '\n';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}
