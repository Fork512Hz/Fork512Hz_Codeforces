#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
#include<bitset>
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
const long long N = 5010;
#endif
string s;
int n;
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		scanf("%d", &n);
		cin >> s;
		
		for(int k=n; k>=1; k--)
		{
			bitset<N> a;
			for(int i=0; i<n; i++) a[i] = (s[i] == '1');
			vector<int> flips = {0};
			int i;
			for(i=0; i+k<=n; i+=k)
			{
				int nf = flips.size();
				for(int j=nf-1; j>=1; j-=2)
					for(int t=flips[j-1]; t<flips[j]; t++)
						a.flip(i+t);
				flips = {0};
				bool prev = 1;
				for(int j=0; j<k; j++)
				{
					if(a[i+j] != prev)
					{
						prev = !prev;
						flips.push_back(j);
					}
				}
				
			}
			if(i + flips.back() > n) continue;
			int nf = flips.size();
			for(int j=nf-1; j>=1; j-=2)
			{
				for(int t=flips[j-1]; t<flips[j]; t++)
					a.flip(i+t);
			}
			bool fin = 1;
			for(; i<n; i++) if(!a[i])
			{
				fin = 0;
				break;
			}
			if(fin)
			{
				printf("%d\n", k);
				goto fff;
			}
		}
		printf("-1\n");
		fff:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
