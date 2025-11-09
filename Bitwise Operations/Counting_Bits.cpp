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
    long long n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < 61; ++i) {
        long long cycle = 1LL << (i + 1);
        long long ones = 1LL << i;
        long long full = (n / cycle) * ones;
        long long rem = n % cycle;
        long long extra = max(0LL, rem - ones + 1);
        ans += full + extra;
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}