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
    function<vector<string>(int n)> helper = [&](int n)->vector<string>{
        if(n==1) return {"0","1"};
        vector<string> a=helper(n-1);
        vector<string> b=a;
        for(auto &c : a) c+='0';
        reverse(begin(b),end(b));
        for(auto &c : b) c+='1';
        a.insert(a.end(),b.begin(),b.end());
        return a;
    };
    vector<string> ans=helper(n);
    for(auto it : ans) cout<<it<<endl;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}