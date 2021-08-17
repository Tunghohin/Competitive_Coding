#include <stdio.h>

char a[100000];
int i;
void elv(char x[])
{
    int b=0,c=0;
    for (int j=0;x[j]!='E';j++)
    {
        if (x[j]=='W')
        {
            b++;
        }
        else if (x[j]=='L')
        {
            c++;
        }
        if ((b>=11||c>=11)&&((b-c)>1||(b-c)<-1))
        {
            printf("%d:%d\n",b,c);
            b=0,c=0;
        }
    }
    printf("%d:%d\n",b,c);
}
void twe(char x[])
{
    int b=0,c=0;
    for (int j=0;x[j]!='E';j++)
    {
        if (x[j]=='W')
        {
            b++;
        }
        else if (x[j]=='L')
        {
            c++;
        }
        if ((b>=21||c>=21)&&((b-c)>1||(b-c)<-1))
        {
            printf("%d:%d\n",b,c);
            b=0,c=0;
        }
    }
    printf("%d:%d\n",b,c);
}
int main()
{
    while (1==1)
    {
        char x;
        scanf("%c",&x);
        a[i]=x;
        i++;
        if (x=='E')
            break;
    }
    elv(a);
    printf("\n");
    twe(a);
    return 0;
}
