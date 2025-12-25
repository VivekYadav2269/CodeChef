#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    i64 n;
    std::cin >> n;
    
    if (n < 5 || n == 6 || (n & 3) == 0) {
        i64 ans = 0;
        while (true) {
            if (n == 1) {
                std::cout << ans << '\n';
                return;
            } else if (n == 3) {
                std::cout << ans + 1 << '\n';
                return;
            } else if (n == 4 || n == 6) {
                std::cout << ans + 2 << '\n';
                return;
            } else if (n == 12) {
                std::cout << ans + 3 << '\n';
                return;
            }
            if (n >> 2 & 1) {
                n += 4;
            } else {
                n /= 2;
            }
            ans++;
        }
    }
    std::cout << "-1\n";
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