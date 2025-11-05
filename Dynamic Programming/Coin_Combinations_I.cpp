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
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> dp(x+1,0);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(v[j]<=i) dp[i]=(dp[i]+dp[i-v[j]])%1000000007;
        }
    }
    cout<<dp[x];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}