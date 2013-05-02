#include <cstdio>
#include <cstring>

#define N  1000 + 5

int d[N][N] = {0};

bool a[N][N] = {0};

bool checkstr(char* beg, char* end)
{
    for (; beg < end; beg++,end--)
       if (*beg != *end) return false;
    return true;
}

int main()
{
    char buf[N];
    int num;

#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d",&num);
    while (num--)
    {
        scanf("%s",buf);
        int n = strlen(buf);
        int i,j,del;


        for (i = 0; i < n; ++i)
            for (j = i; j < n; ++j)
            {
                d[i][j] = j - i + 1;
                a[i][j] = checkstr(buf+i,buf+j);
            }

        for (j = 1; j  < n; j++)
        {
            if (a[0][j]) d[0][j] = 1; 
            int t = 1000;
            for (i = 0; i < j; ++i)
                if (a[i+1][j]) 
                {
                    t = d[0][i] + 1;
                    if (t < d[0][j]) d[0][j] = t;
                }

        }

        printf("%d\n",d[0][n-1]);
    }
    return 0;
}
