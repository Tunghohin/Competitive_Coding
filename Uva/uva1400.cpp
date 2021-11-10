#include <iostream>
#include <cstring>
#define int long long

using namespace std;

const int N = 500010;

int arr[N];

struct Node
{
	int l, r;
	int sum;
	int t_max, pre_max, suf_max;
	pair<int, int> max_idx;
	int pre_idx, suf_idx;
}tr[N << 2];

void push_up(Node &root, Node &left, Node &right)
{
	root.sum = left.sum + right.sum;

	int mid_max = left.suf_max + right.pre_max;
	int left_max = left.t_max;
	int right_max = right.t_max;

	if (left_max >= right_max && left_max >= mid_max)
	{
		root.t_max = left_max;
		root.max_idx = left.max_idx;
	}
	else if (mid_max >= right_max && mid_max >= left_max)
	{
		root.t_max = mid_max;
		root.max_idx = {left.suf_idx, right.pre_idx};
	}
	else
	{
		root.t_max = right_max;
		root.max_idx = right.max_idx;
	}

	if (left.pre_max >= left.sum + right.pre_max)
	{
		root.pre_max = left.pre_max;
		root.pre_idx = left.pre_idx;
	}
	else
	{
		root.pre_max = left.sum + right.pre_max;
		root.pre_idx = right.pre_idx;
	}

	if (right.suf_max > right.sum + left.suf_max)
	{
		root.suf_max = right.suf_max;
		root.suf_idx = right.suf_idx;
	}
	else
	{
		root.suf_max = right.sum + left.suf_max;
		root.suf_idx = left.suf_idx;
	}
}

void push_up(int u)
{
	push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
	tr[u].l = l;
	tr[u].r = r;
	if (l == r)
	{
		tr[u].sum = arr[l];
		tr[u].pre_max = tr[u].suf_max = tr[u].t_max = arr[l];
		tr[u].pre_idx = tr[u].suf_idx = l;
		tr[u].max_idx = {l, r};
		return;
	}

	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);

	push_up(u);
}

Node query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u];

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

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	int case_cnt = 0;
	while (cin >> n >> m)
	{
		memset(tr, 0, sizeof(tr));
		memset(arr, 0, sizeof(arr));

		case_cnt++;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		build(1, 1, n);

		cout << "Case " << case_cnt << ':' << '\n';
		for (int i = 1; i <= m; i++)
		{
			int l, r;
			cin >> l >> r;

			if (l > r) swap(l, r);

			Node res = query(1, l, r);
			cout << res.max_idx.first << ' ' << res.max_idx.second << '\n';
		}
	}
}