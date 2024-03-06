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
const ll N = 50;
#endif
#ifndef DEBUG
const ll N = 50;
#endif
const char i2s[4] = {'C','D','H','S'};
vector<int> deck[4];
char out[N][3];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
	while(z--){
    	for(int i=0; i<4; i++) deck[i].clear();
		int n;
		scanf("%d\n", &n);
		char trump;
		scanf("%c\n", &trump);
		switch(trump)
		{
			case 'C': trump=0; break;
			case 'D': trump=1; break;
			case 'H': trump=2; break;
			case 'S': trump=3; break;
		}
		for(int i=0; i<2*n; i++)
		{
			char x, y;
			string s;
			cin >> s;
			x = s[0]; y = s[1];
			int t = x-48;
			switch(y)
			{
				case 'C': deck[0].push_back(t); break;
				case 'D': deck[1].push_back(t); break;
				case 'H': deck[2].push_back(t); break;
				case 'S': deck[3].push_back(t); break;
			}
		}
		for(int i=0; i<4; i++) sort(deck[i].begin(), deck[i].end());
		int top = 0;
		int trumpsize = deck[trump].size();
		int rem = 0;
		for(int i=0; i<=3; i++) if(i != trump)
		{
			char t = i2s[i];
			int m = deck[i].size();
			if(m%2)
			{
				if(rem >= trumpsize)
				{
					printf("IMPOSSIBLE\n");
					goto fin;
				}
				out[top][0] = deck[i][m-1]+48;
				out[top][1] = t;
				top++;
				out[top][0] = deck[trump][rem]+48;
				out[top][1] = i2s[trump];
				top++;
				rem++;
				m--;
			}
			for(int j=0; j<m; j++)
			{
				out[top][0] = deck[i][j]+48;
				out[top][1] = t;
				top++;
			}
		}
		for(int i=rem; i<trumpsize; i++)
		{
			out[top][0] = deck[trump][i]+48;
			out[top][1] = i2s[trump];
			top++;
		}
		for(int i=0; i<top; i+=2)
		{
			printf("%c%c %c%c\n", out[i][0], out[i][1], out[i+1][0], out[i+1][1]);
		}
		fin:;
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
