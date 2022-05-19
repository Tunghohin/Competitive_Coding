#include <iostream>

using namespace std;

const int N = 100010;
int tr_x[N], tr_y[N];
int x_cnt[N], y_cnt[N];
int n, q;

int low_bit(int x)
{
	return x & (-x);
}

void modify(int tr[], int x, int v)
{
	for (; x <= n; x += low_bit(x))
	{
		tr[x] += v;
	}
}

int query(int tr[], int x)
{
	int res = 0;
	for (; x; x -= low_bit(x))
	{
		res += tr[x];
	}
	return res;
}

void solve()
{
	cin >> n >> q;

	for (int i = 1; i <= q; i++)
	{
		int op;
		cin >> op;

		if (op == 1)
		{
			int x, y;
			cin >> x >> y;
			if (!x_cnt[x]) modify(tr_x, x, 1);
			x_cnt[x]++;
			if (!y_cnt[y]) modify(tr_y, y, 1);
			y_cnt[y]++;
		}
		else if (op == 2)
		{
			int x, y;
			cin >> x >> y;
			x_cnt[x]--, y_cnt[y]--;
			if (!x_cnt[x]) modify(tr_x, x, -1);
			if (!y_cnt[y]) modify(tr_y, y, -1);
		}
		else
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;

			int cnt_x = query(tr_x, x2) - query(tr_x, x1 - 1);
			int cnt_y = query(tr_y, y2) - query(tr_y, y1 - 1);

			if (cnt_x == x2 - x1 + 1 || cnt_y == y2 - y1 + 1)
			{
				cout << "YES\n";
			}
			else cout << "NO\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}