#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, c;
    std::cin >> n >> c;
    
    std::vector <int> b(n), d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }
    
    std::vector min(n, std::vector <int> (n, 1 << 30));
    std::vector idx(n, std::vector <int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = (i - j + n) % n;
            if (min[i][(j - 1 + n) % n] > b[x]) {
                min[i][j] = b[x];
                idx[i][j] = j;
            } else {
                min[i][j] = min[i][(j - 1 + n) % n];
                idx[i][j] = idx[i][(j - 1 + n) % n];
            }
        }
    }
    
    i64 ans = 1LL << 60;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        i64 res = 0;
        for (int j = 0; j < n; j++) {
            cnt = std::max(cnt, idx[j][i]);
            res += 1LL * min[j][i] * d[j];
        }
        res += cnt * c;
        ans = std::min(ans, res);
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