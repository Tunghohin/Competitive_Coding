#include <iostream>
#include <cstring>

using namespace std;

char a[1000];//原串
char dfs_p[1010];//dfs枚举子串
int n;

bool check(const char arr[], const char patt[], int n_p, int m_a)
{
	bool flag = true;
	int nxt[1010];
	memset(nxt, 0, sizeof(nxt));

	for (int i = 2, j = 0; i <= n_p; i++)
	{
		while (j && patt[i] != patt[j + 1]) j = nxt[j];
		if (patt[i] == patt[j + 1]) j++;
		nxt[i] = j;
	}

	for (int i = 1, j = 0; i <= m_a; i++)
	{
		while (j && arr[i] != patt[j + 1]) j = nxt[j];
		if (arr[i] == patt[j + 1]) j++;
		if (j == n_p)
		{
			flag = false;
			j = nxt[j];
		}
	}

	return flag;
}

bool flag = true;
void dfs(int s, int limit)
{
	if (!flag) return;
	if (s > limit)
	{
		if (check(a, dfs_p, limit, n))
		{
			for (int i = 1; i <= limit; i++) cout << dfs_p[i];
			cout << '\n';
			flag = false;
		}
		return;
	}

	for (int i = 0; i < 26; i++)
	{
		dfs_p[s] = (char)(i + 'a');
		dfs(s + 1, limit);
		if (!flag) return;//找到后直接return
	}
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		cin >> n;
		flag = true;

		for (int i = 1; i <= n; i++) cin >> a[i];

		for (int len = 1; len <= 1000; len++)
		{
			dfs(1, len);
			if (!flag) break;//找到后直接break
		}
	}

	return 0;
}
