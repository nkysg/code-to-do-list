#include <cstdio>
#include <algorithm>

using namespace std;

struct cmp
{
    bool operator() (int a, int b)
    {
        return abs(a) < abs(b);
    }
};

int a[500000+5];
int main()
{
    int T;

#ifndef ONLINE_JUDGE
    freopen("1.txt","r",stdin);
#endif
    scanf("%d",&T);
    while (T--)
    {
        int n,i;
        scanf("%d",&n);
        for (i = 0; i < n; ++i)
            scanf("%d",a+i);

        sort(a,a+n,cmp());

        int flag = a[0] > 0 ? 1: -1;
        int num = 1;

        for (i = 1; i < n; ++i)
        {
            if (flag * a[i] < 0) { flag = -1 * flag; num++; }
        }
        printf("%d\n",num);
    }
    return 0;
}
