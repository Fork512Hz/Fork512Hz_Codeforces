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
//#define DEBUG

//#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 1000100;
#endif
const ll M = 998244353;
const ll HALF = 499122177; // = 1/2
ll pfsa[N], pfsb[N], C[N];
ll suma, sumb, powhalf;
ll ksm(ll x, ll e)
{
	if(e == 0) return 1ll;
	if(e == 1) return x;
	ll tmp = ksm(x, e>>1);
	tmp = tmp*tmp % M;
	if(e & 1ll) tmp = tmp*x % M;
	return tmp;
}
inline ll inv(ll x)
{
	return ksm(x, M-2);
}
ll solve(ll a1, ll a2,  ll b2)
{
	//Calculate P(a1 + b1X > a2 + b2X), 
	//where kX = sum of k iid values of silver coin
	//= P(a1 + b1X > a2 + b2 - b2X)
	//= P((b1+b2)X > a2 + b2 - a1)
	//LHS ~ B(sumb, 1/2)
	ll t = a2+b2-a1;
	if(t < 0) return 1ll;
	if(t >= sumb) return 0ll;
	return powhalf * C[t+1] % M;
}
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
	pfsa[0] = 0;
	pfsb[0] = 0;
	int n, q;
	scanf("%d%d", &n, &q);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld", &pfsa[i]);
		pfsa[i] += pfsa[i-1];
	}
	for(int i=1; i<=n; i++)
	{
		scanf("%lld", &pfsb[i]);
		pfsb[i] += pfsb[i-1];
	}
	suma = pfsa[n];
	sumb = pfsb[n];
	//2 ^ -(sumb)
	powhalf = ksm(HALF, sumb);
	//C(sumb, i)
	C[0] = 1;
	for(ll i=1; i <= sumb/2; i++)
	{
		ll t = C[i-1] *(sumb + 1 - i) % M;
		t = t * inv(i) % M;
		C[i] = t;
	}
	for(int i=sumb; i>sumb/2; i--)
		C[i] = C[sumb - i];
	//Suffix sum
	C[sumb+1] = 0;
	for(int i=sumb; i>=0; i--)
		C[i] = C[i] + C[i+1] % M;
	for(int i=0; i<q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld ", solve(pfsa[r] - pfsa[l-1], suma - pfsa[r] + pfsa[l-1],
							  sumb - pfsb[r] + pfsb[l-1]));
	}
	#endif
 	return 0;
}
