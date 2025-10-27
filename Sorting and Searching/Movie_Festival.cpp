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
    vector<pii> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    sort(all(v),[&](pii a,pii b){return (a.second<b.second);});
    int ans=1;
    int curr=v[0].second;
    for(int i=1;i<n;i++){
        auto [s,e]=v[i];
        if(curr<=s){
            ans++;
            curr=e;
        }
    }
    cout<<ans;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}