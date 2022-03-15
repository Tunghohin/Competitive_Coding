#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#define int long long

using namespace std;

int n;
int size[100010];
long long res;

struct edge
{
	int to, next;
}e[200010];
int head[100010], tot = 0;

void add_edge(int from, int to)
{
	e[++tot].to = to;
	e[tot].next = head[from];
	head[from] = tot;
}

int cal2(vector<int>&a) {
	if (a.size() < 2)return 0;
	int sum = accumulate(a.begin(), a.end(), 0ll);
	int sum1 = 0; for (int x : a)sum1 += x * x;
	return (sum*sum - sum1) / 2;
}
int cal3(vector<int>&a) {
	if (a.size() < 3)return 0;
	int sum = accumulate(a.begin(), a.end(), 0ll);
	int sum1 = 0; for (int x : a)sum1 += x * x * x;
	int sum2 = 0; for (int x : a)sum2 += 3 * x * x * (sum - x);
	return (sum*sum*sum - sum1 - sum2) / 6;
}

void dfs(int u, int from)
{
	vector<int> child;
	size[u] = 1;

	for (auto i = head[u]; i; i = e[i].next)
	{
		int j = e[i].to;
		if (j == from) continue;
		dfs(j, u);
		size[u] += size[j];
		child.push_back(size[j]);
	}

	res += cal2(child) * (n - size[u]);
	res += cal3(child);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int f, t, v;
		cin >> f >> t >> v;
		add_edge(f, t), add_edge(t, f);
	}

	dfs(1, 0);
	cout << res << '\n';
}