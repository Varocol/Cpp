#include <stdio.h>
int main()
{
    long long x;
    long long left = 1, right = 1e8, mid, k;
    int n;
    scanf("%d",&n);while(n--)
    { 
        left = 1, right = 1e8;
        scanf("%ld", &x);
    //二分法查找k,使其满足k(k+1)/2刚好大于或等于x
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (mid * (mid + 1) / 2 < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    k = left;
    if (left * (left + 1) / 2 == x + 1)
    {
        k++;
    }
    printf("%ld\n", k);
    }
}