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
    string s;
    cin>>s;
    int n=s.size();
    set<string> ans;
    function<void(int,string)> helper=[&](int idx,string s)->void{
        if(idx==n-1) {
            ans.insert(s);
            return;
        }
        for(int i=idx;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(s[i],s[j]);
                helper(i+1,s);
                swap(s[i],s[j]);
                helper(i+1,s);
            }
        }
    };
    helper(0,s);
    cout<<ans.size()<<endl;
    for(auto a : ans) cout<<a<<endl;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}