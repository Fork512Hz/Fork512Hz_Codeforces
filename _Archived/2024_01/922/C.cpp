#include<cstdio>
#include<algorithm>
#include<iostream>
#include<deque>
#include<cmath>

#include<cstring>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 100000;//TODO
#endif
bool a[64], b[64];
deque<int> todo;
ll grandans = 0x7fffffffffffffff;
int len;
void check(ll x)
{
	ll t=x;
	if(t<0) t*=-1;
	if(t<grandans) grandans = t;
}
void solve(ll depth, ll ans, ll range, ll type)
{
	//type = 0: init 1: follow a -1: follow b
	//side = 1: a=1,b=0 side = -1: a=0, b=1
	
	if(depth == len)
	{
		check(ans);
		return;
	}
	ll side = todo[depth]>0? 1: -1;
	ll pos = todo[depth] * side - 1;
	if(range >= 1ll << (pos+1))
	{
		if(type == 0)
		{
			ll an_ = 1ll << pos;
			for(int d=depth+1; d<len; d++) an_ += -1ll << (abs(todo[d])-1);
			check(an_);
			return;
		}
		ll an_ = ans;
		for(int d=depth; d<len; d++) an_ += -type << (abs(todo[d])-1);
		check(an_);
	}
	else if(range <= 1ll << pos)
	{
		solve(depth+1, ans+(side<<pos), range, type==0? side: type);
	}
	else
	{
		solve(depth+1, ans+(side<<pos), 1ll << pos, type==0? side: type);
		solve(depth+1, ans-(side<<pos), range - (1ll << pos), type==0? -side: type);
	}
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
    	todo.clear();
    	memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		grandans = 0x7fffffffffffffff;
		len = 0;
		ll x, y, r;
		scanf("%lld%lld%lld", &x, &y, &r);
		for(int i=0; i<=62; i++) 
		{
			a[i] = (x & (1ll<<i)) > 0;
			b[i] = (y & (1ll<<i) )> 0;
		}
		for(int i=0; i<=62; i++)
		{
			if(a[i] && !b[i]) todo.push_front(i+1);
			if(b[i] && !a[i]) todo.push_front(-i-1);
		}
		len = todo.size();
		solve(0, 0, r+1, 0);
		printf("%lld\n", grandans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
