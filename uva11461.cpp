#include <cstdio>
#include <cmath>

int main()
{
    int a,b;

#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    while (scanf("%d %d",&a,&b) != EOF && a && b)
    {
        int a1 = sqrt(a);
        int b1 = sqrt(b);

        if (a1 * a1 < a) a1++;

        printf("%d\n",b1-a1+1);
    }
    return 0;
}
