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
    const int mod=1e9+7;
    auto binPow = [&](int a,int b,int mod){
        int ans=1;
        while(b){
            if(b&1) ans=(ans*1LL*a )%mod;
            a=(a*1LL*a)%mod;
            b>>=1;
        }
        return ans;
    };
    auto rangeSum=[&](int l,int r){
        l%=mod;
        r%=mod;
        int ans = (r*1LL*(r+1))%mod;
        ans = (ans*binPow(2,mod-2,mod))%mod;
        int left = (l*1LL*(l-1))%mod;
        left = (left*binPow(2,mod-2,mod))%mod;
        return (ans-left+mod)%mod;
    };
    int ans=0;
    int i=1;
    while(i<=n){
        int f=n/i;
        int nxt=n/f+1;
        int s=rangeSum(i,nxt-1);
        ans = (ans + (f*1LL*s )%mod)%mod;
        i=nxt;
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}