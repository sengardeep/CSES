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
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        if(b==0){
            cout<<1<<endl;
            continue;
        }
        if(a==0){
            cout<<0<<endl;
            continue;
        }
        int ans=1;
        while(b){
            if(b&1) ans=(ans*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        cout<<ans<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}