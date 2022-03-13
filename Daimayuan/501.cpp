#include <iostream>

using namespace std;

int h[100010];
int dp_l[100010], dp_r[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> h[i];

	for (int i = 1; i <= n; i++)
	{
		if (h[i] > dp_l[i - 1]) dp_l[i] = dp_l[i - 1] + 1;
		else dp_l[i] = h[i];
	}

	for (int i = n; i >= 1; i--)
	{
		if (h[i] > dp_r[i + 1]) dp_r[i] = dp_r[i + 1] + 1;
		else dp_r[i] = h[i];
	}

	int max_res = -1;
	for (int i = 1; i <= n; i++)
	{
		max_res = max(max_res, min(dp_l[i], dp_r[i]));
	}

	cout << max_res;
}