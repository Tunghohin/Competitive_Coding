#include <iostream>
#include <algorithm>

using namespace std;

bool solve()
{
	string s1, s2;
	cin >> s1 >> s2;

	int s1_size = s1.size();
	int s2_size = s2.size();

	for (int i = 0; i < s1_size; i++)
	{
		for (int j = 0; i + j < s1_size; j++)
		{
			int k = s2_size - (j + 1);

			if (i + j < k || k < 0) continue;

			int l1 = i, l2 = i + j - k;

			string tmp = s1.substr(l2, k);
			reverse(tmp.begin(), tmp.end());

			if (s1.substr(l1, j + 1) + tmp == s2) return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		bool flag = solve();
		cout << (flag? "Yes\n" : "No\n");
	}

	return 0;
}