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
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(all(v));
    int sum=accumulate(all(v),0LL);
    vector<int> dp(sum+1,0);
    dp[0]=1;
    vector<int> temp;
    for(int i=0;i<n;i++){
        temp.clear();
        for(int j=v[i];j<=sum;j++){
            if(dp[j-v[i]]) temp.pb(j);
        }
        for(auto it : temp) dp[it]++;
    }
    vector<int> ans;
    for(int i=1;i<=sum;i++) if(dp[i]) ans.pb(i);
    cout<<ans.size()<<endl;
    for(auto x : ans) cout<<x<<" ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}