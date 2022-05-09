#include <iostream>
#include <vector>

using namespace std;

const int N = 200010;
const int M = 500;

vector<int> G[N];
vector<int> big[N];
int val[N];
int is_big[N];
int res[N];

void solve()
{
	int n, m, q;
	cin >> n >> m >> q;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		if (G[i].size() >= M) is_big[i] = true;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int to : G[i])
		{
			if (is_big[to]) big[i].push_back(to);
		}
	}

	while (q--)
	{
		int op, x;
		cin >> op >> x;

		if (op == 1)
		{
			val[x] = (val[x] + 1) % 2;
			for (auto to : big[x])
			{
				val[x]? res[to]++ : res[to]--;
			}
		}
		else
		{
			if (is_big[x]) cout << res[x] << '\n';
			else
			{
				int cnt = 0;
				for (auto to : G[x])
				{
					if (val[to]) cnt++;
				}

				cout << cnt << '\n';
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}