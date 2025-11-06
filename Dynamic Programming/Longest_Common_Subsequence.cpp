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
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    vector<int> ans;
    int i=n,j=m;
    while(i>0&&j>0){
        if(a[i-1]==b[j-1]){
            ans.pb(a[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(all(ans));
    cout<<dp[n][m]<<endl;
    for(auto it : ans) cout<<it<<" ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}