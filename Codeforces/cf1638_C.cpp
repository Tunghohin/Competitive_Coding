#include <iostream>
#include <stack>

using namespace std;

int a[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) cin >> a[i];

		stack<pair<int, int>> s;
		s.push({a[1], a[1]}); //max, min

		for (int i = 2; i <= n; i++)
		{
			pair<int, int> t = {a[i], a[i]};
			pair<int, int> u;
			while (!s.empty() && s.top().first > t.second)
			{
				u = s.top();
				s.pop();

				t = {max(u.first, t.first), min(u.second, t.second)};
			}

			s.push(t);
		}

		cout << s.size() << '\n';
	}
}