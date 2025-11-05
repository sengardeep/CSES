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
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<vector<int>> dp(n,vector<int>(m+1,0)); 
    const int mod=1e9+7;
    if(v[0]==0){
        for(int i=1;i<=m;i++) dp[0][i]=1;
    }else{
        dp[0][v[0]]=1;
    }
    for(int i=1;i<n;i++){
        if(v[i]){
            dp[i][v[i]]=dp[i-1][v[i]];
            if(v[i]>1)
            dp[i][v[i]]=(dp[i][v[i]]+dp[i-1][v[i]-1])%mod;
            if(v[i]<m)
            dp[i][v[i]]=(dp[i][v[i]]+dp[i-1][v[i]+1])%mod;
        }else{
            for(int x=1;x<=m;x++){
                dp[i][x]=dp[i-1][x];
                if(x>1)
                dp[i][x]=(dp[i][x]+dp[i-1][x-1])%mod;
                if(x<m)
                dp[i][x]=(dp[i][x]+dp[i-1][x+1])%mod;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++) ans=(ans+dp[n-1][i])%mod;
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}