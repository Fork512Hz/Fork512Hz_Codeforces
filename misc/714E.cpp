#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
typedef long long i64;
//#define DEBUG

//#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 100100;
#endif
ll M = 1000000007;
// Modular inverse and combinatorics preprocessing
i64 mod_inv(i64 a, const i64& m);
i64 exgcd(i64 a, i64 b, i64& x, i64& y);
i64 mod_inv(i64 a, const i64& m)
{
	i64 x, y;
	exgcd(a, m, x, y);
	return (m + x % m) % m;
}
i64 exgcd(i64 a, i64 b, i64& x, i64& y)
{
	i64 d = a;
	if (b)
	{
		d = exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else
	{
		x = 1;
		y = 0;
	}
	return d;
}
i64 gcd(i64 x, i64 y)
{
	i64 t;
	i64 a=x, b=y;
	if(a>y)
	{
		t=a; a=b; b=t;
	}
	while(a)
	{
		t=b%a;
		b=a; a=t;
	}
	return b;
}
ll jc[N], inv[N];
ll C(ll n, ll m)
{
	if(n < 0 || m < 0 || m > n) return 0;
	return (jc[n] * inv[m] % M )* inv[n-m] % M;
}
void prepCombinatorics(ll n)
{
	jc[0] = 1;
	for(int i=1; i<=n; i++)
		jc[i] = jc[i-1] * i % M;
	for(int i=0; i<=n; i++)
		inv[i] = mod_inv(jc[i], M);
}
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

    }
    #endif
	#ifndef MULTI
	int n;
	scanf("%d", &n);
	ll sum = 0;
	for(int i=0; i<n; i++)
	{
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	if(sum % n)
	{
		printf("0");
		return 0;	
	}	
	sort(a, a+n);
	ll avg = sum / n;
	ll up = 0, down = 0, eq = 0;
	vector<ll> group;
	ll pv = 0;
	for(ll i=0; i<n; i++) 
	{
		if(a[i] > avg) up++;
		else if(a[i] <avg) down++;
		else eq++;
		if(a[pv] != a[i]) 
		{
			if(a[pv] != avg)group.push_back(i - pv);
			pv = i;
		}
	}
	if(a[pv] != avg) group.push_back(n - pv);
	prepCombinatorics(n);
	ll ans = jc[up] * jc[down] % M;
	for(ll i: group)
		ans = ans * inv[i] % M;
	if(up == 1 || down == 1)
		ans = ans * (up + down) % M;	
	else if(up == 0 || down == 0)
		;
	else 
		ans = ans * 2ll % M;
	ans = ans * C(n, eq) % M;
	printf("%lld\n", ans);
	#endif
 	return 0;
}
