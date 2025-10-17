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
    vector<pii> ans;
    function<void(int,int,int,int)> helper=[&](int s,int m,int e,int n)->void{
        if(n==1){
            ans.pb({s,e});
            return;
        }
        helper(s,e,m,n-1);
        helper(s,m,e,1);
        helper(m,s,e,n-1);
    };
    helper(1,2,3,n);
    cout<<ans.size()<<endl;
    for(auto [a,b] : ans) cout<<a<<" "<<b<<endl;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}