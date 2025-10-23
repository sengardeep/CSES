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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(all(a));
    sort(all(b));
    int i=0,j=0,ans=0;
    while(i<n&&j<m){
        if(abs(a[i]-b[j])<=k){
            ans++;
            i++;
            j++;
        }
        else{
           if(a[i]>b[j]) j++;
           else i++;
        }
    }
    cout<<ans;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}