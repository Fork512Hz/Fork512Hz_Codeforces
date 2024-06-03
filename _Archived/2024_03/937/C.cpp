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
		string s;
		cin >> s;
		int x = ((s[0] - 48) * 10 + s[1] - 48);
		if(x >= 12)
		{
			if(x-12 < 10 && x != 12) printf("0");
			printf("%d", x == 12? 12: x-12);
			for(int i=2; i<=4; i++) printf("%c", s[i]);
			printf(" PM\n");
		}
		else 
		{
			if(x != 0)cout << s;
			else{
				printf("12");
				for(int i=2; i<=4; i++) printf("%c", s[i]);
			}
			printf(" AM\n");
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
