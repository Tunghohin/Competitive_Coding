#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	long long num;
	cin >> num;

	if (num % 25 == 0)
	{
		cout << 0 << '\n';
		return;
	}

	string s = to_string(num);
	int len = (int)s.length();
	int zero_end = 0;
	bool flag = false;
	for (int i = len - 1; i >= 0 && !flag; i--)
	{
		if (s[i] == '0')
		{
			zero_end++;
			flag = true;

			for (int j = i - 1; j >= 0; j--)
			{
				if (s[j] == '0' || s[j] == '5')
				{
					zero_end++;
					zero_end += j;

					flag = true;
					break;
				}
			}
		}
	}

	int five_end = 0;
	flag = false;
	for (int i = len - 1; i >= 0 && !flag; i--)
	{
		if (s[i] == '5')
		{
			five_end++;
			flag = true;
			for (int j = i - 1; j >= 0; j--)
			{
				if (s[j] == '2' || s[j] == '7')
				{
					five_end++;
					five_end += j;

					flag = true;
					break;
				}
			}
		}
	}

	cout << len - max(zero_end, five_end) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	vector<string> get25;

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}