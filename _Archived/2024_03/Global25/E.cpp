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
		string s;
		cin >> s;
		int n = s.size();
		vector<int> seg;
		char c = s[0];
		int cnt = 0;
		for(int i=0; i<=n/2; i++)
			if(s[i] != s[n-1-i])
			{
				cerr << "Case1: not palindrome\n";
				printf("YES\n1\n");
				cout << s << endl;
				goto fin;
			}
		for(int i=0; i<n/2; i++) 
			if(s[i] != c && s[i+1] != c)
			{
				cerr << "Case2: 2 adjacent characters != c\n";
				printf("YES\n2\n");
				cout << s.substr(0, i+1) << ' ' << s.substr(i+1) <<endl;
				goto fin;
			}
		
		
		for(int i=0; i<n; i++)
		{
			if(s[i] == c) cnt++;
			else
			{
				seg.push_back(cnt);
				if(cnt != seg[0])
				{
					cerr << "Case3: different segs\n";
					printf("YES\n2\n");
					cout << s.substr(0, i) << ' ' << s.substr(i) << endl;
					goto fin;
				}
				cnt = 0;
			}
		}
		seg.push_back(cnt);
		if(seg.size() <= 2)
		{
			cerr << "Fail1: <=2 segs\n";
			printf("NO\n");
			goto fin;
		}
		if(seg[0] != 1)
		{
			cerr << "Case4: Seg longer than 1\n";
			printf("YES\n2\n");
			cout << s.substr(0, seg[0] + 2) << ' ' << s.substr(seg[0] + 2) << endl;
			goto fin;
		}
		for(int i=3; i<n; i+=2)
		{
			if(s[i] != s[i-2])
			{
				cerr << "Case5: different interpolation\n";
				printf("YES\n2\n");
				cout << s.substr(0, i+2) << ' ' << s.substr(i+2) << endl;
				goto fin;
			}
		}
		cerr << "Fail 2: abababababababa\n";
		printf("NO\n");
		
		fin:
		;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
