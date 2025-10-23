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
    vector<int> map(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        map[x]=i;
    }
    vector<int> count(n+1,0);
    for(int i=1;i<n;i++){
        if(map[i]>map[i+1]) count[i]++;
    }
    int ans=accumulate(all(count),1LL);
    cout<<ans;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}