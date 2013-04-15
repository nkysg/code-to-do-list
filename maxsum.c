#include <stdio.h>

#define  N 100

int maxsum(int a[], int n)
{
        int B[N] = {0};
        B[0] = a[0];

        int maxsum = B[0] > 0 ? B[0] : 0;
        int i;
        for (i = 1; i < n; ++i)
        {
                B[i] = a[i];
                if (B[i-1] > 0) B[i] += B[i-1];
                if (B[i] > maxsum) maxsum = B[i];
        }
        return maxsum;
}
