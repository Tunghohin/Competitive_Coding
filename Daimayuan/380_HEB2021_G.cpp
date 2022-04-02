#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>

using namespace std;

const int N = 200010;

typedef pair<int, int> PII;

int t, r, n, m, k;
int pos[22];
vector<PII> s(30);

struct edge
{
	int to, next, val;
}e[2 * N];
int head[N], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

int d[22][22];
int dist[N];
bool vis[N];
void dijkstra(int st)
{
	for (int i = 0; i <= n; i++)
	{
		vis[i] = false;
		dist[i] = 0x3f3f3f3f;
	}
	priority_queue<PII, vector<PII>, greater<PII>> q;
	dist[st] = 0;
	q.push({dist[st], st});

	while (!q.empty())
	{
		auto u = q.top();
		q.pop();

		if (vis[u.second]) continue;
		vis[u.second] = true;

		for (int i = head[u.second]; i; i = e[i].next)
		{
			int j = e[i].to;
			if (dist[j] > dist[u.second] + e[i].val)
			{
				dist[j] = dist[u.second] + e[i].val;
				q.push({dist[j], j});
			}
		}
	}
}

double dp[1 << 20][30];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> t >> r;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b, v;
		cin >> a >> b >> v;
		add_edge(a, b, v);
		add_edge(b, a, v);
	}

	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		int a, p;
		cin >> a >> p;
		s[i] = {a, p};
		pos[i] = a;
	}
	pos[0] = 1, pos[k + 1] = n;

	for (int i = 0; i <= k + 1; i++)
	{
		dijkstra(pos[i]);
		for (int j = 0; j <= k + 1; j++)
		{
			d[i][j] = dist[pos[j]];
		}
	}


	if (d[0][k + 1] == 0x3f3f3f3f)
	{
		cout << -1;
		return 0;
	}

	for (int S = (1 << k) - 1; S >= 0; S--)
	{
		for (int i = 1; i <= k; i++)
		{
			double p_bike = 0.01 * s[i].second;
			double bike = (double)d[i][k + 1] / (double)r;
			double no_bike = (double)d[i][k + 1] / (double)t;

			for (int p = 1; p <= k; p++)
			{
				if (!(S & (1 << (p - 1))))
				{
					no_bike = min(no_bike, (double)d[i][p] / (double)t + dp[S + (1 << (p - 1))][p]);
				}
			}
			dp[S][i] = p_bike * no_bike + (1.0 - p_bike) * bike;
		}
	}

	double res = (double)d[0][k + 1] / (double)t;
	for (int i = 1; i <= k; i++)
	{
		res = min(res, (double)d[0][i] / (double)t + dp[1 << (i - 1)][i]);
	}
	cout << fixed << setprecision(6) << res;
}