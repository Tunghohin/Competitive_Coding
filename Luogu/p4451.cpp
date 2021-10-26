#include <iostream>

using namespace std;

const int N = 600010, M = 25 * N;

int idx = 0;
int root[N], max_R[M];
int prefix_xor[N];
int tr[M][2];

void insert(int i, int k, int p, int q)
{
	if (k < 0)
	{
		max_R[q] = i;
		return;
	}

	int v = prefix_xor[i] >> k & 1;
	if (p) tr[q][v ^ 1] = tr[p][v ^ 1];
	tr[q][v] = ++idx;

	insert(i, k - 1, tr[p][v], tr[q][v]);
	max_R[q] = max(max_R[tr[q][0]], max_R[tr[q][1]]);
}

int query(int _root, int C, int L)
{
	int p = _root;
	for (int i = 23; i >= 0; i--)
	{
		int v = C >> i & 1;
		if (max_R[tr[p][v ^ 1]] >= L) p = tr[p][v ^ 1];
		else p = tr[p][v];
	}

	return C ^ prefix_xor[max_R[p]];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	max_R[0] = -1;
	root[0] = ++idx;

	insert(0, 23, 0, root[0]);

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		prefix_xor[i] = prefix_xor[i - 1] ^ x;
		root[i] = ++idx;
		insert(i, 23, root[i - 1], root[i]);
	}

	char op[2];
	int l, r, x;

	while (m--)
	{
		cin >> op;
		if (*op == 'A')
		{
			cin >> x;
			n++;
			prefix_xor[n] = prefix_xor[n - 1] ^ x;
			root[n] = ++idx;
			insert(n, 23, root[n - 1], root[n]);
		}

		else
		{
			cin >> l >> r >> x;
			cout << query(root[r - 1], prefix_xor[n] ^ x, l - 1) << '\n';
		}
	}
}
