#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int T, n; ll a[MAXN], s[MAXN], dp[MAXN];

deque<int> q;

inline 
bool check(ll x) {
    for (int i = 1; i <= n + 1; i++) dp[i] = 0;
    q.clear(), q.push_back(0);
    for (int i = 1, j = 0; i <= n + 1; i++) {
        for (; !q.empty() && s[i - 1] - s[q.front()] > x; q.pop_front());
        dp[i] = a[i] + dp[q.front()];
        for (; !q.empty() && dp[q.back()] >= dp[i]; q.pop_back());
        q.push_back(i);
    }
    return dp[n + 1] <= x;
}

ll l, r, mid;

int main() {
	freopen("1.txt", "r", stdin);
    for (scanf("%d", &T); T--;) {
        scanf("%d", &n), a[n + 1] = 0;
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
        for (l = 1, r = s[n]; l < r; check(mid = l + r >> 1) ? r = mid : l = mid + 1);
        printf("%lld\n", l);
    }
}