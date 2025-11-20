#include <bits/stdc++.h>
using i64 = long long;

const int mod = 998244353;
const i64 inf = 1E18;

int add(int x, int y) {
    x += y; 
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int power(int x, i64 y) {
    int ans = 1;
    for (; y != 0; x = mul(x, x), y >>= 1) {
        if (y & 1) {
            ans = mul(ans, x);
        }
    }
    return ans;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector adj(n, std::vector <int> ());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (n == 1) {
        if (a[0] >= 0) {
            std::cout << power(2, a[0]) << '\n';
        } else {
            std::cout << add(mod, -power(2, -a[0])) << '\n';
        }
        return;
    }
    
    std::vector <std::array <i64, 3>> dp(n, {-inf, -inf, -inf});
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) {
            dp[i][0] = a[i];
        } else {
            dp[i][1] = -a[i];
        }
    }
    auto dfs = [&](auto &self, int u, int p) -> void {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            self(self, v, u);
            i64 u0 = dp[u][0], u1 = dp[u][1];
            dp[u][0] = std::max({dp[u][0], dp[v][1] + u1, dp[v][0] + u0});
            dp[u][1] = std::max({dp[u][1], u0 + dp[v][1], u1 + dp[v][0]});
            dp[u][2] = std::max({dp[u][2], dp[v][0], dp[v][2]});
        }
    };
    dfs(dfs, 0, -1);
    
    int ans = power(2, std::max(dp[0][0], dp[0][2]));
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