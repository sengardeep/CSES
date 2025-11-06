#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

const int N=1e6+5;
const int mod=1e9+7;
vector<vector<int>> dp(N,vector<int>(8,0));
void solve() {
    int n;
    cin>>n;
    cout<<(dp[n-1][2]+dp[n-1][6])%mod<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<8;i++) dp[0][i]=1;
    for(int i=1;i<N;i++){
        for(int j=0;j<8;j++){
            //Bottom part on
            if(j==0 || j==2 || j==3 || j==4 || j==5) {
                //Add those states having top part on
                dp[i][j]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][3]+dp[i-1][4]+dp[i-1][5])%mod;
            }
            //Bottom part off
            else{
                //Add those having top part off
                dp[i][j]=(dp[i-1][2]+dp[i-1][6]+dp[i-1][7])%mod;
            }
        }
    }
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}