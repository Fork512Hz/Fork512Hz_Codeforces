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
		cin >> n;
		char s[15];
		scanf("%s", s);
		int i, j;
		for(i=0; i<n; i++) if(s[i] == 'B') break;
		for(j=n-1; j>=0; j--) if(s[j] == 'B') break;
		if(i > j) printf("0\n");
		else printf("%d\n", j-i+1);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
