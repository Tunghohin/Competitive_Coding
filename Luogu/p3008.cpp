#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

int id[25010];
int block_cnt = 0;
vector<int> blocks[25010];
int InDegree[25010];
int dist[25010];
bool vis[25010];
queue<int> q;

struct edge
{
	int to, val, next;
}e[150010];
int head[25010], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

void dfs(int u, int cnt)
{
	id[u] = cnt;
	blocks[cnt].push_back(u);

	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (!id[j])
		{
			dfs(j, cnt);
		}
	}
}

void dijkstra(int block_id)
{
	priority_queue<PII, vector<PII>, greater<PII>> heap;

	for (auto u : blocks[block_id])
	{
		heap.push({dist[u], u});
	}

	while (!heap.empty())
	{
		auto u = heap.top();
		heap.pop();

		if (vis[u.second]) continue;

		vis[u.second] = true;

		for (int i = head[u.second]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (id[u.second] != id[j] && --InDegree[id[j]] == 0) q.push(id[j]);
			if (dist[j] > dist[u.second] + e[i].val)
			{
				dist[j] = dist[u.second] + e[i].val;
				if (id[j] == id[u.second]) heap.push({dist[j], j});
			}
		}
	}
}

void TopologicalSort(int S)
{
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, false, sizeof(vis));
	dist[S] = 0;

	for (int i = 1; i <= block_cnt; i++)
	{
		if (!InDegree[i]) q.push(i);
	}

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		dijkstra(u);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T, R, P, S;
	cin >> T >> R >> P >> S;

	while (R--)
	{
		int f, t, v;
		cin >> f >> t >> v;
		add_edge(f, t, v);
		add_edge(t, f, v);
	}

	for (int i = 1; i <= T; i++)
	{
		if (!id[i])
		{
			block_cnt++;
			dfs(i, block_cnt);
		}
	}

	while (P--)
	{
		int f, t, v;
		cin >> f >> t >> v;
		InDegree[id[t]]++;
		add_edge(f, t, v);
	}

	TopologicalSort(S);

	for (int i = 1; i <= T; i++)
	{
		if (dist[i] > 0x3f3f3f3f / 2) cout << "NO PATH\n";
		else cout << dist[i] << '\n';
	}
}