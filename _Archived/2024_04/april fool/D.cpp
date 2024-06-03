#include<cstdio>
#include<algorithm>
#include<chrono>
using namespace std;
int main()
{
    chrono::high_resolution_clock::time_point t1
	= chrono::high_resolution_clock::now();
	string s;
	cin >> s;
	while(1)
	{
		cout << ' ';
		chrono::high_resolution_clock::time_point t2 = 
		chrono::high_resolution_clock::now();
		chrono::duration<double, ratio<1,1>> duration_s(t2-t1);
		if(duration_s.count() >= 0.98) break; 
	}
	cout << '?\n';
 	return 0;
}
