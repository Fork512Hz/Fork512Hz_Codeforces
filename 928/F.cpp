#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI
bool gr[9][9] = {};
int ansa, ansb, step;
vector <pair<int, int>> a, b;
	
	
bool chk(int i, int j)
{
	if(gr[i][j] && gr[i+1][j+1] && gr[i-1][j-1] && gr[i+1][j-1] && gr[i-1][j+1]) return false;
	else return true;
}
bool chk1()
{
	for(int i=2; i<=6; i++)
		for(int j=2; j<=6; j++) if ((i+j)%2 == 0)
		{
			if(!chk(i, j)) return false;
		}
	return true;
}
bool chk2()
{
	for(int i=2; i<=6; i++)
		for(int j=2; j<=6; j++) if ((i+j)%2)
		{
			if(!chk(i, j)) return false;
		}
	return true;
}
void bf1(int x)
{
	if(x >= 25 || step >= 4) 
	{
		if(chk1()) ansa = min(ansa, step);
		return;
	}
	int p, q;
	p = a[x].first;
	q = a[x].second;
	bf1(x+1);
	if(gr[p][q])
	{
		step++;
		gr[p][q] = 0;
		bf1(x+1);
		gr[p][q] = 1;
		step--;
	}
}

void bf2(int x)
{
	if(x >= 24 || step >= 4) 
	{
		if(chk2()) ansb = min(ansb, step);
		return;
	}
	int p, q;
	p = b[x].first;
	q = b[x].second;
	bf2(x+1);
	if(gr[p][q])
	{
		step++;
		gr[p][q] = 0;
		bf2(x+1);
		gr[p][q] = 1;
		step--;
	}
}
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    for(int i=1; i<=7; i++)
    {
    	for(int j=1; j<=7; j++)
    	{
    		if((i+j) % 2) b.push_back(pair<int, int> (i, j));
    		else a.push_back(pair<int, int> (i, j));
		}
	}
    for(int zz=0; zz<z; zz++)
	{
    	memset(gr, 0, sizeof(gr));
		for(int i=1; i<=7; i++)
		{
			string s;
			cin >> s;
			for(int j=0; j<7; j++) if(s[j] == 'B') gr[i][j+1] = 1;
		}
		
		ansa = 100;
		ansb = 100;
		step = 0;
		bf1(1);
		step = 0;
		bf2(1);
		printf("%d\n", ansa+ansb);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
