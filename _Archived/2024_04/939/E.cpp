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

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 200100;
#endif
int b[N], a[N];
bool check(ll x, ll y, ll z, bool fm2)
{
	if(z == 0) return false;
	if(!fm2) y = y-x;
	ll mo = y % x;
	ll xs = (y - mo) / x + 1;
	return (z > (y + mo) * xs / 2);
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    //bool flag = z!=10000;
    bool flag = 1;
    int num = 0;
    while(z--){
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++)
		{
			scanf("%d", &b[i]);
			a[i] = b[i];
		}
		for(;;)
		{
			for(int i=1; i<n; i++)
				a[i] = max(0, a[i] - a[i-1]);
			a[0] = max(0, a[0] - a[n-1]);
			int k = 0, kmax = 0;
			for(int i=0; i<n; i++) if(a[i] == 0)
			{
				kmax = max(kmax, k);
				k = 0;
			}
			else k++;
			for(int i=0; i<n; i++) if(a[i] == 0)
			{
				
				break;
			}
			else k++;
			kmax = max(kmax, k);
			if(kmax <= 3) break; 
		}
		vector<int> todo, ans;
		for(int i=0; i<n; i++)
			if(a[i] != 0 && a[(i+n-1) %n] == 0)
				todo.push_back(i);
		for(int i: todo)
			if(check(a[i], a[(i+1) % n], a[(i+2) % n], i == n-1))
			{
				ans.push_back(i+1);
				ans.push_back((i+2) % n + 1);
			}
			else ans.push_back(i+1);
		sort(ans.begin(), ans.end());
		auto last = unique(ans.begin(), ans.end());
		ans.erase(last, ans.end());
		if(flag)
		{
			printf("%d\n", ans.size());
			for(int i: ans) printf("%d ", i);
			printf("\n");
		}
		else
		{
			num += ans.size() + 1;
			if(num >= 1157)
			{
				printf("%d\n", n);
				for(int i=0; i<n; i++)
					printf("%d ", b[i]);
				return  -1000;
			}
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
