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
    using T=tuple<int,int,int>;
    vector<T> v(n);
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[i]={x,y,z};
    }
    vector<int> dp(n,0);
    sort(all(v));
    vector<int> starts,suffix(n+1,0);
    for(auto [s,e,x] : v) starts.pb(s);
    for(int i=n-1;i>=0;i--){
        auto [s,e,x] = v[i];
        auto ub=upper_bound(all(starts),e)-begin(starts);
        dp[i]=x+suffix[ub];
        suffix[i]=max(suffix[i+1],dp[i]);
    }
    int ans=*max_element(all(dp));
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}