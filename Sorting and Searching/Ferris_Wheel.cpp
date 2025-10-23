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
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(all(v));
    int ans=0;
    int i=0,j=n-1;
    while(i<=j){
        if(v[i]+v[j]<=x) {
            i++;
            j--;
        }else j--;
        ans++;
    }
    cout<<ans;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}