#include <stdio.h>

#define max(a,b) ((a) > (b) ? (a) : (b))

#define N 20

int getconseq(int x[],int y[],int m, int n)
{
    int a[N+1][N+1] = {0};

    int i;
    int j;

    for (i = 1; i <= m; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (x[i-1] == y[j-1]) a[i][j] = a[i-1][j-1] + 1;
            else
            {
                int tmp = max(a[i-1][j],a[i][j-1]);
                if (tmp > a[i][j]) a[i][j] = tmp;
            }
        }
    }
    return a[m][n];
}

int main()
{
   int x[] = {'A','B','C','B','D','A','B'};
   int y[] = {'B','D','C','A','B','A'};

   printf("%d\n",getconseq(x,y,7,6));
   return 0;
}
