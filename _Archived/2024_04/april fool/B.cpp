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
//define DEBUG

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
		int n = s.size();
		int state = 0;
		for(int i=0; i<n; i++)
		{
			if(s[i] == 'i') state = 1;
			else if(s[i] == 't')
			{
				if(state == 1)
				{
					printf("YES\n");
					break;
				}
				else state = 0;
			}
			else state = 0;
		}
		printf("NO\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
