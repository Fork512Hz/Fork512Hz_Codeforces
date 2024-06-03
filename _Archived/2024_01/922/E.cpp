#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<cstdlib>
typedef long long ll;
using namespace std;

//#define DEBUG

#define MULTI

#ifdef DEBUG
const ll N = 1000;
#endif
#ifndef DEBUG
const ll N = 2010;
#endif
int ans[N];

int query(int x)
{
	printf("? %d\n", x);
	fflush(stdout);
	char c;
	cin >> c;
	switch(c)
	{
		case '=': return 0;
		case '>': return 1;
		case '<': return -1;
		default: exit(1);
	}
}
void qsort(vector<int>& todo, int l, int r)
{
	if(l > r) return;
	if(l == r)
	{
		ans[todo[0]] = l;
		return;
	}
	int len = todo.size();
	if(len == 0) return;
	int x = rand() % len;
	while(query(todo[x]) != 0) 
		;
	vector<int> ltodo, rtodo;
	int pos = 0;
	for(int y=0; y<len; y++)
	{
		int i = todo[y];
		if(y==x) continue;
		if(query(i) == -1)
		{
			ltodo.push_back(i);
			pos++;
		}
		else
		{
			rtodo.push_back(i);
		}
		query(todo[x]);
	}
	ans[todo[x]] = pos+l;
	qsort(ltodo, l, l+pos-1);
	qsort(rtodo, l+pos+1, r);
}
int main()
{ 
    #ifdef MULTI
    srand(time(NULL));
    int z;
    cin >> z;
    while(z--){
		int n;
		cin >> n;
		vector<int> todo;
		for(int i=1; i<=n; i++) todo.push_back(i);
		qsort(todo, 1, n);
		printf("! ");
		for(int i=1; i<=n; i++) printf("%d ", ans[i]);
		printf("\n");
		fflush(stdout);
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
