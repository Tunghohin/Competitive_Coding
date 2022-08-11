#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

using namespace std;

int n, m;
const int N = 200010;

template<typename T>
class binary_index_tree {
private:
	T tr[N];
	int m_size;

	int low_bit(int x)
	{
		return x & (-x);
	}
public:
	void init(int sz)
	{
		m_size = sz;
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
		T res;
		for (; x; x -= low_bit(x))
		{
			res += tr[x];
		}
		return res;
	}
};

//pos type modify_pos pid
//type 0->add, 1->query_sub, 2->query_add
long long res[N];
vector<array<int, 4>> event;
vector<int> hashed;
binary_index_tree<long long> tr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		hashed.push_back(y);
		event.push_back({x, 0, y, 2});
	}

	for (int i = 1; i <= m; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		event.push_back({x2, 2, y2, i});
		event.push_back({x1 - 1, 2, y1 - 1, i});
		event.push_back({x2, 1, y1 - 1, i});
		event.push_back({x1 - 1, 1, y2, i});
	}

	sort(hashed.begin(), hashed.end());
	hashed.erase(unique(hashed.begin(), hashed.end()), hashed.end());
	sort(event.begin(), event.end());
	tr.init(hashed.size());

	for (auto evt : event)
	{
		if (evt[1] == 0)
		{
			int y = lower_bound(hashed.begin(), hashed.end(), evt[2]) - hashed.begin() + 1;
			tr.modify(y, 1);
		}
		else
		{
			int y = upper_bound(hashed.begin(), hashed.end(), evt[2]) - hashed.begin();
			long long tmp = tr.query(y);
			if (evt[1] == 1) res[evt[3]] -= tmp;
			else res[evt[3]] += tmp;
		}
	}

	for (int i = 1; i <= m; i++) cout << res[i] << '\n';
}