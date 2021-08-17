#include <stdio.h>
int main()
{
    int i,j,n;
    i=1,j=1;
    scanf("%d",&n);
    while(n>j)
    {
        i++;
        j=j+i;
    }
    if(i%2==0)
    {
        printf("%d/%d",n-j+i,j-n+1);
    }
    else
    {
        printf("%d/%d",j+1-n,i+n-j);
    }
    return 0;
}
