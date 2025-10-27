#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin>>n;
    vector<pii> v(n);
    map<pii,int> map;
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
        map[v[i]]=i;
    }
    sort(all(v),[&](pii &a,pii &b){return (a.first!=b.first)?(a.first<b.first):(a.second>b.second);});
    vector<int> ans1(n),ans2(n);
    ordered_multiset<int> ms;
    for(int i=n-1;i>=0;i--){
        auto [s,e] = v[i];
        ans1[map[v[i]]]=ms.order_of_key(e+1);
        ms.insert(e);
    }
    for(auto it : ans1) cout<<it<<" ";
    cout<<"\n";
    ms.clear();
    for(int i=0;i<n;i++){
        auto [s,e] = v[i];
        ans2[map[v[i]]] = (int)ms.size() - ms.order_of_key(e);
        ms.insert(e);
    }
    for(auto it : ans2) cout<<it<<" ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}