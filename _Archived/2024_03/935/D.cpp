#include<bits/stdc++.h>
using namespace std;
#define DEBUG
const long long N = 200100;
int a[N], b[N];
int main()
{
    int z;
    scanf("%d", &z);
    while(z--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        for(int i=0; i<n; i++) 
            scanf("%d", &b[i]);
        long long ans = 0;
        for(int i=k; i<n; i++)
            ans += (long long)min(a[i], b[i]);
        long long sum = 0;
        long long t = 0x3f3f3f3f3f3f3f3f;
        for(int i=k-1; i>=0; i--)
        {
            t = min(t, sum + (long long)a[i]);
            sum += (long long) b[i];
        }
        printf("%lld\n", t + ans);
    }
    return 0;
}