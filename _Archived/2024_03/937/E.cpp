#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<deque>
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
const long long N = 500100;
#endif
int n;
string s;
deque<int> factors;

bool check(int x)
{
	if(x == n) 
	{
		printf("%d\n", x);
		return true;
	}
	int cnt = 0;
	for(int i=0; i<x; i++)
	{
		char c1, c2;
		c1 = s[i];
		c2 = s[x+i];
		if(c1 != c2)
		{
			cnt ++;
			if(i+2*x >= n);
			else
			{
				char c3 = s[i+2*x];
				if(c3 != c1 && c3 != c2) return false;
				for(int j = i+3*x; j<n; j+=x)
					if(s[j] != c3) return false;
			}
		}
		else
		{
			int rcnt = 0;
			for(int j=i+2*x; j<n; j+=x)
			{
				if(s[j] != c1) rcnt++;
				if(rcnt >= 2)
					return false;
			}
			cnt += rcnt;
		}
		if(cnt >= 2) return false;
	}
	printf("%d\n", x);
	return true;
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
		factors.clear();
		scanf("%d", &n);
		cin >> s;
		int _sqrt = floor(sqrt(n) + 0.5);
		for(int i=1; i<=_sqrt; i++) if(n % i == 0)
		{
			factors.push_front(n/i);
			if(check(i)) goto fin;
		}
		for(int i: factors) if(check(i)) goto fin;
		
		fin:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
