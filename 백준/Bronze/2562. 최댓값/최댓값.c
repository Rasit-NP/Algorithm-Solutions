#include <stdio.h>

int maximum = 0;
int idx;

int main()
{
    for (int i=1; i<10; i++)
    {
        int n;
        scanf("%d", &n);
        if (n > maximum)
        {
            maximum = n;
            idx = i;
        }
    }
    printf("%d\n%d", maximum, idx);
    return 0;
}