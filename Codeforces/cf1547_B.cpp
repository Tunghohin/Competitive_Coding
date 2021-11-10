#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void solve()
{
	string s;
	cin >> s;

	int pl, pr;
	bool flag = false;
	for (int i = 0; i < (int)s.length(); i++)
	{
		if (s[i] == 'a')
		{
			flag = true;
			pl = pr = i;
		}
	}

	if (!flag)
	{
		cout << "NO\n";
		return;
	}

	for (int i = 1; i < (int)s.length(); i++)
	{
		if (s[pl - 1] == i + 'a' && pl >= 0)
		{
			pl--;
			continue;
		}
		else if (s[pr + 1] == i + 'a' && pr < (int)s.length())
		{
			pr++;
			continue;
		}

		cout << "NO\n";
		return;
	}

	cout << "YES\n";
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