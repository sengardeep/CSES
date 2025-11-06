#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define inf 1e9

void solve() {
    int a,b;
    cin>>a>>b;
    vector<vector<int>> dp(a+1,vector<int>(b+1,inf));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j) dp[i][j]=0;
            else{
                for(int k=1;k<=i/2;k++){
                    dp[i][j]=min({dp[i][j],1+dp[k][j]+dp[i-k][j]});
                }
                for(int k=1;k<=j/2;k++){
                    dp[i][j]=min({dp[i][j],1+dp[i][k]+dp[i][j-k]});
                }
            }
        }
    }
    cout<<dp[a][b];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}