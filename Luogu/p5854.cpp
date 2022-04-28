#include <iostream>
#include <stack>

using namespace std;

const int N = 10000010;
int a[N];

inline int read()
{
	int x = 0, flag = 1;
	char ch = getchar();
	for( ; ch > '9' || ch < '0' ; ch = getchar()) if(ch == '-') flag = -1;
	for( ; ch >= '0' && ch <= '9' ; ch = getchar()) x = (x << 3) + (x << 1) + ch - '0';
	return x * flag;
}

struct Node
{
	int L, R;
}tr[N];

int stk[N];
int build(int n)
{
	int root = 0;
	int top = 0;

	for (int i = 1; i <= n; i++)
	{
		int last = 0;
		while (top && a[stk[top]] > a[i])
		{
			last = stk[top];
			top--;
		}

		if (top) tr[stk[top]].R = i;
		else root = i;

		tr[i].L = last;
		stk[++top] = i;
	}

	return root;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	n = read();

	for (int i = 1; i <= n; i++) a[i] = read();

	build(n);

	long long res_L = 0, res_R = 0;
	for (int i = 1; i <= n; i++)
	{
		res_L ^= 1ll * i * (tr[i].L + 1);
		res_R ^= 1ll * i * (tr[i].R + 1);
	}

	cout << res_L << ' ' << res_R;
}