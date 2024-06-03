#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<functional>
#include<deque>
#include<map>
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
map<int, int> t;
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    t.clear();
    t[3]++;
    t[5]++;
    t[3]++;
    for(auto i: t) printf("%d %d\n",i.first, i.second);
 	return 0;
}
