#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int mod = 998244353;

struct edge {
	int to, next;
} e[600010];
int head[300010], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

long long qmi(int a, int k, int p)
{
	long long res = 1;

	while (k)
	{
		if (k & 1) res = (int)((long long)res * a % p);
		k >>= 1;
		a = (int)((long long)a * a % p);
	}

	return res;
}

int depth[300010];
int depth_k[300010][60];
int f[300010][20];
void bfs(int root)
{
	queue<int> q;
	memset(depth, 0x3f, sizeof(depth));
	memset(depth_k, 0, sizeof(depth_k));
	depth[0] = -1, depth[root] = 0;

	q.push(root);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (depth[j] > depth[u] + 1)
			{
				depth[j] = depth[u] + 1;
				q.push(j);

				f[j][0] = u;
				for (int k = 1; k <= 15; k++) f[j][k] = f[f[j][k - 1]][k - 1];

				depth_k[j][0] = 1;
				for (int k = 1; k <= 50; k++)
				{
					long long res = qmi(depth[j], k, mod);
					depth_k[j][k] = (int)(((long long)depth_k[u][k] + res + mod) % mod);
				}
			}
		}
	}
}

int lca(int a, int b)
{
	if (depth[a] < depth[b]) swap(a, b);
	for (int k = 15; k >= 0; k--)
		if (depth[f[a][k]] >= depth[b])
			a = f[a][k];
	if (a == b) return a;
	for (int k = 15; k >= 0; k--)
		if (f[a][k] != f[b][k])
		{
			a = f[a][k];
			b = f[b][k];
		}
	return f[a][0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b);
		add_edge(b, a);
	}

	bfs(1);

	int q;
	cin >> q;

	while (q--)
	{
		int a, b, k;
		cin >> a >> b >> k;

		int p = lca(a, b);

		long long dist = ((depth_k[a][k] + depth_k[b][k]) % mod - (depth_k[p][k] + depth_k[f[p][0]][k]) % mod + mod) % mod;

		cout << dist << '\n';
	}
}