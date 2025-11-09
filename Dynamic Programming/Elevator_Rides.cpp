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
    int n,w;
    cin>>n>>w;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<pii> dp((1<<n) , {1e9,1e9}); //dp[mask] = {number of rides,space taken by last ride}
    dp[0]={1,0};
    for(int mask=1;mask<(1<<n);mask++){
        for(int bit=0;bit<n;bit++){
            if((1<<bit)&mask){
                int space=w-dp[mask^(1<<bit)].second;
                if(space >= v[bit]){
                    dp[mask]=min(dp[mask],{dp[mask^(1<<bit)].first,dp[mask^(1<<bit)].second+v[bit]});
                }
                else dp[mask]=min(dp[mask],{dp[mask^(1<<bit)].first+1,v[bit]});
            }
        }
    }
    cout<<dp[(1<<n)-1].first;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}