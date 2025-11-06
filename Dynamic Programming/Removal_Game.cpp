#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                dp[i][j] = v[i];
            } else {
                int a = v[i] + min((i + 2 <= j ? dp[i + 2][j] : 0),
                                   (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0));
                int b = v[j] + min((i <= j - 2 ? dp[i][j - 2] : 0),
                                   (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0));
                dp[i][j] = max(a, b);
            }
        }
    }
    cout << dp[0][n - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}