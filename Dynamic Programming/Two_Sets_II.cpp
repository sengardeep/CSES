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
    vector<int> v(n);
    iota(all(v),1);
    int sum=n*(n+1)/2;
    if(sum&1){
        cout<<0;
        return;
    }
    int target=sum/2;
    vector<int> dp(target+1,0);
    dp[0]=1;
    vector<int> temp;
    for(int i=0;i<n;i++){
        for(int j=v[i];j<=target;j++) 
        {
            if(dp[j-v[i]]) temp.pb(j);
        }
        reverse(all(temp));
        for(auto it : temp) dp[it]=(dp[it]+dp[it-v[i]])%mod;
        temp.clear();
    }
    auto binExpo=[](int a,int b,int mod){
        int ans=1;
        while(b){
            if(b&1) ans=(ans*a)%mod;
            a=(a*a)%mod;
            b>>=1;
        }
        return ans;
    };
    int ans=(dp[target]*1LL*binExpo(2,mod-2,mod))%mod;
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}