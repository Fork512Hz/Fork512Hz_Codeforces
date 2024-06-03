#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
#include<queue>
#include<set>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vll;
typedef long long ll;
typedef long long i64;

//#define DEBUG

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 200100;
#endif
// const ll M = 998244353;
ll a[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		ll n, x;
		scanf("%lld%lld", &n, &x);
		for(int i=0; i<n; i++)
			scanf("%lld", &a[i]);
		ll balance = 0;
		ll cnt = 0;
		priority_queue<ll> hp;
		for(int i=0; i<n; i++)
		{
			
			if(balance >= a[i])
			{
				cnt++;
				balance -= a[i];
				hp.push(a[i]);
			}
			else if(!hp.empty())
			{
				ll t = hp.top();
				if(a[i] < t)
				{
					balance += t - a[i];
					hp.pop();
					hp.push(a[i]);
				}
			}
			balance += x;
		}
		printf("%lld\n", cnt);
    }
 	return 0;
}
