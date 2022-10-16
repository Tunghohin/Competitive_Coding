#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using PII = pair<int, int>;

const int N = 210;

bool is_stu[N], go_home[N];
bool mp[N][N];

struct edge
{
    int to, next;
}e[100010];
int head[1010], tot = 0;

void add_edge(int from, int to)
{
    e[++tot].to = to;
    e[tot].next = head[from];
    head[from] = tot;
}

bool vis[1010];
int matched[1010];
bool KM(int x)
{
    for (int i = head[x]; i; i = e[i].next)
    {
        int j = e[i].to;

        if (!vis[j])
        {
            vis[j] = true;
            if (!matched[j] || KM(matched[j]))
            {
                matched[j] = x;
                return true;
            }
        }
    }

    return false;
}

void solve()
{
	int n;
	cin >> n;

	memset(matched, 0, sizeof(matched));
	memset(head, 0, sizeof(head));
	tot = 0;

	int need_cnt = 0;
	for (int i = 1; i <= n; i++) cin >> is_stu[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> go_home[i];
		if (is_stu[i] && !go_home[i]) need_cnt++;
		else if (!is_stu[i]) need_cnt++; 
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> mp[i][j];
			if (!is_stu[j]) mp[i][j] = 0;
		}
		if (is_stu[i]) mp[i][i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (mp[i][j]) add_edge(i, j + n);
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (is_stu[i] && go_home[i]) continue;
		memset(vis, 0, sizeof(vis));
		if (KM(i)) res++;
	}

	if (res >= need_cnt) cout << "^_^\n";
	else cout << "T_T\n";
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