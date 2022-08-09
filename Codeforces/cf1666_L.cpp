#include <iostream>
#include <vector>

using namespace std;

const int N = 200010;

int n, m, s;
vector<int> G[N];
int status[N];
int type = 1;
int end_id = -1;
vector<int> path_a, path_b;

bool is_ok = false;
void dfs(int u)
{
	status[u] = type;
	for (auto v : G[u])
	{
		if (is_ok) continue;
		if (u == s) type++;
		if (!status[v]) dfs(v);
		else if (status[v] && status[v] != 1 && status[v] != status[u])
		{
			is_ok = true;
			end_id = v;
		}
	}
	if (is_ok) path_a.push_back(u);
}

bool vis[N];
bool found_path = false;
void get_path(int u)
{
	vis[u] = true;
	for (auto v : G[u])
	{
		if (found_path) continue;
		if (v == end_id)
		{
			found_path = true;
		}
		else if (status[v] == status[end_id] && !vis[v])
		{
			get_path(v);
		}
	}
	path_b.push_back(u);
}

void solve()
{
	cin >> n >> m >> s;

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}

	dfs(s);

	if (is_ok) get_path(s);

	if (is_ok)
	{
		cout << "Possible\n";
		cout << path_a.size() + 1 << '\n';
		while (!path_a.empty())
		{
			cout << path_a.back() << ' ';
			path_a.pop_back();
		}
		cout << end_id << '\n';
		cout << path_b.size() + 1 << '\n';
		while (!path_b.empty())
		{
			cout << path_b.back() << ' ';
			path_b.pop_back();
		}
		cout << end_id << '\n';
	}
	else cout << "Impossible\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	solve();
}