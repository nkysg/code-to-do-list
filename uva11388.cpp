#include <cstdio>

int main()
{
    int T;

#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if (b % a)  printf("-1\n");
        else printf("%d %d\n",a,b);
    }
    return 0;
}
