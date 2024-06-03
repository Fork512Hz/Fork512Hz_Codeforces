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
double findMedianSortedArrays(vector<ll>& nums1, vector<ll>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int l = 0; int r = m-1;
        int k = (n+m-1) >> 1;
        if(n == 0)
            return 1.0 * (nums2[m/2] + nums2[(m-1)/2]) / 2;
        if(m == 0)
            return 1.0 * (nums1[n/2] + nums1[(n-1)/2]) / 2;
        while(l <= r)
        {
            int mid = (l+r) >> 1;
            if(k-mid < 0) r = mid - 1;
            else if(k-mid >= n) l = mid+1;
            else if(nums2[mid] < nums1[k-mid])
                l = mid+1;
            else
                r = mid-1;
        }
        if(n+m & 1)
        	if(r < 0 || r >= m) return nums1[k-r-1];
        	else if(k-r-1 < 0 || k-r-1 >= n) return nums2[r];
            else return max(nums2[r], nums1[k-r-1]);
        else
        {
        	int x, y;
        	if(r < 0 || r >= m) x= nums1[k-r-1];
        	else if(k-r-1 < 0 || k-r-1 >= n) x = nums2[r];
            else x = max(nums2[r], nums1[k-r-1]);
            
            if(l < 0 || l >= m) y = nums1[k-r];
            else if(k-r < 0 || k-r >= n) y = nums2[l];
            else y = min(nums2[l], nums1[k-r]);
            return 1.0 * (x+y) / 2;
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
    while(z--){

    }
    #endif
	#ifndef MULTI
	vint a = {3};
	vint b = {-2, -1};
	printf("%lf", findMedianSortedArrays(a,b));
	#endif
 	return 0;
}
