#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<iomanip>
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

int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    int z;
    z = 1;
    //cin >> z;
    while(z--){
		vector<string> a = {"↕", "Φ", "ghi"};
		for(string i: a) cout << setw(7) << i;
    }
 	return 0;
}
