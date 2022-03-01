#include <iostream>
#include <unordered_map>

using namespace std;

int prefix[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	unordered_map<int, int> vis;

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		prefix[i] = (prefix[i - 1] + x) % n;
	}

	vis[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		int num = prefix[i] % n;

		if (vis.count(num))
		{
			cout << (i - vis[num]) << '\n';
			for (int j = vis[num] + 1; j <= i; j++)
			{
				cout << j << ' ';
			}
			break;
		}

		vis[num] = i;
	}
}