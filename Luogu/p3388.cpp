#include <iostream>
#include <vector>

using namespace std;

const int N = 20010, M = 200010;

struct edge
{
	int to, next;
}e[M];
int head[N], tot;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int root;
int dfn[N], low[N], timestamp = 0;
bool is_cnt[N];
void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;

	int cnt = 0;
	for (int i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;

		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);

			if (dfn[u] <= low[j])
			{
				cnt++;
				if (u != root || cnt > 1) is_cnt[u] = true;
			}
		}

		else low[u] = min(low[u], dfn[j]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add_edge(a, b), add_edge(b, a);
	}

	for (root = 1; root <= n; root++)
	{
		if (!dfn[root]) tarjan(root);
	}

	int cnt = 0;
	vector<int> cut;
	for (int i = 1; i <= n; i++)
	{
		if (is_cnt[i])
		{
			cnt++;
			cut.push_back(i);
		}
	}

	cout << cnt << '\n';
	for (auto i : cut) cout << i << ' ';

	return 0;
}