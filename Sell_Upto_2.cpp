#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector <std::vector <std::array <int, 3>>> dp(n, std::vector <std::array <int, 3>> (n));
    dp[0][0][1] = a[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j) {
                dp[i][j][0] = std::max({dp[i - 1][j - 1][0], dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]});
            } 
            dp[i][j][1] = std::max({dp[i - 1][j][0], dp[i - 1][j][1], dp[i - 1][j][2]});
            dp[i][j][1] += a[i];
            if (j + 1 <= i) {
                dp[i][j][2] = std::max({dp[i - 1][j + 1][0], dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]});
                dp[i][j][2] += 2 * a[i];
            }
        }
    }
    std::cout << std::max(dp[n - 1][0][1], dp[n - 1][0][2]) << '\n';
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