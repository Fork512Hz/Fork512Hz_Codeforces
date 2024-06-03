#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<set>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 200100;
#endif
set<ll> s;
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
		s = {0};
		int n;
		ll sum = 0;
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%lld", &a[i]);
		for(int i=0; i<n; i++)
		{
			sum += (i%2)? a[i]: -a[i];
			if(s.find(sum) != s.end()) 
			{
				printf("Yes\n");
				goto fin;
			}
			s.insert(sum);
		}
		printf("No\n");
		fin: ;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
