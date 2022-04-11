#include <iostream>
#include <cstring>

using namespace std;

const int N = 40;
int c[N], cw[N], w[N];
int cnt[N], id[N];
int dp[N][1 << 20];
int res[N];

int bit(int x)
{
	return (1 << x);
}

struct edge
{
	int to, next;
}e[N * N];
int head[N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
		cnt[c[i]]++;
	}
	for (int i = 1; i <= n; i++) cin >> cw[i];
	for (int i = 1; i <= n; i++) w[i] = cw[c[i]];

	int bit_cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] < 2) id[i] = -1;
		else id[i] = ++bit_cnt;
	}
	for (int i = 1; i <= n; i++)
	{
		c[i] = id[c[i]];
	}

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
	}

	memset(dp, -1, sizeof(dp));
	if (c[1] != -1) dp[1][bit(c[1] - 1)] = w[1];
	else dp[1][0] = w[1];

	for (int i = 1; i <= n; i++)
	{
		for (int j = head[i]; j; j = e[j].next)
		{
			int to = e[j].to;
			if (c[to] == -1)
			{
				for (int k = 0; (k < bit(bit_cnt)); k++)
				{
					if (dp[i][k] == -1) continue;
					dp[to][k] = max(dp[to][k], dp[i][k] + w[to]);
				}
				continue;
			}
			else
			{
				for (int k = 0; (k < (1 << bit_cnt)); k++)
				{
					if (dp[i][k] == -1) continue;
					if ((k & bit(c[to] - 1)) == 0)
					{
						dp[to][k + bit(c[to] - 1)] = max(dp[to][k + bit(c[to] - 1)], dp[i][k] + w[to]);
					}
					else
					{
						dp[to][k] = max(dp[to][k], dp[i][k]);
					}
				}
			}
		}
	}


	for (int i = 1; i <= n; i++)
	{
		res[i] = -1;
		for (int j = 0; j < bit(bit_cnt); j++) res[i] = max(res[i], dp[i][j]);
	}

	for (int i = 1; i <= n; i++) cout << res[i] << '\n';
}