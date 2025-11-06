#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

const int N=5005;
int dp[N][N];

void solve() {
    string s,t;
    cin>>s>>t;
    for(int i=0;i<=s.size();i++) dp[i][0]=i;
    for(int i=0;i<=t.size();i++) dp[0][i]=i;
    for(int i=1;i<=s.size();i++){
        for(int j=1;j<=t.size();j++){
            dp[i][j]=min({dp[i-1][j-1]+(s[i-1]!=t[j-1]),dp[i-1][j]+1,dp[i][j-1]+1});
        }
    }
    cout<<dp[s.size()][t.size()];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}