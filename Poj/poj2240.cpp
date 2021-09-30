#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#define nullptr 0

using namespace std;

struct edge
{
	double rate;
	int to, next;
}e[1000010];
int head[32], tot = 0;

void add_edge(int from, int to, double rate)
{
	e[++tot].to = to;
	e[tot].rate = rate;
	e[tot].next = head[from];
	head[from] = tot;
}

double dist[32];
bool in_que[32];
int cnt[32];
bool spfa(int n)
{
	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		dist[i] = 100000;
		q.push(i);
		in_que[i] = true;
		cnt[i] = 0;
	}

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		in_que[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (dist[j] < dist[u] * e[i].rate)
			{
				dist[j] = dist[u] * e[i].rate;
				cnt[j] = cnt[u] + 1;

				if (cnt[j] >= n) return true;

				if (!in_que[j])
				{
					q.push(j);
					in_que[j] = true;
				}
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	int kase = 0;
	while (cin >> n && n)
	{
		kase++;
		memset(head, 0, sizeof(head));
		tot = 0;

		map<string, int> mp;

		for (int i = 1; i <= n; i++)
		{
			string s;
			cin >> s;
			mp[s] = i;
		}

		int m;
		cin >> m;

		for (int i = 1; i <= m; i++)
		{
			string a, b;
			double rate;
			cin >> a >> rate >> b;

			int f = mp[a], t = mp[b];
			add_edge(f, t, rate);
		}

		cout << "Case " << kase << ": ";
		if (spfa(n)) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}