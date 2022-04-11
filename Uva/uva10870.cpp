#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstring>
#include <iomanip>
#include <algorithm>
#define PI 3.1415926535898
#define inf64 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define precision 8
#define eps 1e-precision
#define debug(x) cout << (x) << ' '
#define fix(x) fixed << setprecision((precision - 2)) << x

using namespace std;

const int MOD = 1e9 + 7;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template<typename T>
void init(T q[], int n, T val)
{
	for (int i = 0; i <= n; i++) q[i] = val;
}

LL a[20], f[20];
int d, n, m;

struct matrix
{
	LL mat[20][20];

	void clear()
	{
		memset(mat, 0, sizeof(mat));
	}

	void init()
	{
		clear();
		for (int i = 0; i <= d; i++) mat[i][i] = 1;
	}

	friend matrix operator * (matrix a, matrix b)
	{
		matrix res;

		for (int i = 0; i <= d; i++)
		{
			for (int j = 0; j <= d; j++)
			{
				res.mat[j][i] = 0;
				for (int k = 0; k <= d; k++)
				{
					LL val = a.mat[j][k] * b.mat[k][i] % m;
					res.mat[j][i] = res.mat[j][i] + val % m;
				}
			}
		}

		return res;
	}

	friend matrix operator ^ (matrix base, LL k)
	{
		matrix res;
		res.init();

		while (k)
		{
			if (k & 1) res = res * base;
			base = base * base;
			k >>= 1;
		}

		return res;
	}

	void show()
	{
		for (int i = 0; i <= d; i++)
		{
			for (int j = 0; j <= d; j++)
			{
				cout << mat[i][j] << ' ';
			}
			cout << '\n';
		}
	}
};

void solve()
{
	matrix F;
	matrix A;
	F.clear();
	A.clear();

	for (int i = 1; i <= d; i++) cin >> a[i];
	for (int i = 1; i <= d; i++) cin >> f[i];

	for (int i = 0; i <= d; i++)
	{
		F.mat[i][0] = f[i];
	}

	for (int i = 1; i <= d; i++)
	{
		A.mat[i - 1][i] = 1;
		A.mat[d][i] = a[d - i + 1];
	}


	A = A ^ (n - d);

	matrix res;
	res = A * F;

	cout << res.mat[d][0] % m << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	while (cin >> d >> n >> m && (d || n || m))
	{
		solve();
	}

	return 0;
}