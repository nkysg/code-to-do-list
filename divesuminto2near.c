/*
Partition a set of numbers into two such that difference between their sum is minimum, 
and both sets have equal number or one more of elements.
For example: {1, 4, 9, 16} is partitioned as {1,16} and {4,9} with diff =17-13=4.
*/
#include <cstdio>
#include <cstdlib>

void getsumdiv(int a[],int n, int index,int arrsum, int sum, int flaga[],int saveindex[],int& getsum)
{
    if (index == n)
    {
        if (abs(2 * sum - arrsum) < abs(2 * getsum - arrsum))
        {
            getsum = sum;
            for (int i = 0,j = 0; i < 2 * n; ++i)
            {
                if (flaga[i]) saveindex[j++] = i;
            }
        }
        return;
    }

    for (int i = 0; i < 2 * n; ++i)
    {
        if (flaga[i]) continue;
        else
        {
            flaga[i] = 1;
            getsumdiv(a,n,index+1,arrsum,sum+a[i],flaga,saveindex,getsum);
            flaga[i] = 0;
        }
    }
}
#define ARRSIZE(a) (sizeof(a)/sizeof(a[0]))
int main()
{
    int a[] = {1,4,9,16,5,6,3};
    int arrsum = 0;
    for (int i =  0; i < ARRSIZE(a); i++)
    {
        arrsum += a[i];
    }

    int flaga[ARRSIZE(a)] = {0};
    int saveindex[ARRSIZE(a)] = {0};

    int getsum = 0;
    getsumdiv(a,ARRSIZE(a)/2,0,arrsum,0,flaga,saveindex,getsum);

    printf("%d\n",getsum);
    for (int i = 0; i < ARRSIZE(a)/2; ++i)
    {
        printf("%d ",a[saveindex[i]]);    
    }
    printf("\n");
    return 0;
}
