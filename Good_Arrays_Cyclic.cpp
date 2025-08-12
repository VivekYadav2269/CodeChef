#include <bits/stdc++.h>
using i64 = long long;
const int mod = 1E9 + 7;

int add(int x, int y) {
    x += y;
    if (x >= mod) {
        x -= mod;
    }
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0) {
        x += mod;
    }
    return x;
}

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

int power(int x, int y) {
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
    
    std::vector <std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int cnt = std::count(s[i].begin(), s[i].end(), '1');
        ans = mul(ans, cnt);
    }
    
    int bad = 1;
    for (int i = 0; i < n / 2; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1' && s[i + n / 2][j] == '1') {
                cnt++;
            }
        }
        bad = mul(bad, cnt);
    }
    ans = sub(ans, bad);
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
