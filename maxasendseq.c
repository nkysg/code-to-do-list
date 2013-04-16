//最长递增子串
#include <stdio.h>

int max_asend_seq(int a[],int n)
{
    int B[14] = {1};
    int maxseq = 1;

    for (int i = 1; i < n; ++i)
    {
        B[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] <= a[i] && B[j] + 1 > B[i])
            {
                B[i] = B[j] + 1;
            }
        }
        if (B[i] > maxseq) maxseq = B[i];
    }

    return maxseq;
}

int main()
{
    //int A[N] = {};
    //int A[N] = {};
    int A[14] = {6,7,8,1,3,5,2,12,14,8,9,29,12,35};

    printf("%d\n",max_asend_seq(A,sizeof(A)/sizeof(A[0])));
}

