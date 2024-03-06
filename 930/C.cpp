#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 10000;
#endif

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    string s;
    while(z--){
		int n;
		scanf("%d", &n);
		int maxpos = 0;
		for(int i=1; i<n; i++)
		{
			printf("? %d %d %d %d\n", maxpos, maxpos, i, i);
			fflush(stdout);
			cin >> s;
			if(s[0] == '<') maxpos = i;
		}
		int best = (maxpos == 0? 1: 0);
		vector<int> cand = {best};
		for(int i=1; i<n; i++) if(i != maxpos)
		{
			printf("? %d %d %d %d\n", maxpos, best, maxpos, i);
			fflush(stdout);
			cin >> s;
			if(s[0] == '=') cand.push_back(i);
			else if(s[0] == '<')
			{
				cand = {i};
				best = i;
			}
		}
		int len = cand.size();
		int ans = best;
		for(int i=1; i<len; i++)
		{
			printf("? %d %d %d %d\n", ans, ans, cand[i], cand[i]);
			fflush(stdout);
			cin >> s;
			if(s[0] == '>') ans = cand[i];
		}
		printf("! %d %d\n", ans, maxpos);
		fflush(stdout);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
