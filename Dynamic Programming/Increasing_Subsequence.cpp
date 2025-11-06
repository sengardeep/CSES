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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(ans.empty()||ans.back()<v[i]) ans.pb(v[i]);
        else{
            auto lb=lower_bound(all(ans),v[i])-begin(ans);
            ans[lb]=v[i];
        }
    }
    cout<<ans.size();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}