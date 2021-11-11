#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int N = 510, M = 1010;

typedef pair<int, int> PII;

struct edge
{
	int to, next, val;
}e[2 * M];
int head[N], tot = 0;

void add_edge(int from, int to, int val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

int dist_st[N], dist_bk[N];
int pre_st[N], pre_bk[N];
bool vis[N];
void dijkstra(int st, int dist[], int pre[])
{
	for (int i = 0; i < N; i++)
	{
		vis[i] = false;
		pre[i] = -1;
		dist[i] = 0x3f3f3f3f;
	}

	dist[st] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({dist[st], st});

	while (!pq.empty())
	{
		auto u = pq.top();
		pq.pop();

		if (vis[u.second]) continue;
		vis[u.second] = true;

		for (int i = head[u.second]; i; i = e[i].next)
		{
			int j = e[i].to;
			int val = e[i].val;

			if (dist[j] > dist[u.second] + val)
			{
				dist[j] = dist[u.second] + val;
				pre[j] = u.second;
				pq.push({dist[j], j});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, S, E;
	int case_cnt = 0;
	while (cin >> n >> S >> E)
	{
		if (case_cnt++) cout << '\n';

		tot = 0;
		memset(head, 0, sizeof(head));

		int m;
		cin >> m;
		while (m--)
		{
			int x, y, z;
			cin >> x >> y >> z;
			add_edge(x, y, z);
			add_edge(y, x, z);
		}

		dijkstra(S, dist_st, pre_st);
		dijkstra(E, dist_bk, pre_bk);

		int dist = dist_st[E];

		int k;
		cin >> k;
		PII fast_line = {-1, -1};
		while (k--)
		{
			int x, y, z;
			cin >> x >> y >> z;

			if (dist_st[x] + dist_bk[y] + z < dist)
			{
				dist = dist_st[x] + dist_bk[y] + z;
				fast_line = {x, y};
			}
			if (dist_st[y] + dist_bk[x] + z < dist)
			{
				dist = dist_st[y] + dist_bk[x] + z;
				fast_line = {y, x};
			}
		}

		if (fast_line.first == -1)
		{
			vector<int> path;
			int now = E;
			path.push_back(now);
			while (now != S)
			{
				path.push_back(pre_st[now]);
				now = pre_st[now];
			}
			reverse(path.begin(), path.end());

			for (int i = 0; i < (int)path.size() - 1; i++) cout << path[i] << ' ';
			cout << path.back();
			cout << '\n';
			cout << "Ticket Not Used\n";
			cout << dist_st[E] << '\n';
		}
		else
		{
			vector<int> path;
			int now = fast_line.first;
			path.push_back(now);
			while (now != S)
			{
				path.push_back(pre_st[now]);
				now = pre_st[now];
			}

			reverse(path.begin(), path.end());
			now = fast_line.second;
			path.push_back(now);
			while (now != E)
			{
				path.push_back(pre_bk[now]);
				now = pre_bk[now];
			}

			for (int i = 0; i < (int)path.size() - 1; i++) cout << path[i] << ' ';
			cout << path.back();
			cout << '\n';
			cout << fast_line.first << '\n';
			cout << dist << '\n';
		}
	}
}