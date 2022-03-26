#include <iostream>
#include <vector>

using namespace std;

const int N = 30;

vector<int> v[N];
int val[N];

bool check(int k, int num)
{
	if (v[k].empty()) return true;
	for (auto i : v[k])
	{
		if (((num >> i) & 1) == 0) return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> val[i];

	for (int i = 0; i < n; i++)
	{
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++)
		{
			int x;
			cin >> x;
			v[i].push_back({x - 1});
		}
	}

	int res = -0x3f3f3f3f;
	for (int i = 0; i <= ((1 << n) - 1); i++)
	{
		bool ok = true;
		int cur_res = 0;
		for (int k = 0; k < n; k++)
		{
			int bit = (i >> k) & 1;
			if (bit)
			{
				if (check(k, i))
				{
					cur_res += val[k];
				}
				else
				{
					ok = false;
					break;
				}
			}
		}

		if (ok) res = max(res, cur_res);
	}

	cout << res;
}