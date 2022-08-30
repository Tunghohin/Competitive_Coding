#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 3010;

int n, m;
int val[N];
LL dp[N][N];

template<typename T>
class tree {
public:
	struct edge
	{
		int to, next;
		T val;
	} e[N];
	int head[N], tot = 0;

	void add_edge(int from, int to, T val)
	{
		e[++tot] = {to, head[from], val}; head[from] = tot;
	}
};
tree<LL> tr;

int dfs(int u)
{
	if (u > n - m)
	{
		dp[u][1] = val[u];
		return 1;
	}

	int sum = 0, tmp;
	for (int i = tr.head[u]; i; i = tr.e[i].next)
	{
		int v = tr.e[i].to;
		tmp = dfs(v);
		sum += tmp;
		int cost = tr.e[i].val;

		for (int j = sum; j > 0; j--)
		{
			for (int k = 1; k <= tmp; k++)
			{
				if (j - k >= 0)
				{
					dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k] - cost);
				}
			}
		}
	}

	return sum;
}

void solve()
{
	cin >> n >> m;

	memset(dp, -0x3f, sizeof(dp));

	for (int i = 1; i <= n - m; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int nx, nx_v;
			cin >> nx >> nx_v;
			tr.add_edge(i, nx, nx_v);
		}
	}

	for (int i = n - m + 1; i <= n; i++) cin >> val[i];
	for (int i = 1; i <= n; i++) dp[i][0] = 0;

	dfs(1);

	for (int i = m; i >= 1; i--)
	{
		if (dp[1][i] >= 0)
		{
			cout << i << '\n';
			break;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}