#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<set>
#include<cmath>
typedef long long ll;
using namespace std;

#define MULTI

set<int> k ;
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l);
		int ans = 0;
		k.clear();
		for(;;)
		{
			int t = l;
			for(;;)
			{
				if(k.find(t) == k.end())
				{
					ans++;
					k.insert(t);
				}
				if(t%b) break;
				t /= b;
			}
			if(l%a) break;
			l/=a;
		}
		printf("%d\n", ans);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
