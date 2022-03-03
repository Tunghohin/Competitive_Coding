#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 100010;

struct node
{
	int l, r;
	int cnt;
}tr[4 * N + 18 * N];
int root[N], idx;

int find(vector<int> &v, int x)
{
	return (int)(upper_bound(v.begin(), v.end(), x) - v.begin());
}

int build(int l, int r)
{
	int p = ++idx;
	if (l == r) return p;

	int mid = (l + r) >> 1;
	tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
	return p;
}

int insert(int p, int l, int r, int x)
{
	int q = ++idx;
	tr[q] = tr[p];

	if (l == r)
	{
		tr[q].cnt++;
		return q;
	}

	int mid = (l + r) >> 1;
	if (x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
	else tr[q].r = insert(tr[p].r, mid + 1, r, x);

	tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
	return q;
}

int query(int q, int l, int r, int x)
{
	if (l == r) return tr[q].cnt;

	int mid = (l + r) >> 1;
	if (x <= mid) return query(tr[q].l, l, mid, x);
	else return tr[tr[q].l].cnt + query(tr[q].r, mid + 1, r, x);
}

void solve()
{
	int n, q;
	cin >> n >> q;

	vector<int> nums;
	vector<int> hashed;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		nums.push_back(x);
		hashed.push_back(x);
	}

	sort(hashed.begin(), hashed.end());
	hashed.erase(unique(hashed.begin(), hashed.end()), hashed.end());

	root[0] = build(0, 100010);
	for (int i = 1; i <= n; i++)
	{
		root[i] = insert(root[i - 1], 0, 100010, find(hashed, nums[i - 1]));
	}

	while (q--)
	{
		int l, r, h;
		cin >> l >> r >> h;

		cout << query(root[r], 0, 100010, find(hashed, h))
		- query(root[l - 1], 0, 100010, find(hashed, h)) << ' ';
	}
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