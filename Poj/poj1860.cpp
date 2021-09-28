#include <iostream>
#include <queue>
#include <cstring>
#define nullptr 0

using namespace std;

int cnt[110];

struct edge
{
	int to;
	double rate, commission;
	int next;
}e[220];
int head[110], tot = 0;

void add_edge(int from, int to, double rate, double commission)
{
	e[++tot].to = to;
	e[tot].rate = rate;
	e[tot].commission = commission;
	e[tot].next = head[from];
	head[from] = tot;
}

double dist[110];
bool in_que[110];
bool spfa(int st, double sum, int n)
{
	for (int i = 1; i <= n; i++) dist[i] = -10000;
	memset(in_que, false, sizeof(in_que));
	memset(cnt, 0, sizeof(cnt));

	queue<int> q;
	q.push(st);
	dist[st] = sum;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		in_que[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			double sum_ex = (dist[u] - e[i].commission) * e[i].rate;
			if (dist[j] < sum_ex && sum_ex >= 0)
			{
				dist[j] = sum_ex;
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

	int N, M, S;
	double V;
	cin >> N >> M >> S >> V;

	for (int i = 1; i <= N; i++)
	{
		int a, b;
		double r_ab, c_ab, r_ba, c_ba;
		cin >> a >> b >> r_ab >> c_ab >> r_ba >> c_ba;

		add_edge(a, b, r_ab, c_ab);
		add_edge(b, a, r_ba, c_ba);
	}

	bool res = spfa(S, V, N);

	if (res) cout << "YES";
	else cout << "NO";

	return 0;
}