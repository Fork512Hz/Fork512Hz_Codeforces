#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>

using ll = __int128_t;
#define DEBUG
#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = //TODO
#endif
const ll M = 1000000007;
using namespace std;
ll mod_inv(ll a, const ll& m);
ll exgcd(ll a, ll b, ll& x, ll& y);
ll mod_inv(ll a, const ll& m)
{
	ll x, y;
	exgcd(a, m, x, y);
	return (m + x % m) % m;
}
ll exgcd(ll a, ll b, ll& x, ll& y)
{
	ll d = a;
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
ll gcd(ll x, ll y)
{
	ll t;
	ll a=x, b=y;
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
void scan(__int128 &x)//输入
{
    x = 0;
    int f = 1;
    char ch;
    if((ch = getchar()) == '-') f = -f;
    else x = x*10 + ch-'0';
    while((ch = getchar()) >= '0' && ch <= '9')
        x = x*10 + ch-'0';
    x *= f;
}
void _print(__int128 x)
{
    if(x > 9) _print(x/10);
    putchar(x%10 + '0');
}
void print(__int128 x)//输出
{
    if(x < 0)
    {
        x = -x;
        putchar('-');
    }
    _print(x);
}
int main()
{
    #ifdef DEBUG
    //freopen("1.txt", "r", stdin);
    #endif
	int z;
    cin >> z;
    getchar();
    while(z--)
    {
    	ll n, m, k;
    	scan(n);
    	scan(m);
    	scan(k);
    	ll sumv=0;
    	for(int i=0; i<m; i++)
    	{
    		ll a, b, x;
    		scan(a);
    		scan(b);
    		scan(x);
    		sumv += x;
		}
		ll npair = n * (n-1) / 2;
		ll ansq = npair *npair;
		ll first = sumv*npair;
		ll last = (first + m * (k-1));
		ll ansp = (first+last)*k/2;
		ll g = gcd(ansp, ansq);
		ansp /= g;
		ansq /= g;
		
		print(ansp * mod_inv(ansq, M) % M);
		printf("\n");
	}
 	return 0;
}
