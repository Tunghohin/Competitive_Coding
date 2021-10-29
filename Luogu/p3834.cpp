#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200010, M = 10010;

int arr[N];

struct Node
{
	int l, r;
	int cnt;
}tr[4 * N + N * 17];
int root[N], idx;

int find(vector<int> &v, int x)
{
	return lower_bound(v.begin(), v.end(), x) - v.begin();
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

int query(int q, int p, int l, int r, int k)
{
	if (l == r) return r;
	int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
	int mid = (l + r) >> 1;
	if (k <= cnt) return query(tr[q].l, tr[p].l, l, mid, k);
	else return query(tr[q].r, tr[p].r, mid + 1, r, k - cnt);
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> nums;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		nums.push_back(arr[i]);
	}

	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	root[0] = build(0, (int)nums.size() - 1);

	for (int i = 1; i <= n; i++)
	{
		root[i] = insert(root[i - 1], 0, (int)nums.size() - 1, find(nums, arr[i]));
	}

	while (m--)
	{
		int l, r, k;
		cin >> l >> r >> k;

		cout << nums[query(root[r], root[l - 1], 0, (int)nums.size() - 1, k)] << '\n';
	}

	return 0;
}