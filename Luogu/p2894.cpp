#include <iostream>

using namespace std;

const int N = 500010;

struct Node
{
	int l, r;
	int room_cnt;
	int length;
	int length_L, length_R;
	int lazy_tag;
}tr[4 * N];

void push_up(int u)
{
	Node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];

	if (left.length == left.room_cnt)
	{
		root.length_L = left.length + right.length_L;
	}
	else root.length_L = left.length_L;

	if (right.length == right.room_cnt)
	{
		root.length_R = right.length + left.length_R;
	}
	else root.length_R = right.length_R;

	root.length = max(max(left.length, right.length), left.length_R + right.length_L);
}

void push_down(int u) //1 in, 2 out
{
	if (!tr[u].lazy_tag) return;
	Node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];


	if (root.lazy_tag == 1)
	{
		left.lazy_tag = right.lazy_tag = 1;
		left.length = left.length_L = left.length_R = 0;
		right.length = right.length_L = right.length_R = 0;
	}

	if (root.lazy_tag == 2)
	{
		left.lazy_tag = right.lazy_tag = 2;
		left.length = left.length_L = left.length_R = left.room_cnt;
		right.length = right.length_L = right.length_R = right.room_cnt;
	}

	root.lazy_tag = 0;
}

void build(int u, int l, int r)
{
	int len = r - l + 1;
	tr[u] = {l, r, len, len, len, len, 0};
	if (l == r) return;

	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int l, int r, int tag)
{
	push_down(u);
	if (tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].lazy_tag = tag;
		if (tag == 1)
		{
			tr[u].length = tr[u].length_L = tr[u].length_R = 0;
		}
		else
		{
			tr[u].length = tr[u].length_L = tr[u].length_R = tr[u].room_cnt;
		}

		return;
	}

	int mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid) modify(u << 1, l, r, tag);
	if (r > mid) modify(u << 1 | 1, l, r, tag);

	push_up(u);
}

int query(int u, int k)
{
	push_down(u);
	if (tr[u].l == tr[u].r) return tr[u].l;

	int mid = (tr[u].l + tr[u].r) >> 1;
	if (tr[u << 1].length >= k) return query(u << 1, k);
	if (tr[u << 1].length_R + tr[u << 1 | 1].length_L >= k) return mid - tr[u << 1].length_R + 1;
	else return query(u << 1 | 1, k);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	build(1, 1, n);

	int op, x, y;
	while (m--)
	{
		cin >> op;

		if (op == 1)
		{
			cin >> x;
			if (tr[1].length >= x)
			{
				int left = query(1, x);
				cout << left << '\n';
				modify(1, left, left + x - 1, 1);
			}
			else cout << 0 << '\n';
		}

		else
		{
			cin >> x >> y;
			modify(1, x, x + y - 1, 2);
		}
	}
}