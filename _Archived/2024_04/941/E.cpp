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
		if(n == 1) 
		{
			printf("1\n");
			continue;
		}
		vector<int> fold = {0};
		for(int i=1; i<n; i++)
			if(s[i] == s[i-1])
				fold.push_back(i);
		fold.push_back(n);
		int m = fold.size();
		for(int i=m-1; i>=1; i--)
			fold[i] -= fold[i-1];
		int left = 0, right = 0, k = 0, dir = 1;
		for(int i=1; i<m; i++)
		{
			k += dir * fold[i];
			if(dir > 0) right = max(right, k);
			else left = min(left, k);
			dir *= -1;
			
		}
		printf("%d\n", right - left);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
