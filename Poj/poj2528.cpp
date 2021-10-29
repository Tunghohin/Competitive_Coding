#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define nullptr 0

using namespace std;

const int N = 200010;

struct Node
{
	int l, r;
	int color_lazy;
}tr[5 * N];
bool vis[N];

int find(vector<int> &v, int x)
{
	return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void push_down(int u)
{
	if (!tr[u].color_lazy) return;
	tr[u << 1].color_lazy = tr[u].color_lazy;
	tr[u << 1 | 1].color_lazy = tr[u].color_lazy;
	tr[u].color_lazy = 0;
}

void build(int u, int l, int r)
{
	tr[u] = {l, r, 0};
	if (l == r) return;

	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}

void modify(int u, int l, int r, int v)
{
	if (tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].color_lazy = v;
		return;
	}

	push_down(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid) modify(u << 1, l, r, v);
	if (r > mid) modify(u << 1 | 1, l, r, v);
}

int query(int u)
{
	if (tr[u].color_lazy)
	{
		if (!vis[tr[u].color_lazy])
		{
			vis[tr[u].color_lazy] = true;
			return 1;
		}
		return 0;
	}

	if (tr[u].l == tr[u].r) return 0;

	return query(u << 1) + query(u << 1 | 1);
}

void solve()
{
	memset(tr, 0, sizeof(tr));
	memset(vis, false, sizeof(vis));

	int n;
	cin >> n;

	vector<int> nums;
	vector<pair<int, int> > posters;
	nums.push_back(-0x3f3f3f3f);

	for (int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		nums.push_back(l);
		nums.push_back(r);
		posters.push_back({l, r});
	}

	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	int len = nums.size();
	for (int i = 1; i <= n; i++)
	{
		if (nums[i] - nums[i - 1] != 1) nums.push_back(nums[i] - 1);
	}
	sort(nums.begin(), nums.end());

	build(1, 1, (int)nums.size() - 1);

	for (int i = 0; i < n; i++)
	{
		pair<int, int> u = posters[i];
		int l = find(nums, u.first), r = find(nums, u.second);
		modify(1, l, r, i + 1);
	}

	cout << query(1) << '\n';
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