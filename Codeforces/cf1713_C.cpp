#include <iostream>

using namespace std;

const int N = 100010;

int n, p[N];
void solve()
{
    cin >> n;

    for (int i = 0; i <= n; i++) p[i] = -1;

    int cur_num = 0;
    while (cur_num * cur_num < 2 * n - 2) cur_num++;
    cur_num++;

    for (int i = n - 1; i >= 0; i--)
    {
    	for (int j = cur_num; j >= 0; j--)
    	{
    		int x = j * j - i;
    		if ((x < n) && (x >= 0) && p[x] == -1)
    		{
    			p[x] = i;
    			break;
    		}
    	}
    }

    for (int i = 0; i < n; i++) cout << p[i] << ' ';
    cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		solve();
	}
}