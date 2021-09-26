#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

double G[220][220];

double get_dist(pair<int, int> a, pair<int, int> b)
{
	double dx = a.first - b.first;
	double dy = a.second - b.second;

	return dx * dx + dy * dy;
}

void solve(int n, int kase)
{
	memset(G, 0x3f, sizeof(G));

	vector<pair<double, double> > d;

	for (int i = 1; i <= n; i++)
	{
		double x, y;
		cin >> x >> y;
		d.push_back({x, y});
	}

	for (int i = 0; i < d.size() - 1; i++)
	{
		for (int j = i + 1; j < d.size(); j++)
		{
			G[j + 1][i + 1] = G[i + 1][j + 1] = get_dist(d[i], d[j]);
		}
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
			}
		}
	}

	cout << "Scenario #" << kase << '\n';
	cout << "Frog Distance = " << fixed << setprecision(3) << sqrt(G[1][2]) << "\n\n";
}

int main()
{
	int n;
	int kase = 0;
	while (cin >> n && n)
	{
		kase++;
		solve(n, kase);
	}

	return 0;
}