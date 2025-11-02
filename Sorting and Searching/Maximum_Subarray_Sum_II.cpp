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
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> pre(n+1, 0);
    for(int i=0;i<n;i++) pre[i+1]=pre[i]+v[i];
    int ans=LLONG_MIN;
    multiset<int> ms;
    for(int i=a;i<=n;i++){
        ms.insert(pre[i-a]);
        if(i>b){
            auto it = ms.find(pre[i-b-1]);
            if(it!=ms.end()) ms.erase(it);
        }
        ans=max(ans,pre[i]-*ms.begin());
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}