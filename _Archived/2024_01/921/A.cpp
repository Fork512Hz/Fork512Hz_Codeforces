#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
typedef long long ll;
#define DEBUG
#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = //TODO
#endif

using namespace std;

int main()
{
    #ifdef DEBUG
    //freopen("1.txt", "r", stdin);
    #endif
	int z;
	cin >> z;
	while(z--)
    {
    	int n,k;
    	scanf("%d%d",&n, &k);
    	for(int i=0; i<n; i++)
    	{
    		for(int j=0; j<k; j++) printf("%c", 'a' + j);
		}
		printf("\n");
	}
 	return 0;
}
