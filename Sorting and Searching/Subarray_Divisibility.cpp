#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define dbg(x) cerr<<#x<<" = "<<x<<endl;

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    map<int,int> map;
    map[0]=1;
    int sum=0,ans=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        int mod = ((sum%n)+n)%n;
        ans+=map[mod];
        map[mod]++;
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}