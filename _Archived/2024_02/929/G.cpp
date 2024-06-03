#include<cstdio>
#include<algorithm>
#include<iostream>

#include<vector>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 101000;
#endif
int grid[16];
const int pattern[8] = {0xaa55, 0xa55a, 0xc3c3, 0x9696, 0x55aa, 0x5aa5, 0x3c3c, 0x6969};
bool valid[8];
vector<int> todo;
inline int ans(int pt, int digit)
{
	return (pt>>digit) & 1;
}
int check(int x, int pos)
{
	if(grid[pos] != ans(pattern[x], pos))
	{
		valid[x] = 0;
		return 0;
	}
	return 1;
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){
		int n, m, t;
		scanf("%d%d%d", &n, &m, &t);
		printf("8\n");
		memset(grid, 0xff, sizeof(grid));
		memset(valid, 0x01, sizeof(valid));
		bool flag = 0;
		for(int i=0; i<t; i++)
		{
			int x, y;
			string s;
			cin >> x >> y >> s;
			if(flag)
			{
				printf("0\n"); 
				continue;
			}
			int pos = (x-1)%4 * 4 + (y-1)%4;
			int shape;
			if(s[0] == 'c') shape = 1;
			else shape = 0;
			if(shape + grid[pos] == 1)
			{
				flag = 1;
				printf("0\n");
				continue;
			}
			grid[pos] = shape;
			int ans = 0;
			for(int j=0; j<8; j++) if(valid[j])
				ans += check(j, pos);
			if(ans == 0) flag = 1;
			printf("%d\n", ans);
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
