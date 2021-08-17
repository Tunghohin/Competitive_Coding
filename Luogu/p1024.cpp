#include <iostream>
#include <cstdio>
using namespace std;
double a,b,c,d,sum;
double fun(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    double l,r,x1,x2,mid;
    for (int i=-100;i<100;i++)
    {
        l=i,r=i+1,x1=fun(l),x2=fun(r);
        if (!x1)
        {
            sum++;
            printf("%.2lf ",l);
        }
        if (x1*x2<0)
        {
            while(r-l>=0.001)
            {
                mid=(l+r)/2;
                if(fun(mid)*fun(r)<=0) l=mid;
                else r=mid;
            }
            printf("%.2lf ",r);
            sum++;
        }
        if (sum==3) break;
    }
    return 0;
}
