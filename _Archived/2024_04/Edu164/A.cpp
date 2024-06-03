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
		string a,b;
		cin >> a >> b;
		bool flag = 1;
		int n = a.size();
		for(int i=0; i<n; i++)
		{
			if(a[i] == b[i]);
			else if(flag)
			{
				if(a[i] > b[i]) swap(a[i], b[i]);
				flag = 0;
			}
			else
			{
				if(a[i] < b[i]) swap(a[i], b[i]);
			}
		}
		cout << a << endl << b << endl;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
