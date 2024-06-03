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
char s[100][100];
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
		cin >> n;
		if(n == 1)
		{
			printf("1\n");
			continue;
		}
		for(int i=0; i<n; i++)
		{
			memset(s[i], '0', n);
			s[i][n] = '\0';
		}
		for(int i=0; i<n/2 ; i++)
		{
			s[i][0] = '1';
			s[i][1+i] = '6';
			s[i][2+2*i] = '9';
		}
		s[n/2][0] = '1';
		s[n/2][1] = '9';
		s[n/2][2] = '6';
		for(int i=0; i<n/2; i++)
		{
			s[i+n/2+1][0] = '9';
			s[i+n/2+1][1+i] = '6';
			s[i+n/2+1][2+2*i] = '1';
		}
		for(int i=0; i<n; i++)
		{
			printf("%s\n", s[i]);
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
