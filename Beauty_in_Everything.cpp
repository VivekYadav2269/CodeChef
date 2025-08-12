#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    std::string p = s;
    p.erase(std::unique(p.begin(), p.end()), p.end());
    int m = p.size();
    std::vector <int> cnt(m);
    for (int i = 0, j = 0, c = 0; i < n; i++) {
        if (s[i] != p[j]) {
            cnt[j] = c;
            c = 0;
            j++;
        }
        c++;
        if (i == n - 1) {
            cnt[j] = c;
        }
    }
    
    int ans = 0;
    for (int i = 3; i < n; i++) {
        if (((s[i - 3] == '0' && s[i - 2] == '1') || (s[i - 3] == '1' && s[i - 2] == '0')) && s[i - 3] == s[i - 1] && s[i - 2] == s[i]) {
            ans = 4;
        }
    }
    
    for (int i = 2; i < m; i++) {
        if (cnt[i - 1] == 1) {
            ans = std::max(ans, cnt[i - 2] + cnt[i - 1] + cnt[i]);
        }
    }
    for (int i = 1; i < m; i++) {
        ans = std::max(ans, 1 + std::max(cnt[i - 1], cnt[i]));
    }
    for (int i = 0; i < m; i++) {
        ans = std::max(ans, cnt[i]);
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
