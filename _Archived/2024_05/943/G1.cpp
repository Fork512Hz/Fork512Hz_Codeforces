#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstring>
using namespace std;
typedef pair<long long, long long> pii;
typedef long long ll;
typedef long long i64;

//#define DEBUG

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 200100;
#endif
// const ll M = 998244353;
int nxt[N];
string s;
int pfm[N];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
		int n, lb, rb;
		cin >> n >> lb >> rb;
		cin >> s;
		//bool flag = (n == 200000 && s.substr(0, 8) == "aabbbaab");
		const int SQRT = 115;
		nxt[0] = 0;
		for(int i=1; i<n; i++)
		{
			int p = nxt[i-1];
			while(p >= 0)
			{
				if(s[p] == s[i]) break;
				if(p == 0)
				{
					p = -1;
					break;
				}
				p = nxt[p-1];
			}
			nxt[i] = p+1;
		}
		//if(flag) goto part2;
		for(int k = lb; k <= min(SQRT, rb); k++)
		{
			if(k == 1)
			{
			    cout << n << ' ';
				continue;
			}
			int l = 1, r = n/k;
			while(l <= r)
			{
				int m = (l+r) >> 1;
				int j=0;
				int cnt = 1;
				for(int i=m; i<n; )
				{
					if(s[i] == s[j])
					{
						i++; j++;
						if(j == m)
						{
							cnt++;
							j = 0;
						}
					}
					else
					{
						if(j == 0) i++;
						else j = nxt[j-1];
					}
				}
				if(cnt >= k) l = m+1;
				else r = m-1;
			}
			cout << r << ' ';
		}
		//if(flag) return -100;
		//part2:
		memset(pfm, 0, sizeof(int) * (n+5));
		for(int m = 1; m <= n/SQRT; m++)
		{
			
			int j=0;
			int cnt = 1;
			for(int i=m; i<n; )
			{
				if(s[i] == s[j])
				{
					i++; j++;
					if(j == m)
					{
						cnt++;
						j = 0;
					}
				}
				else
				{
					if(j == 0) i++;
					else j = nxt[j-1];
				}
			}
			pfm[cnt] = m;
		}
		for(int i=n; i>=SQRT; i--)
			pfm[i] = max(pfm[i+1], pfm[i]);
		for(int i=max(lb, SQRT+1); i<=rb; i++)
			cout << pfm[i] << ' ';
		cout << '\n';
    }
 	return 0;
}