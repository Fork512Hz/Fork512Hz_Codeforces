#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll b[1<<18];int main(){ll z;cin>>z;while(z--){string s;cin>>s;ll n=s.size(),a=0,p=0,i;memset(b,0,n*5);for(i=0;i<n;i++){p+=(s[i]&1?-1:1);a+=b[p]++;if(p&1)b[p/2]=0;}cout<<a<<'\n';}return 0;}