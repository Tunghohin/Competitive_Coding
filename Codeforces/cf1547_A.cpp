#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void solve()
{
	pair<int, int> A, B, F;
	cin >> A.first >> A.second >> B.first >> B.second >> F.first >> F.second;

	if (A.first == B.first)
	{
		cout << abs(A.second - B.second) + (2 * ((F.first == A.first)
			&& F.second >= min(A.second, B.second) && F.second <= max(A.second, B.second))) << '\n';
	}

	else if (A.second == B.second)
	{
		cout << abs(A.first - B.first) + (2 * ((F.second == A.second)
			&& F.first >= min(A.first, B.first) && F.first <= max(A.first, B.first))) << '\n';
	}

	else
	{
		int dx = abs(A.first - B.first);
		int dy = abs(A.second - B.second);
		cout << dx + dy << '\n';
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