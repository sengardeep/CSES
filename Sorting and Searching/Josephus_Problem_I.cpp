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
    vector<int> vis(n+1,0);
    vector<int> v(n);
    iota(all(v),1);
    int x=1;
    while(x<v.size()){
        cout<<v[x]<<" ";
        vis[v[x]]=1;
        if(vis[v[x-1]]==0) v.pb(v[x-1]);
        x=x+2;
    }
    cout<<v[x-1];
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}