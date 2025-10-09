#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector <i64> dp(n);
    dp[0] = a[0];
    for (int i = 1; i < n; i++) {
        dp[i] = std::min(dp[i - 1] + a[i], abs(a[i - 1] - a[i]) + (i < 2 ? 0 : a[i - 2]) + (i < 3 ? 0 : dp[i - 3]));
    }
    std::cout << dp[n - 1] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}