#include <iostream>
#include <vector>

using namespace std;

const int N = 1010;

vector<int> G[N];

int color[N];
bool bio_graph(int u, int type)
{
	color[u] = type;
	for (auto to: G[u])
		if (!color[to])
		{
			if (!bio_graph(to, 3 - type)) return false;
		}
		else if (color[to] == type) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		if (!color[i])
		{
			if (!bio_graph(i, 1))
			{
				flag = false;
				break;
			}
		}
	}

	flag? cout << "Yes\n" : cout << "No\n";
}