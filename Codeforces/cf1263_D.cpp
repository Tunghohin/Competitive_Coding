#include <iostream>
#include <cstring>

using namespace std;

int alphabet[26];

int p[200010];

int find(int x)
{
	if (p[x] != x) return p[x] = find(p[x]);
	return p[x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n , cnt = 0;
	cin >> n;

	for (int i = 0; i <= n; i++) p[i] = i;

	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		cnt++;

		for (auto j : s)
		{
			if (!alphabet[j - 'a'])
			{
				alphabet[j - 'a'] = i;
			}

			else
			{
				int px = find(i), py = find(alphabet[j - 'a']);
				if (px != py)
				{
					p[py] = px;
					cnt--;
				}
			}
		}
	}

	cout << cnt;

	return 0;
}