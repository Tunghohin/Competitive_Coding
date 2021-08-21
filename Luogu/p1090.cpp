#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    priority_queue<int, vector<int>, greater<int>> q;

    int n,sumsum=0;
    cin>>n;

    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }

    while (q.size()>1)
    {
        int l=q.top();
        q.pop();
        int r=q.top();
        q.pop();
        int sum=l+r;
        q.push(sum);
        sumsum+=sum;
    }

    cout<<sumsum;

    return 0;
}
