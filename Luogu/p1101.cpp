#include <iostream>
using namespace std;
char mp[102][102];
bool vis[102][201];
int xx[8]={0,1,1,1,0,-1,-1,-1};
int yy[8]={1,1,0,-1,-1,-1,0,1};
char a[7]={'y','i','z','h','o','n','g'};
int n;
void f_ne(int x,int y,int d)
{

    int nx=x,ny=y;
    {
        for (int i=2;i<7;i++)
        {
            nx+=xx[d],ny+=yy[d];
            if (mp[nx][ny]!=a[i]) return;
            else continue;
        }
        vis[nx][ny]=true;
        for (int i=0;i<6;i++)
        {
            nx-=xx[d];
            ny-=yy[d];
            vis[nx][ny]=true;
        }
    }
}
void f_i(int x,int y)
{
    for (int i=0;i<8;i++)
    {
        int dx=x+xx[i];
        int dy=y+yy[i];
        if (dx>=0&&dx<n&&dy>=0&dy<n&&mp[dx][dy]=='i')
        {
            f_ne(dx,dy,i);
        }
    }
}
int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>mp[i][j];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (mp[i][j]=='y')
                f_i(i,j);
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (vis[i][j]) cout<<mp[i][j];
            else cout<<'*';
        }
        cout<<endl;
    }
    return 0;
}
