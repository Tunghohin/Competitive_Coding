#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

void solve()
{
	vector<int> a(3);
	for (int i = 0; i < 3; i++) cin >> a[i];

	sort(a.begin(), a.end());
	
	if (a[0] + a[1] == a[2])
	{
		cout << "Yes\n";
	}
	else cout << "No\n";
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