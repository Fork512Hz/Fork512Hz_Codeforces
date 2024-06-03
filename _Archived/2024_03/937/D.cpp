#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
#include<set>
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
int a[16] = {
	10, 11, 101, 111, 1001, 1011, 1101, 1111,
	10001, 10011, 10101, 10111, 11001, 11011, 11101, 11111
};
set<int> s = {1};
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    for(int i=0; i<16; i++)
    {
    	for(int j: s) 
    	{
    		int t = j;
    		for(;;)
    		{
    			t *= a[i];
    			if(t > 100000) break;
    			s.insert(t);
			}
		}
	}
    while(z--){
		int n;
		scanf("%d", &n);
		if(s.find(n) != s.end())
			printf("YES\n");
		else printf("NO\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
