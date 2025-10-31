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
    //Sparse Table
    auto findLog=[](int n){
        int ans=0;
        while(1<<(ans+1)<=n) ans++;
        return ans;
    };
    int LOG=findLog(n);
    vector<vector<int>> st(n,vector<int>(LOG+1));
    for(int i=0;i<n;i++) st[i][0]=v[i];
    for(int j=1;j<=LOG;j++) for(int i=0;i+(1<<j)-1<n;i++) st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    auto query=[&](int l,int r){
        int len=r-l+1;
        int k=findLog(len);
        return min(st[l][k],st[r-(1<<k)+1][k]);
    };
    while(q--){
        int l,r;
        cin>>l>>r;
        --l;
        --r;
        cout<<query(l,r)<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}