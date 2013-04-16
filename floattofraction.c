#include <stdio.h>

typedef struct __frac {
        int numerator;
        int denominator;
}frac;

int gcd(int m, int n)
{
        while (m)
        {
                int t = m;
                m = n % m;
                n = t;
        }
        return n;
}

frac getfloat(float x)
{
        int denominator = 1;
        while (1)
        {
                if (ceilf(x * denominator) == (int)(x * denominator))
                        break;
                denominator *= 10;
        }

        int numerator = (int)(x * denominator);
        int fracgcd = gcd(numerator,denominator);
        frac myfrac;
        myfrac.numerator = numerator/fracgcd;
        myfrac.denominator = denominator/fracgcd;

        return myfrac;
}

int main()
{
        float x = 1.3;
        frac myfrac = getfloat(x);
        printf("%d/%d\n",myfrac.numerator,myfrac.denominator);
        return 0;
}

