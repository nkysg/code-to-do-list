#include <cstdio>

int gcd(int m,int n)
{
    while (n)
    {
        int t = m % n;
        m = n;
        n = t;
    }
    return m;
}

int main()
{
    int T;

#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d",&T);
    while (T--)
    {
        int a,c;
        scanf("%d %d",&a,&c);
        if (c % a) printf("NO SOLUTION\n");
        else
        {
            int b = c/a,i;
            for (i = 1; i  <= a; ++i)
            {
                if (a % i == 0 && gcd(a / i,b) == 1)
                {
                    printf("%d\n",i*b);
                    break;
                }
            }
        }
    }
    return 0;
}
