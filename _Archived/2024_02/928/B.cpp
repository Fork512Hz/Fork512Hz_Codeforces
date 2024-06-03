#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;


#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 1000;
#endif
int cnt[N];
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
		for(int i=0; i<n; i++)
		{
			string s;
			cin >> s;
			cnt[i] = 0;
			for(int j=0; j<n; j++) if(s[j] == '1') cnt[i] ++;
		}
		int t = -1;
		for(int i=0; i<n; i++) if(cnt[i] != 0)
		{
			if(t == -1) t = cnt[i];
			else if(cnt[i] == t)
			{
				printf("SQUARE\n");
				break;
			}
			else
			{
				printf("TRIANGLE\n");
				break;
			}
		}
		
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
