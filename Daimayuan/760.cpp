#include <iostream>
#include <queue>

using namespace std;

const int N = 10010, M = 100010;

int in_degree[N];

struct edge
{
	int to, next;
}e[M];
int head[N], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

void topological_sort(int n)
{
	priority_queue<int, vector<int>, greater<int>> q;

	for (int i = 1; i <= n; i++)
	{
		if (in_degree[i] == 0) q.push(i);
	}

	while (!q.empty())
	{
		int u = q.top();
		cout << u << ' ';
		q.pop();
		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;
			in_degree[j]--;
			if (in_degree[j] == 0) q.push(j);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;

		add_edge(a, b);
		in_degree[b]++;
	}

	topological_sort(n);
}