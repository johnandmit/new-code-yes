#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void placment(int n, int i, int nox[n * n], int x[n], int y)
{
    if (i < n && x[i] <= n)
    {
        int nx = 1, ny = y + 1, yes = 0;
        while (yes == 0)
        {
            int j = 0;
            yes = 1;
            while (j <= i)
            {
                for (int count = 0; count < n * n; count++)
                {
                    if (nx == nox[count])
                    {
                        
                    }
                        
                }
                if (abs(nx - x[j]) == abs(ny - y))
                {
                    yes = 0;
                    break;
                }
                j++;
            }
            if (yes == 0)
            {
                nx++;
            }
        }
        printf("#%i queen position = %i,%i\n", i + 1, nx, ny);
        i++;
        x[i] = nx;
        placment(n, i, nox, x, ny);
    }
    if (x[i] > n)
    {
        nox
        placment(n, i, nox, x, ny);
    }
}

int main()
{
    int n;
    printf("enter n: ");
    scanf("%i", &n);
    int x[n], nox[n * n];
    x[0] = 1;
    nox[0] = 0;
    placment(n, 0, , x, 0);
}
