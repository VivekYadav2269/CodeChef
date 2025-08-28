#include <bits/stdc++.h>
using i64 = long long;

const int mod = 998244353;

int add(int x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = 1;
    for (int i = 0, x = n, j = n - 1; i < j; x--) {
        if (a[i] != x && a[j] != x) {
            ans = add(ans, 1);
        } else {
            ans = add(ans, x);
        }
        while (i < j && a[i] >= x) {
            i++;
        }
        while (i < j && a[j] >= x) {
            j--;
        }
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