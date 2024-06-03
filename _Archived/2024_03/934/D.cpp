#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<utility>
#include<vector>
#include<cmath>
using namespace std;
typedef pair<long long, long long> pii;
typedef vector<long long> vint;
typedef long long ll;
//#define DEBUG

#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 200100;
#endif
char a[N<<1];
int span[N<<1], same1[N], same2[N];
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
   // bool flag = 0;
    //int flint = 0;
    while(z--){
    	//if(z == 19999) flag=1;
    	int len, q;
    	scanf("%d%d", &len, &q);
		string s;
		cin >> s;
		same1[len-1] = len-1;
		same2[len-1] = len-1;
		if(len > 1) same2[len-2] = len-2;
		for(int i=len-2; i>=0; i--) 
			same1[i] = (s[i] == s[i+1])? same1[i+1]: i;
		for(int i=len-3; i>=0; i--)
			same2[i] = (s[i] == s[i+2])? same2[i+2]: i;
		//<Manacher>
	    for(int i=0; i<len; i++) 
			a[i*2+2] = s[i];
	    for(int i=0; i<len+1; i++) a[i*2+1] = '$';
	    a[0] = '!';
	    a[len*2+2] = '^';  
	    int n = len*2+3;
	    int maxcenter = 2;
	    int maxright = 3;
	    span[0] = 0;
	    span[1] = 0;
	    span[2] = 1;
	    for(int i=3; i<n; i++)
	    {
	        int j;
	        if(i <= maxright) j = min(maxright - i + 1, span[2*maxcenter - i] + 1);
	        else j = 1;
	        while(a[i+j] == a[i-j]) j++;
	        j--;
	        span[i] = j;
	        if(i+j > maxright)
	        {
	            maxright = i+j;
	            maxcenter = i;
	        }
	    }
	    //</Manacher>
	    
	    for(int i=0; i<q; i++)
	    {
	    	int x, y;
	    	scanf("%d%d", &x, &y);
	    	/*if(flag) 
	    	{
	    		flint++;
	    		if(flint == 240)
	    		{
	    			cout << s << endl;
	    			printf("%d %d", x, y);
	    			return 1000;
				}
				else continue;
			}*/
	    	x--; y--;
	    	if(same1[x] >= y) printf("0\n"); //"aaaaaa"
	    	else if(same2[x] >= y-1 && same2[x+1] >= y-1) //"ababab"
	    	{
	    		ll t = (y-x+1) >> 1;
	    		printf("%lld\n", t * (t+1));
			}
			else if(span[x+y+2] >= (y-x+1))
				printf("%lld\n", (ll)(y-x) * (y-x+1) / 2 - 1);
			else printf("%lld\n", (ll)(y-x+2) * (y-x+1) / 2 - 1);
		}
    }
    #endif
	#ifndef MULTI

	#endif
 	return 0;
}
