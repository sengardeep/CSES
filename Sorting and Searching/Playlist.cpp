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
    set<int> set;
    int ans=0;
    int start=0,end=0;
    while(end<n){
        while(set.count(v[end])){
            set.erase(v[start]);
            start++;
        }
        set.insert(v[end]);
        ans=max(ans,end-start+1);
        end++;
    }
    cout<<ans;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}