#include <iostream>

using namespace std;

int a[510], b[510];
int LCIS[510][510];
int Path[510][510];

void Output(int n, int s)
{
    if (Path[n][s] == 0)
    {
        cout << b[s] << ' ';
        return;
    }
    Output(n-1, Path[n][s]);
    if (Path[n][s] != s) cout << b[s]<<' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) cin >> b[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            LCIS[i][j] = LCIS[i-1][j];
            Path[i][j] = j;
            if (a[i] == b[j])
            {
                LCIS[i][j] = 1;
                Path[i][j] = 0;
                for (int k = 1; k < j; k++)
                {
                    if (b[k] < b[j] && LCIS[i-1][k] + 1 > LCIS[i][j])
                    {
                        LCIS[i][j] = LCIS[i-1][k] + 1;
                        Path[i][j] = k;
                    }
                }
            }
        }
    }

    int last = 0;
    for (int i = 1; i <= m; i++)
    {
         if (LCIS[n][last] < LCIS[n][i]) last = i;
    }

    cout << LCIS[n][last] << '\n';

    if (LCIS[n][last] != 0)
    {
        Output(n, last);
    }

    return 0;
}