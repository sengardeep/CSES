#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9+7;

void solve() {
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> dp(n);
    vector<int> ndp(n,0);
    ndp[0]=1;
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<n;j++){
            if(v[i][j]=='*') dp[j]=0;
            else {
                if(j>0)
                dp[j]=(dp[j]+dp[j-1])%mod;
                dp[j]=(dp[j]+ndp[j])%mod;
            }
        }
        ndp=dp;
        dp.assign(n,0);
    } 
    cout<<ndp[n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}