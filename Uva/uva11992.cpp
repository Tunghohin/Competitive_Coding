#include <iostream>

using namespace std;

const int N = 1010;//500010

struct Node
{
	int l, r;
	long long sum;
	int set_tag;
	long long add_tag;
	int min, max;
}tr[22][4 * N];

void push_up(Node &root, Node &left, Node &right)
{
	root.sum = left.sum + right.sum;
	root.max = max(left.max, right.max);
	root.min = min(left.min, right.min);
}

void push_up(int u, Node t[])
{
	push_up(t[u], t[u << 1], t[u << 1 | 1]);
}

void push_down(int u, Node t[])
{
	Node &root = t[u], &left = t[u << 1], &right = t[u << 1 | 1];

	if (t[u].set_tag >= 0)
	{
		left.set_tag = right.set_tag = root.set_tag;
		left.add_tag = right.add_tag = 0;

		left.sum = (long long)(left.r - left.l + 1) * root.set_tag;
		right.sum = (long long)(right.r - right.l + 1) * root.set_tag;

		left.min = left.max = root.set_tag;
		right.min = right.max = root.set_tag;

		root.set_tag = -1;
	}

	if (t[u].add_tag)
	{
		left.add_tag += root.add_tag;
		right.add_tag += root.add_tag;

		left.sum += (long long)(left.r - left.l + 1) * root.add_tag;
		right.sum += (long long)(right.r - right.l + 1) * root.add_tag;

		left.min += root.add_tag;
		left.max += root.add_tag;
		right.min += root.add_tag;
		right.max += root.add_tag;

		root.add_tag = 0;
	}
}

void build(int u, int l, int r, Node t[])
{
	t[u] = {l, r};
	if (l == r)
	{
		t[u].sum = 0;
		t[u].set_tag = -1;
		t[u].add_tag = 0;
		t[u].min = 1e9;
		t[u].max = -1e9;
		return;
	}

	int mid = (l + r) >> 1;
	build(u << 1, l, mid, t);
	build(u << 1 | 1, mid + 1, r, t);

	push_up(u, t);
}

void modify(int u, int l, int r, int v, Node t[], int op) //1 add, 2 set
{
	push_down(u, t);

	if (t[u].l >= l && t[u].r <= r)
	{
		if (op == 1)
		{
			t[u].add_tag += v;
			t[u].sum += (long long)(t[u].r - t[u].l + 1) * v;
			t[u].max += v;
			t[u].min += v;
		}
		else
		{
			t[u].set_tag = v;
			t[u].sum = (t[u].r - t[u].l + 1) * v;
			t[u].max = v;
			t[u].min = v;
		}
		return;
	}

	int mid = (t[u].l + t[u].r) >> 1;
	if (l <= mid) modify(u << 1, l, r, v, t, op);
	if (r > mid) modify(u << 1 | 1, l, r, v, t, op);

	push_up(u, t);
}

Node query(int u, int l, int r, Node t[])
{
	if (t[u].l >= l && t[u].r <= r) return t[u];

	push_down(u, t);

	int mid = (t[u].l + t[u].r) >> 1;
	if (r <= mid) return query(u << 1, l, r, t);
	else if (l > mid) return query(u << 1 | 1, l, r, t);
	else
	{
		Node left = query(u << 1, l, r, t);
		Node right = query(u << 1 | 1, l, r, t);

		Node root;
		push_up(root, left, right);

		return root;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int r, c, m;
	while (cin >> r >> c >> m)
	{
		for (int i = 1; i <= r; i++)
		{
			build(1, 1, c, tr[i]);
		}

		int op;
		while (m--)
		{
			cin >> op;
			if (op == 1 || op == 2)
			{
				int x1, y1, x2, y2, v;
				cin >> x1 >> y1 >> x2 >> y2 >> v;

				for (int i = x1; i <= x2; i++)
				{
					modify(1, y1, y2, v, tr[i], op);
				}
			}

			else
			{
				int x1, y1, x2, y2;
				cin >> x1 >> y1 >> x2 >> y2;

				long long sum = 0;
				int max_num = -1e9, min_num = 1e9;
				for (int i = x1; i <= x2; i++)
				{
					auto u = query(1, y1, y2, tr[i]);
					sum += u.sum;

					max_num = max(max_num, u.max);
					min_num = min(min_num, u.min);
				}

				cout << sum << ' ' << min_num << ' ' << max_num << '\n';
			}
		}
	}
}