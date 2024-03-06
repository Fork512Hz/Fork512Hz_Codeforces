#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 300100;
#endif
ll a[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		ll n, c;
		scanf("%lld%lld", &n ,&c);
		for(int i=0; i<n; i++) scanf("%lld", &a[i]);
		ll ans = (c+2)*(c+1) / 2;
		for(int i=0; i<n; i++) ans -= a[i]/2+1;
		for(int i=0; i<n; i++) ans -= (c+1-a[i]);
		ll o, e;
		o = 0;
		e = 0;
		for(int i=0; i<n; i++) if(a[i] % 2) o++;
		else e++;
		ans += o*(o+1) / 2;
		ans += e*(e+1) / 2;
		printf("%lld\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
