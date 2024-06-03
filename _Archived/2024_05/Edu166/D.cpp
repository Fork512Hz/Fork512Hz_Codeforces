#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
#include<deque>
#include<set>
#include<cassert>
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
ll bucket[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		string s;
		cin >> s;
		ll n = s.size();
		memset(bucket, 0, sizeof(ll) * (n/2) + 5);
		ll ans = 0;
		ll potential = 0;
		for(int i=0; i<n; i++)
		{
			if(s[i] == '(') potential++;
			else potential--;
			assert(potential >= 0);
			ans += bucket[potential];
			bucket[potential] ++;
			if(potential & 1ll) bucket[potential/2] = 0;
		}
		printf("%lld\n", ans);
    }
 	return 0;
}
