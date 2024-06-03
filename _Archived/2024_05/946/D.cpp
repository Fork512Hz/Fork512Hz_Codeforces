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
		int x, y;
		x=0; y=0;
		for(int i=0; i<n; i++) switch(s[i])
		{
			case 'E': x++; break;
			case 'W': x--; break;
			case 'S': y--; break;
			case 'N': y++; break;
		}
		if(x % 2 || y % 2)
		{
			printf("NO\n");
			continue;
		}
		if(x == 0 && y == 0)
		{
			if(n == 2) printf("NO\n");
			else
			{
				printf("H");
				char tr;
				switch(s[0])
				{
					case 'E': tr='W'; break;
					case 'W': tr='E'; break;
					case 'S': tr='N'; break;
					case 'N': tr='S'; break;
				}
				for(int i=1; i<n; i++)
					if(s[i] == tr)
					{
						printf("H");
						tr = '0';
					}
					else printf("R");
				printf("\n");
			}
			continue;
		}
		x /= 2; y /= 2;
		int xc = 0, yc = 0;
		for(int i=0; i<n; i++) switch(s[i])
		{
			case 'E':
				if(x > 0)
					if(xc < x)
					{
						printf("H");
						xc ++;
					}
					else printf("R");
				else printf("R");
				break;
			case 'W':
				if(x < 0)
					if(xc > x)
					{
						printf("H");
						xc --;
					}
					else printf("R");
				else printf("R");
				break;
			case 'N':
				if(y > 0)
					if(yc < y)
					{
						printf("H");
						yc ++;
					}
					else printf("R");
				else printf("R");
				break;
			case 'S':
				if(y < 0)
					if(yc > y)
					{
						printf("H");
						yc --;
					}
					else printf("R");
				else printf("R");
				break;
		}
		printf("\n");
    }
 	return 0;
}
