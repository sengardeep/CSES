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
    sort(all(v));
    vector<int> pre(n);
    pre[0]=v[0];
    for(int i=1;i<n;i++) pre[i]=v[i]+pre[i-1];
    int ans=1e18;
    for(int i=0;i<n;i++){
        int x=v[i];
        int p=0,s=0;
        if(i>0) p=pre[i-1];
        if(i<n) s=pre[n-1]-pre[i];
        int cost=abs(x*i-p)+abs(s-x*(n-1-i));
        ans=min(ans,cost);
    }
    cout<<ans;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}