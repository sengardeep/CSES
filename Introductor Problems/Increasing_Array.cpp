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
    cin>>n;
    vi v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int ans=0;
    for(int i=1;i<n;i++){
        ans += max(0LL,v[i-1]-v[i]);
        v[i] = max(v[i],v[i-1]);
    }
    cout<<ans;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}