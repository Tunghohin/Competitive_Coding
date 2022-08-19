#include <iostream>
#include <iomanip>

using namespace std;

double A[1010], B[1010];
double p[110];

void solve()
{
	int n, k1, k2, k3, a, b, c;
	cin >> n >> k1 >> k2 >> k3 >> a >> b >> c;

	p[0] = 1.0 / (k1 * k2 * k3);

	for (int i = 1; i <= k1; i++)
	{
		for (int j = 1; j <= k2; j++)
		{
			for (int k = 1; k <= k3; k++)
			{
				if (i != a || j != b || k != c)
				{
					p[i + j + k] += p[0];
				}
			}
		}
	}

	for (int i = n; i >= 0; i--)
	{
		for (int j = 3; j <= k1 + k2 + k3; j++)
		{
			A[i] += p[j] * A[i + j];
			B[i] += p[j] * B[i + j];
		}
		A[i] += p[0], B[i] += 1;
	} 

	cout << fixed << setprecision(8) << B[0] / (1.0 - A[0]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
 
	solve();
}