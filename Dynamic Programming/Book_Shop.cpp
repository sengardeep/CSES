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
    int n,x;
    cin>>n>>x;
    vector<int> price(n),pages(n);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int p = x; p >= price[i]; p--) {
            dp[p] = max(dp[p], dp[p - price[i]] + pages[i]);
        }
    }
    cout<<dp[x];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}