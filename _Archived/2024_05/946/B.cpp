#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
#include<deque>
#include<set>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vll;
typedef long long ll;
typedef long long i64;

//#define DEBUG

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
// const ll M = 998244353;
int oc[30];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    //z = 1;
    cin >> z;
    while(z--){
    	int n;
    	scanf("%d", &n);
		string s;
		cin >> s;
		memset(oc, 0, sizeof(oc));
		for(char c: s)
			oc[c-'a'+1] = 1;
		vector<char> l;
		int cnt = 0;
		for(int i=1; i<=26; i++)
			if(oc[i])
			{
				l.push_back(i+'a'-1);
				oc[i] = cnt;
				cnt++;
			}
		for(char c: s)
		{
			int t = oc[c-'a'+1];
			printf("%c", l[cnt-1-t]);
		}
		printf("\n");
		
    }
 	return 0;
}
