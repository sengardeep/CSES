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
    vector<int> dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=0&&j>=i-6;j--){
            dp[i]=(dp[i]+dp[j])%1000000007;
        }
    }
    cout<<dp[n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}