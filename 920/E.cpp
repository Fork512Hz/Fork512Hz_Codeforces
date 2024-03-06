#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll n;
int main()
{
	int n, m, x1, y1, x2, y2;
	int z;
	cin >> z;
	while(z--)
	{
		cin >> n >> m >> x1 >> y1 >> x2 >> y2;
		if(x2 <= x1)
		{
			printf("Draw\n");
			continue;
		}
		
		bool turn = ((x2-x1) % 2);//1 for alice 0 for bob
		if(turn)
		{
			int dist2 = (y2-y1>0)? (m-y2): (y2-1);
			int dist1 = (y2-y1>0)? (m-y1): (y1-1);
			if(abs(y2 - y1) <= 1) 
			{
				printf("Alice\n");
				continue;
				
				
			}
			if(x2-x1 >= 2*dist1 - 1) printf("Alice\n");
			else printf("Draw\n");
		}
		else
		{
			int dist2 = (y2-y1>0)? (y2-1): (m-y2);
			int dist1 = (y2-y1>0)? (y1-1): (m-y1);
			if(y1 == y2)
			{
				printf("Bob\n");
				continue;
			}
			if(x2-x1 >= 2*dist2) printf("Bob\n");
			else printf("Draw\n");
		}
	}
 	return 0;
}
