#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = //TODO
#endif

int main()
{
    #ifdef DEBUG
    //freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n;
		string s;
		scanf("%d", &n);
		cin >> s;
		int m = s.size();
		bool fg = false;
		for(int i=0; i<m; i++)
		{
			if(s[i] < s[m-1-i])
			{
				fg = false;break;
			}
			else if(s[i] > s[m-1-i])
			{
				fg = true; break;
			}
		}
		if(fg)
		{
			for(int i=m-1; i>=0; i--) printf("%c", s[i]);
		}
		cout << s;
		printf("\n");
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
