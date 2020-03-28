#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    int t, i;
    double n, tax;
    scanf ("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf ("%lf", &n);
        if (n <= 180000) printf ("Case %d: 0\n", i + 1);
        else
        {
            tax = 0.0;
            n = n - 180000.0;
            if (n > 0)
            {
                if (n <= 300000.0)
                {
                    tax += (n * 10.0) / 100.0;
                    n = 0;
                }
                else
                {
                    n = n - 300000.0;
                    tax += (300000.0 * 10.0) / 100.0;
                }
            }
            if (n > 0)
            {
                if (n <= 400000.0)
                {
                    tax += (n * 15.0) / 100.0;
                    n = 0;
                }
                else
                {
                    n = n - 400000.0;
                    tax += (400000.0 * 15.0) / 100.0;
                }
            }
            if (n > 0)
            {
                if (n <= 300000.0)
                {
                    tax += (n * 20.0) / 100.0;
                    n = 0;
                }
                else
                {
                    n = n - 300000.0;
                    tax += (300000.0 * 20.0) / 100.0;
                }
            }
            if (n > 0)
            {
                tax += (n * 25) / 100;
                n = 0;
            }
            if (tax < 2000) tax = 2000.0;
            tax = ceil(tax);
            printf ("Case %d: %.0lf\n", i + 1, tax);
        }
    }
    return 0;
}
