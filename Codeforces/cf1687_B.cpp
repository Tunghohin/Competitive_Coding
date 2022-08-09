#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using PII = pair<int, int>;

int ask(const string &x)
{
	cout << "? " << x << endl;
	int res;
	cin >> res;
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	string s(m, '0');
	vector<int> sum(m + 1);
	vector<PII> edges;

	for (int i = 0; i < m; i++)
	{
		s[i] = '1';
		edges.push_back({ask(s), i});
		s[i] = '0';
	}

	sort(edges.begin(), edges.end());

	for (int i = 0; i < m; i++)
	{
		s[edges[i].second] = '1';
		sum[i + 1] = ask(s);
	}

	int r = 0;
	for (int i = 0; i < m; i++)
	{
		if (sum[i + 1] == sum[i] + edges[i].first) r += edges[i].first;
	}

	cout << "! " << r << endl;
}