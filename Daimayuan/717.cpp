#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 1000010;

int a[N];
int res[N];

struct Node
{
	int L, R;
}tr[N];

int build(int n)
{
	stack<int> stk;
	int root = 0;

	for (int i = 1; i <= n; i++)
	{
		int last = 0;
		while (!stk.empty() && a[stk.top()] > a[i])
		{
			last = stk.top();
			stk.pop();
		}

		if (!stk.empty()) tr[stk.top()].R = i;
		else root = i;

		tr[i].L = last;
		stk.push(i);
	}

	return root;
}

int now;
void dfs(int u)
{
	res[u] = now++;
	if (tr[u].L) dfs(tr[u].L);
	if (tr[u].R) dfs(tr[u].R);
}

void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	int root = build(n);
	now = 1;
	dfs(root);

	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}

int main()
{
	int T;
	T = 1;

	while (T--)
	{
		solve();
	}
}