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
    int ans=0,sum=0;
    bool zero=0;
    for(int i=0;i<n;i++){
        if(v[i]==0) zero=1;
        sum+=v[i];
        if(sum<0) sum=0;
        ans=max(ans,sum);
    }
    if((!zero && !ans)) ans=*max_element(all(v));
    cout<<ans;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}