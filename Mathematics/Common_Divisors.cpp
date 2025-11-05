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
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > mx) mx = a[i];
    }
    vector<int> freq(mx + 1, 0);
    for (int x : a) freq[x]++;

    for (int i = mx; i >= 2; --i) {
        int count = 0;
        for (int j = i; j <= mx; j += i) {
            count += freq[j];
            if (count > 1) {
                cout << i;
                return;
            }
        }
    }
    cout << 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}