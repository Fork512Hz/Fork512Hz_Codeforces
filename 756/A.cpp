// Problem: A. Make Even
// Contest: Codeforces - Codeforces Round 756 (Div. 3)
// URL: https://codeforces.com/contest/1611/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<iostream>
using namespace std;
int main()
{
    int z;
    cin>>z;
    for(int zz=1; zz<=z; zz++)
    {
        string s;
        cin >> s;
        int l = s.size();
        if(s[l-1] % 2 == 0 ) cout << 0 << endl;
        else if(s[0] %2 ==0) cout<< 1 << endl;
       
        else{
             bool f = 0;
        for(int i=1; i<l-1; i++)
            if(s[i] % 2 ==0) 
            {
                if(!f)cout<<2 << endl;
                f = 1;
            }
        if(!f )cout << -1 << endl;
        }
    }
    return 0;
}