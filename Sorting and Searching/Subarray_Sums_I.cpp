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
    int n,s;
    cin>>n>>s;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    map<int,int> map;
    map[0]=1;
    int sum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(map.count(sum-s)) ans+=map[sum-s];
        map[sum]++;
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}