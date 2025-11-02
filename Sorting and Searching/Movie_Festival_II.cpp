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
    int n,k;
    cin>>n>>k;
    vector<pii> v(n);
    for(int i=0;i<n;i++) cin>>v[i].second>>v[i].first;
    sort(all(v));
    multiset<int> ms;
    int ans=0;
    for(int i=0;i<k;i++) ms.insert(0);
    for(auto [e,s] : v){
        auto ub = ms.upper_bound(s);
        if(ub==ms.begin()) continue;
        --ub;
        ms.erase(ub);
        ms.insert(e);
        ans++;
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}