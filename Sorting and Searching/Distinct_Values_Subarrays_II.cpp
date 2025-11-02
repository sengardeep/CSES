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
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int ans=0;
    int j=0;
    map<int,int> map;
    for(int i=0;i<n;i++){
        while (j < n && ((int)map.size() < k || map.count(v[j]))) map[v[j++]]++;
        ans+=j-i;
        map[v[i]]--;
        if(map[v[i]]==0) map.erase(v[i]);
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}