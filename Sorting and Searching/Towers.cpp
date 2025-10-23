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
        auto it = upper_bound(all(ans),v[i])-ans.begin();
        if(it==ans.size()){
            ans.pb(v[i]);
        }else{
            ans[it]=v[i];
        }
    }
    cout<<ans.size();
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}