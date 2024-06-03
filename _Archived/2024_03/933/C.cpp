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
const long long N = 500100;
#endif

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n;
		scanf("%d", &n);
		string s;
		cin >> s;
		int st0 = 0, st1 = 0, ans = 0;
		bool flag = 0;
		for(int i=0; i<n; i++) switch(s[i])
		{
			case 'm': 
				st1 = 1;
				st0 = 0;
				flag = 0;
				break;
			case 'a':
				st1 = st1==1? 2: 0;
				st0 = 0;
				flag = 0;
				break;
			case 'i':
				st0 = st0==1? 2: 0;
				st1 = 0;
				break;
			case 'p':
				st0 = 1;
				if(st1 == 2)
				{
					ans++;
					flag = 1;
				}
				else flag = 0;
				st1 = 0;
				break;
			case 'e':
				if(st0 == 2)
				{
					if(!flag) ans++;
				}
				flag = 0;
				st0 = 0;
				st1 = 0;
				break;
			default:
				st0 = 0;
				st1 = 0;
				flag = 0;
		}
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
