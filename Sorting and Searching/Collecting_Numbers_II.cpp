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
    int n,m;
    cin>>n>>m;
    vector<int> map(n+1);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        v[i]=x;
        map[x]=i;
    }
    vector<int> count(n+1,0);
    for(int i=1;i<n;i++){
        if(map[i]>map[i+1]) count[i]++;
    }
    int ans=accumulate(all(count),1LL);
    while(m--){
        int i,j;
        cin>>i>>j;
        if(i==j){
            cout<<ans<<endl;
            continue;
        }
        int a = v[i], b = v[j];
        
        vector<int> keys;
        auto add_key = [&](int k){
            if(k >= 1 && k < n) keys.push_back(k);
        };
        add_key(a-1);
        add_key(a);
        add_key(b-1);
        add_key(b);
        sort(keys.begin(), keys.end());
        keys.erase(unique(keys.begin(), keys.end()), keys.end());
        
        for(int k : keys) ans -= count[k];
        
        swap(v[i], v[j]);
        map[a] = j;
        map[b] = i;
        
        for(int k : keys){
            count[k] = (map[k] > map[k+1]);
            ans += count[k];
        }
        
        cout<<ans<<endl;
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}