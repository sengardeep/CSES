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
    auto binExpo=[](int a,int b,int m)->int{
        if(b==0) return 1;
        if(a==0) return 0;
        int ans=1;
        while(b){
            if(b&1) ans=(ans*a)%m;
            a=(a*a)%m;
            b>>=1;
        }
        return ans;
    };
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        //We'll solving it using Fermett's Little Theorem i.e. (calulate b^c mod m-1, then a^E mod m)
        int E=binExpo(b,c,mod-1);
        int ans=binExpo(a,E,mod);
        cout<<ans<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}