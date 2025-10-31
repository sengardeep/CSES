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
    for(int i=0;i<n;i++)  cin>>v[i];
    sort(all(v));
    int sum=0;
    for(int i=0;i+1<n;i++) sum+=v[i];
    if(sum<v[n-1]) cout<<2*v[n-1];
    else cout<<sum+v[n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}