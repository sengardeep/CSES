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
    stack<int> stack;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        while(!stack.empty() && v[stack.top()-1]>=v[i]) stack.pop();
        if(!stack.empty()) ans[i]=stack.top();
        stack.push(i+1);
    }
    for(auto it : ans) cout<<it<<" ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}