#include <bits/stdc++.h>

void solve() {
    int n;
    std::cin >> n;
    
    std::set <int> s;
    for (int i = 0; i < n; i++) {
        s.insert(i + 1);
    }
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (s.contains(a[i])) {
            s.erase(a[i]);
        }
    }
    
    std::vector adj(n, std::vector <int> ());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = n;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        auto it = s.begin();
        for (int j : adj[i]) {
            if (a[j] == 0) {
                x = std::max(x, *it);
                it++;
            } else {
                x = std::max(x, a[j]);
            }
        }   
        if (a[i] == 0) {
            auto r = s.upper_bound(x);
            if (r != s.end() && x < *r) {
                ans = std::min(ans, *r);
            }
        } else {
            if (x <= a[i]) {
                ans = std::min(ans, a[i]);
            }
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