#include <cstdio>

int main()
{
    int T;
    int i;

#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d",&T);
    for (i = 1; i <= T;++i)
    {
       int m,n,j,len;
       int a[10] = {0},b[10] = {0};
       scanf("%d %d",&m,&n);
       len = 0;
       for (j = 2; j <= m;j++)
       {
            int dim = 0;
            while (m % j == 0)
            {
                dim++;
                m /= j;
            }
            if (dim) { a[len] = j; b[len++] = dim; }
        }

        int maxk = 10000;
        for (j = 0; j < len; j++)
        {
            int dimsum = 0,temp = a[j];
            while (n > temp)
            {
                dimsum += n/temp;
                temp *= a[j];
            }
            if (dimsum/b[j] < maxk) maxk = dimsum/b[j];
        }
        if (maxk)
            printf("Case %d:\n%d\n",i,maxk);
        else 
            printf("Case %d:\nImpossible to divide\n",i);
    }
    return 0;
}
