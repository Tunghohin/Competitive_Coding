#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
using PII = pair<int, int>;

const int N = 300010;

template<typename T>
class binary_index_tree
{
private:
	int m_size;
	T tr[N];

	int low_bit(int num)
	{
		return num & (-num);
	}

public:
	void init(int size)
	{
		m_size = size;
	}

	void modify(int idx, T v)
	{
		for (; idx <= m_size; idx += low_bit(idx))
		{
			tr[idx] += v;
		}
	}

	T query(int idx)
	{
		T res = 0;
		for(; idx; idx -= low_bit(idx))
		{
			res += tr[idx];
		}

		return res;
	}
};

long long ans[N];
vector<int> vx;
vector<array<int, 4>> event;
binary_index_tree<long long> tr;
int n, q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n >> q;

	vector<PII> v;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		v.push_back({x, i});
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)
	{
		int x, y;
		if (i == 0)
		{	
			x = v[i].second;
			y = v[i + 1].second;
		}
		else if (i == n - 1)
		{
			x = v[i].second;
			y = v[i - 1].second;
		}
		else
		{
			if (abs(v[i - 1].first - v[i].first) < abs(v[i + 1].first - v[i].first))
			{
				x = v[i].second;
				y = v[i - 1].second;
			}
			else if (abs(v[i - 1].first - v[i].first) > abs(v[i + 1].first - v[i].first))
			{
				x = v[i].second;
				y = v[i + 1].second;
			}
			else 
			{
				x = v[i].second;
				y = v[i - 1].second;
				int cur_y = v[i + 1].second;
				vx.push_back(x);
				event.push_back({cur_y, 0, x});
			}
		}
		vx.push_back(x);
		event.push_back({y, 0, x});
	}

	for (int i = 1; i <= q; i++)
	{
		int l, r;
		cin >> l >> r;
		int x1 = l, x2 = r, y1 = l, y2 = r;
		event.push_back({y2, 2, x2, i});
		event.push_back({y1 - 1, 2, x1 - 1, i});
		event.push_back({y2, 1, x1 - 1, i});
		event.push_back({y1 - 1, 1, x2, i});
	}

	sort(event.begin(), event.end());
	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	tr.init((int)vx.size());

	for (auto evt : event)
	{
		if (evt[1] == 0)
		{
			int y = lower_bound(vx.begin(), vx.end(), evt[2]) - vx.begin() + 1;
			tr.modify(y, 1);
		}
		else
		{
			int y = upper_bound(vx.begin(), vx.end(), evt[2]) - vx.begin();
			int tmp = tr.query(y);
			if (evt[1] == 1) ans[evt[3]] -= tmp;
			else ans[evt[3]] += tmp;
		}
	}

	long long res = 0;
	for (int i = 1; i <= q; i++)
	{
		res += i * ans[i];
	}
	cout << res << '\n';
}