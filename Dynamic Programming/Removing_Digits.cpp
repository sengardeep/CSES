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
    vector<int> dp(n+1,1e9);
    for(int i=0;i<10;i++) dp[i]=1;
    for(int i=10;i<=n;i++){
        string temp=to_string(i);
        for(auto c : temp){
            dp[i]=min(dp[i],1+dp[i-(c-'0')]);
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