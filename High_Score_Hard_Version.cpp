#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector <int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        b.push_back(x);
    }
    
    if (n > m) {
        std::swap(n, m);
        std::swap(a, b);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    
    int cnt = 0, ele = -1;
    i64 ans = 0;
    std::map <int, int> mp;
    for (int i = n - 1, j = m - 1; i >= 0; i--, j--) {
        mp[a[i]]++;
        mp[b[j]]++;
        if (cnt < mp[a[i]]) {
            cnt = mp[a[i]];
            ele = a[i];
        }
        if (cnt < mp[b[j]]) {
            cnt = mp[b[j]];
            ele = b[j];
        }
        ans += a[i] + b[j];
    }
    
    if (cnt > n) {
        int look = cnt - n;
        ans -= 2LL * look * ele;
        for (int i = m - n - 1; look && i >= 0; i--) {
            if (b[i] == ele) {
                continue;
            }
            look--;
            ans += ele + b[i];
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