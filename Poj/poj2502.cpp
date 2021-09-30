#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#define nullptr 0

using namespace std;

typedef pair<int, int> PII;

struct edge
{
	int to, next;
	double val;
}e[4000010];
int head[400], tot = 0;

void add_edge(int from, int to, double val)
{
	e[++tot].to = to;
	e[tot].val = val;
	e[tot].next = head[from];
	head[from] = tot;
}

double get_dist(PII a, PII b, bool type) //0 for walk
{
	int dx = a.first - b.first;
	int dy = a.second - b.second;

	double dis = sqrt(dx * dx + dy * dy);

	return type? dis / 40 / 1000 * 60: dis / 10 / 1000 * 60;
}

double dist[400];
bool in_que[400];
void spfa()
{
	for (int i = 1; i < 400; i++)
	{
		dist[i] = 1e18;
		in_que[i] = false;
	}

	queue<int> q;
	q.push(0);
	in_que[0] = true;
	dist[0] = 0;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		in_que[u] = false;

		for (int i = head[u]; i; i = e[i].next)
		{
			int j = e[i].to;

			if (dist[j] > dist[u] + e[i].val)
			{
				dist[j] = dist[u] + e[i].val;

				if (!in_que[j])
				{
					q.push(j);
					in_que[j] = true;
				}
			}
		}
	}
}

int main()
{

	PII st, ed;
	cin >> st.first >> st.second >> ed.first >> ed.second;

	int cnt = 1;
	vector<PII> stop(400);
	stop[0] = st;

	int x, y;
	while (cin >> x >> y)
	{
		stop[cnt++] = {x, y};
		int xx, yy;
		while (cin >> xx >> yy)
		{
			if (xx == -1 && yy == -1) break;
			stop[cnt++] = {xx, yy};
			double dis = get_dist(stop[cnt - 1], stop[cnt - 2], true);

			add_edge(cnt - 2, cnt - 1, dis);
			add_edge(cnt - 1, cnt - 2, dis);
		}
	}

	stop[cnt] = {ed.first, ed.second};

	for (int i = 0; i <= cnt; i++)
	{
		for (int j = 0; j < i; j++)
		{
			double dis = get_dist(stop[i], stop[j], false);

			add_edge(i, j, dis);
			add_edge(j, i, dis);
		}
	}

	spfa();

	printf("%d", int(dist[cnt] + 0.5));

	return 0;
}