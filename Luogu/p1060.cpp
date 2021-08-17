#include <iostream>

using namespace std;

int f[30][100000];
int w[10000];
int v[10000];

int main()
{
    int n,m;
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>w[i]>>v[i];
        v[i]*=w[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int c=0;c<=m;c++)
        {
            f[i][c]=f[i-1][c];
            if(c>=w[i])
                f[i][c]=max(f[i][c],f[i-1][c-w[i]]+v[i]);
        }
    }
    cout<<f[n][m];
    return 0;
}
