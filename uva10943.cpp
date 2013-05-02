#include <cstdio>

int a[105][105] ;
bool vis[105][105] ;

int dp(int k,int n)
{
        if (vis[k][n]) return a[k][n];
        int t = 0;
        for (int i = 0; i <= n; i++)
                t += dp(k-1,i);
        a[k][n] = t % 1000000 ;
        vis[k][n] = 1;
        return a[k][n];
}

int main()
{
        for (int i = 0; i <= 100; ++i)
        {
                vis[1][i] = 1;
                a[1][i] = 1;
        }
        for (int i = 0; i <= 100; ++i)
        {
                vis[i][0] = 1;
                a[i][0] = 1;
        }

        int k,n;
        while (scanf("%d %d",&n,&k) == 2 && n && k)
        {
                printf("%d\n",dp(k,n));
        }
        return 0;
}
