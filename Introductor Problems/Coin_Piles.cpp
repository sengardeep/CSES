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
    int a,b;
    cin>>a>>b;
    int diff=abs(a-b);
    if(diff>min(a,b) || (a+b)%3) cout<<"NO";
    else cout<<"YES";
    cout<<endl;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}