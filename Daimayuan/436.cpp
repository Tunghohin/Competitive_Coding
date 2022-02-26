#include <iostream>
#include <stack>

using namespace std;

int a[500010];
int L_max[500010], R_max[500010];
int L_min[500010], R_min[500010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];

	stack<int> s_max;
	stack<int> s_min;
	for (int i = 1; i <= n; i++)
	{
		while (!s_max.empty() && a[s_max.top()] <= a[i]) s_max.pop();
		if (!s_max.empty())
		{
			L_max[i] = i - s_max.top() - 1;
		}
		else L_max[i] = i - 1;
		s_max.push(i);

		while (!s_min.empty() && a[s_min.top()] > a[i]) s_min.pop();
		if (!s_min.empty())
		{
			L_min[i] = i - s_min.top() - 1;
		}
		else L_min[i] = i - 1;
		s_min.push(i);
	}

	while (!s_max.empty()) s_max.pop();
	while (!s_min.empty()) s_min.pop();

	for (int i = n; i >= 1; i--)
	{
		while (!s_max.empty() && a[s_max.top()] < a[i]) s_max.pop();
		if (!s_max.empty())
		{
			R_max[i] = s_max.top() - i - 1;
		}
		else R_max[i] = n - i;
		s_max.push(i);

		while (!s_min.empty() && a[s_min.top()] >= a[i]) s_min.pop();
		if (!s_min.empty())
		{
			R_min[i] = s_min.top() - i - 1;
		}
		else R_min[i] = n - i;
		s_min.push(i);
	}


	long long maxn = 0, minn = 0;
	for (int i = 1; i <= n; i++)
	{
		maxn += a[i] * (L_max[i] + R_max[i] + (long long)L_max[i] * R_max[i] + 1);
		minn += a[i] * (L_min[i] + R_min[i] + (long long)L_min[i] * R_min[i] + 1);
	}

	cout << maxn - minn << '\n';
}