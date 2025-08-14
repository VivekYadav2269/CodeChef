#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        if (a[i] > b[i]) {
            std::swap(a[i], b[i]);
        }
    }
    
    i64 ans = 1;
    for (int i = 1, ab = 1, ba = 1, aa = 1, bb = 1; i < n; i++) {
        int AA = aa, AB = ab, BA = ba, BB = bb;
        if (a[i - 1] < a[i]) {
            AA = std::max(aa, ba) + 1;
        } else {
            AA = 1;
        }
        if (a[i - 1] < b[i]) {
            AB = std::max(aa, ba) + 1;
        } else {
            AB = 1;
        }
        if (b[i - 1] < a[i]) {
            BA = std::max(ab, bb) + 1;
        } else {
            BA = 1;
        }
        if (b[i - 1] < b[i]) {
            BB = std::max(ab, bb) + 1;
        } else {
            BB = 1;
        }
        ans += 1LL * std::max({AA, AB, BA, BB});
        aa = AA, ab = AB, ba = BA, bb = BB;
    }
    std::cout << ans << '\n';
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