#include <iostream>
#include <vector>

using namespace std;

const int N = 110;
const long long mod = 1e9 + 7;

long long matrix[110][110];
long long right_side[N];
long long solved[N];

long long q_pow(long long a, long long k)
{
	long long res = 1;
	while (k)
	{
		if (k & 1)
		{
			res = res * a % mod;
		}
		a = a * a % mod;
		k >>= 1;
	}
	return res;
}

void elimination(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (matrix[j][i])
			{
				for (int k = i; k <= n; k++)
				{
					swap(matrix[i][k], matrix[j][k]);
				}
				swap(right_side[i], right_side[j]);
				break;
			}
		}

		for (int j = i + 1; j <= n; j++)
		{
			if (matrix[j][i])
			{
				long long delta = matrix[j][i] * q_pow(matrix[i][i], mod - 2) % mod;
				for (int k = i; k <= n; k++)
				{
					matrix[j][k] -= matrix[i][k] * delta % mod;
					if (matrix[j][k] < 0) matrix[j][k] += mod;
				}
				right_side[j] -= right_side[i] * delta % mod;
				if (right_side[j] < 0) right_side[j] += mod;
			}
		}
	}

	for (int i = n; i >= 1; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			right_side[i] -= right_side[j] * matrix[i][j] % mod;
			if (right_side[i] < 0) right_side[i] += mod;
		}
		right_side[i] = right_side[i] * q_pow(matrix[i][i], mod - 2) % mod;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> son[N];

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		son[a].push_back(b);
	}

	for (int i = 1; i < n; i++)
	{
		matrix[i][i] = 1, right_side[i] = 1;
		int size = (int)son[i].size();
		for (auto to : son[i])
		{
			matrix[i][to] = mod - (1 * q_pow(size, mod - 2));
		}
	}
	matrix[n][n] = 1;

	elimination(n);

	cout << solved[1];
}