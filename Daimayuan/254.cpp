#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const int N = 110, M = 1010;

int out[N];
double p[N];

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
		out[a]++;
		add_edge(a, b);
	}

	memset(p, 0, sizeof(p));
	p[1] = 1.0;
	for (int i = 1; i < n; i++)
	{
		for (int j = head[i]; j; j = e[j].next)
		{
			int to = e[j].to;
			p[to] += p[i] / out[i];
		}
	}

	cout << fixed << setprecision(8) << p[n];
}