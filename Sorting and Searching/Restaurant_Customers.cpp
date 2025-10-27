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
    vector<int> starts(n),ends(n);
    for(int i=0;i<n;i++) cin>>starts[i]>>ends[i];
    sort(all(starts));
    sort(all(ends));
    auto find=[&](int num){
        auto ub1=upper_bound(all(starts),num)-begin(starts);
        auto ub2=upper_bound(all(ends),num)-begin(ends);
        return abs(ub1-ub2);
    };
    int ans=0;
    for(int i=0;i<n;i++) ans=max(ans,(int)find(starts[i]));
    cout<<ans;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}