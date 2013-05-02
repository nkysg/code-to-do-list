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
        int m,n,i,j;
        char buf[1024];
        int cnt[1024][4] = {0};
    
        scanf("%d %d",&m,&n);
        for (i = 0; i < m; ++i)
        {
            scanf("%s",buf);
            for (j = 0; j < n; j++)
                switch (buf[j])
                {
                    case 'A':
                        cnt[j][0]++;
                        break;

                    case 'C':
                        cnt[j][1]++;
                        break;
                    
                    case 'G':
                        cnt[j][2]++;
                        break;

                    case 'T':
                        cnt[j][3]++;
                        break;
                }
        }

        char DNA[] = "ACGT";
        int dnadist = 0;
        for (j = 0; j < n;j++)
        {
            int index = 0, max = cnt[j][0],dist = 0;
            for (i = 0; i < 4; i++)
            {
                dist += cnt[j][i];
                if (max < cnt[j][i]) { max = cnt[j][i]; index = i; }
            }
            putchar(DNA[index]);
            dnadist += dist - max;
        }
        putchar('\n');
        printf("%d\n",dnadist);
    }
    return 0;
}
