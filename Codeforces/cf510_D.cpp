#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

const int N = 200010;

typedef pair<int, int> PII;

int a[N];

inline int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while (ch<'0' || ch>'9') { if (ch == '-')w = -1; ch = getchar(); }
	while (ch >= '0'&&ch <= '9') s = s * 10 + ch - '0', ch = getchar();
	return s * w;
}

int root[N], idx;
struct Node
{
	int l, r;
	long long sum;
}tr[4 * N + 14 * N];

int find(vector<int> &v, int x)
{
	return (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
}

int build(int l, int r)
{
	int p = ++idx;
	if (l == r) return p;

	int mid = (l + r) >> 1;
	tr[p].l = build(l, mid);
	tr[p].r = build(mid + 1, r);

	return p;
}

int insert(int p, int l, int r, int x)
{
	int q = ++idx;
	tr[q] = tr[p];

	if (l == r)
	{
		tr[q].sum++;
		return q;
	}

	int mid = (l + r) >> 1;
	if (x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
	else tr[q].r = insert(tr[p].r, mid + 1, r, x);

	tr[q].sum = tr[tr[q].l].sum + tr[tr[q].r].sum;
	return q;
}

long long query(int q, int l, int r, int x)
{
	if (l == r) return tr[q].sum;

	int mid = (l + r) >> 1;
	if (x <= mid) return query(tr[q].l, l, mid, x);
	else return tr[tr[q].l].sum + query(tr[q].r, mid + 1, r, x);
}

int b[N];

void solve()
{
	int n;
	n = read();

	unordered_map<int, int> mp;

	vector<int> nums;
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		b[i] = a[i];
	}
	sort(nums.begin(), nums.end());
	sort(b + 1, b + n + 1);

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!mp[b[i]]) mp[b[i]] = cnt++;
	}

	root[0] = build(0, cnt - 1);

	for (int i = 1; i <= n; i++)
	{
		root[i] = insert(root[i - 1], 0, cnt - 1, mp[a[i]]);
	}

	for (int k = 1; k <= n - 1; k++)
	{
		long long res = 0;
		for (int i = 1; i <= n / k + 1; i++)
		{
			if (k * (i - 1) + 2 > n) break;

			if (k * i + 1 < n)
			{
				res += query(root[k * i + 1], 0, cnt - 1, mp[a[i]] - 1) -
					query(root[k * (i - 1) + 1], 0, cnt - 1, mp[a[i]] - 1);
			}
			else
			{
				res += query(root[n], 0, cnt - 1, mp[a[i]] - 1) -
					query(root[k * (i - 1) + 1], 0, cnt - 1, mp[a[i]] - 1);
			}
		}

		cout << res << ' ';
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	T = 1;

	while (T--)
	{
		solve();
	}
}