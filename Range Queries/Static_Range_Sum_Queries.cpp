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
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> pre(n);
    pre[0]=v[0];
    for(int i=1;i<n;i++) pre[i]=pre[i-1]+v[i];
    auto rangeSum=[&](int l,int r)->int{
        int ans=pre[r];
        if(l>0) ans-=pre[l-1];
        return ans;
    };
    while(q--){
        int l,r;
        cin>>l>>r;
        --l;
        --r;
        cout<<rangeSum(l,r)<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}