#include <iostream>
#include <queue>

using namespace std;

const int N = 200010;

template<typename T>
class graph{
private:
	struct edge
	{
		int to, next;
		T val_a, val_b;
	} e[N];
	int head[N], tot = 0;
	T prefix_a[N], prefix_b[N];
	int depth[N];
	int f[N][30];
	int m_sz;

public:
	void init(int n)
	{
		tot = 0;
		m_sz = n;
		for (int i = 1; i <= n; i++)
		{
			depth[i] = 0x3f3f3f3f;
			head[i] = 0;
			prefix_a[i] = 0;
			prefix_b[i] = 0;
		}
	}

	void bfs(int root)
	{
		queue<int> q;
		q.push(root);

		depth[0] = 0, depth[root] = 1;

		while (!q.empty())
		{
			int u = q.front();
			q.pop();

			for (int i = head[u]; i; i = e[i].next)
			{
				int v = e[i].to;

				if (depth[v] > depth[u] + 1)
				{
					depth[v] = depth[u] + 1;
					prefix_a[v] = prefix_a[u] + e[i].val_a;
					prefix_b[v] = prefix_b[u] + e[i].val_b;
					q.push(v);

					f[v][0] = u;
					for (int k = 1; k <= 25; k++) f[v][k] = f[f[v][k - 1]][k - 1];
				}
			}
		}
	}

	void get_res()
	{
		for (int i = 2; i <= m_sz; i++)
		{
			int cur = i;
			for (int k = 25; k >= 0; k--)
			{
				if (f[cur][k] && (prefix_b[f[cur][k]] > prefix_a[i])) cur = f[cur][k];
			}
			if (prefix_b[cur] <= prefix_a[i]) cout << depth[cur] - 1 << ' ';
			else cout << depth[cur] - 2 << ' ';
		}
		cout << '\n';
	}

	void add_edge(int from, int to, T val_a, T val_b)
	{
		e[++tot] = {to, head[from], val_a, val_b}; head[from] = tot;
	}
};

graph<long long> g;
void solve()
{
	int n;
	cin >> n;

	g.init(n);

	for (int i = 2; i <= n; i++)
	{
		int x;
		int val_a, val_b;
		cin >> x >> val_a >> val_b;
		g.add_edge(x, i, val_a, val_b);
	}

	g.bfs(1);
	g.get_res();
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