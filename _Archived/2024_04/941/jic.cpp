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

//#define MULTI

#ifdef DEBUG
const long long N = 1000;
#endif
#ifndef DEBUG
const long long N = 500100;
#endif
class foo{
	
	public:
		int t;
		foo(){
		}
		foo(int x): t(x){
		}
		void print(){
			printf("%d ", t);
		}
		void k(){
			printf("%d ", t+1);
		}
};
class bar: public foo{
	public:
		bar(){
		}
		bar(int x): t(x){
		}
		void print(){
			printf("%d ", -t);
		}
		void jls() {
			printf("Jiangly ");
		}
};
int main()
{
    #ifdef DEBUG
    freopen("1.txt", "r", stdin);
    #endif
    #ifdef MULTI
    int z;
    cin >> z;
    while(z--){

    }
    #endif
	#ifndef MULTI
	vector<foo> a;
	a.push_back(foo(3));
	a.push_back(bar());
	a[0].print();
	a[1].print();
	a[0].k();
	a[1].k();
	a[1].jls();
	#endif
 	return 0;
}
