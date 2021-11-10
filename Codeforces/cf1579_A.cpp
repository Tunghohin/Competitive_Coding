#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	string s;
	cin >> s;

	int cnt_a = 0, cnt_b = 0, cnt_c = 0;
	for (int i = 0; i <= (int)s.length(); i++)
	{
		if (s[i] == 'A') cnt_a++;
		else if (s[i] == 'B') cnt_b++;
		else if (s[i] == 'C') cnt_c++;
	}

	if (cnt_b == cnt_a + cnt_c) cout << "YES\n";
	else cout << "NO\n";
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