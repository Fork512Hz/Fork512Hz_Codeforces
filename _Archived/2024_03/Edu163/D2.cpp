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
inline bool match(char x, char y)
{
	return x==y || x=='?' || y=='?';
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
		string s;
		cin >> s;
		int n = s.size();
		for(int i=n/2; i>=1; i--)
		{
			int state = 0;
			for(int j=0; j+i <n; j++)
			{
				if(match(s[j], s[i+j])) state++;
				else state = 0;
				if(state == i)
				{
					printf("%d\n", 2*i);
					goto fin;
				}
			}
		}
		printf("0\n");
		fin:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
