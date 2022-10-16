#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

void solve()
{
	string a, b;
	cin >> a >> b;

	if (a.back() == 'S')
	{
		if (b.back() != 'S')
		{
			cout << "<\n";
			return;
		}
		if (a.size() < b.size())
		{
			cout << ">\n";
			return;
		}
		else if (a.size() == b.size())
		{
			cout << "=\n";
		}
		else
		{
			cout << "<\n";
			return;
		}
	}
	else if (a.back() == 'M')
	{
		if (b.back() == 'M')
		{
			cout << "=\n";
			return;
		}
		if (b.back() == 'L')
		{
			cout << "<\n";
			return;
		}
		if (b.back() == 'S')
		{
			cout << ">\n";
			return;
		}
	}
	else
	{
		if (b.back() != 'L')
		{
			cout << ">\n";
			return;
		}
		if (a.size() < b.size())
		{
			cout << "<\n";
			return;
		}
		else if (a.size() == b.size())
		{
			cout << "=\n";
		}
		else
		{
			cout << ">\n";
			return;
		}
	}
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