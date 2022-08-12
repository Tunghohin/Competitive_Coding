#include <iostream>

using namespace std;

int a[200010];

template<typename T>
class binary_index_tree {
public:
	int m_size;
	T tr[200010];
	int low_bit(int x)
	{
		return x & (-x);
	}

	void init(int n)
	{
		m_size = n;
		for (int i = 1; i <= n; i++) tr[i] = 0;
	}

	void modify(int x, T v)
	{
		for (; x <= m_size; x += low_bit(x))
		{
			tr[x] += v;
		}
	}

	T query(int x)
	{
		T res = 0;
		for (; x; x -= low_bit(x))
		{
			res += tr[x];
		}
		return res;
	}
};

binary_index_tree<int> t;
void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	t.init(n);
	long long res = 0;
	for (int i = n; i >= 1; i--)
	{
		res += (long long)t.query(a[i]);
		t.modify(a[i], 1);
	}

	cout << res << '\n';
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