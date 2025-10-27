#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod=1e9+7;
void solve() {
    int n;
    cin>>n;
    map<int,int> map;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        map[x]++;
    }
    int ans=1;
    for(auto [num,f] : map) ans=(ans*(1+f))%mod;
    cout<<ans-1;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}