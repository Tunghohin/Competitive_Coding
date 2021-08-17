#include <stdio.h>
int main(void)
{
    int len,sum,b,c,num;
    num=0;
    scanf("%d",&len);/*总路长为len*/
    int a[len];
    for(int i=0;i<=len;i++)
    {
        a[i]=0;
    }/*初始化数组全为0*/
    scanf("%d",&sum);/*移走了sum组*/
    for(int j=0;j<sum;j++)
    {
        scanf("%d %d",&b,&c);
        for(int k=b;k<=c;k++)
        {
            a[k]=1;
        }
    }/*输入且将已移走的树位置设为1*/
    for(int l=0;l<=len;l++)
    {
        if(a[l]==0)
            num++;
    }
    printf("%d",num);
    return 0;
}
