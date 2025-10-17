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
    int sum=0;
    for(int i=0;i<n;i++) 
    {
        cin>>v[i];
        sum+=v[i];
    }
    function<int(int,int)> helper=[&](int idx,int s)->int{
        if(idx==n) return abs(sum-2*s);
        int skip = helper(idx+1,s);
        int take = helper(idx+1,s+v[idx]);
        return min(take,skip);
    };
    cout<<helper(0,0);
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}