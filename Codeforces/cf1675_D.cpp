#include <iostream>
#include <vector>

using namespace std;

struct edge
{
	int to, next;
}e[200010];
int head[200010], tot;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

vector<vector<int>> paths;
void dfs(int u)
{
	int fst = head[u];
	int to = e[fst].to;
	if (fst) paths.back().push_back(to);
	if (fst) dfs(to);

	for (int i = e[head[u]].next; i; i = e[i].next)
	{
		int j = e[i].to;
		vector<int> new_path;
		new_path.push_back(j);
		paths.push_back(new_path);
		dfs(j);
	}
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		head[i] = 0;
	}
	tot = 0;
	paths.clear();

	int root = -1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == i) root = i;
		else add_edge(x, i);
	}

	vector<int> root_path;
	root_path.push_back(root);
	paths.push_back(root_path);

	dfs(root);

	cout << paths.size() << '\n';
	for (auto &v : paths)
	{
		cout << v.size() << '\n';
		for (auto &vv : v)
		{
			cout << vv << ' ';
		}
		cout << '\n';
	}

	cout << '\n';
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