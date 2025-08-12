#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::string s;
    std::cin >> s;
    
    // std::vector <array <int, 2>> pre(n, {});
    // for (int i = 0, i < n; i++) {
    //     if (i == 0) {
    //         pre[0][s[0] - '0'] = 1;
    //     } else {
    //         pre[i][s[i] - '0'] = pre[i - 1][s[i] - '0'] + 1;
    //     }
    // }
    
    auto check = [&](int x) -> bool {
        int c = 0;
        for (int i = 0, z = 0, o = 0, j = 0; i < n; i++) {
            if (s[i] == '0') {
                z++;
            }
            if (s[i] == '1') {
                o = std::max(o, z) + 1;
            }
            j = std::max(j, std::max(o, z));
            if (j >= x) {
                j = 0;
                z = 0;
                o = 0;
                c++;
            }
        }
        // cout << c << ' ' << x << '\n';
        return c >= k;
    };
    
    int l = 1, h = n + 1;
    while (l < h) {
        int m = (l + h) / 2;
        if (check(m)) {
            l = m + 1;
        } else {
            h = m;
        }
    }
    std::cout << l - 1 << '\n';
    // std::cout << '\n';
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
