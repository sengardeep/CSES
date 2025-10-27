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
    map<pii,int> map;
    vector<pii> v(n);
    for(int i=0;i<n;i++) 
    {
        cin>>v[i].first>>v[i].second;
        map[v[i]]=i;
    }
    sort(all(v),[&](pii &a,pii &b){return (a.first!=b.first)?(a.first<b.first):(a.second>b.second);});
    vector<int> ans1(n);
    multiset<int> ends;
    for(int i=0;i<n;i++){
        auto [s,e]=v[i];
        auto lb=ends.lower_bound(e);
        if(lb!=ends.end()) ans1[map[v[i]]]^=1;
        ends.insert(e);
    }
    ends.clear();
    vector<int> ans2(n);
    for(int i=n-1;i>=0;i--){
        auto [s,e]=v[i];
        if(!ends.empty() && e>=*ends.begin()) ans2[map[v[i]]]^=1;
        ends.insert(e);
    }
    for(auto it : ans2) cout<<it<<" ";
    cout<<endl;
    for(auto it : ans1) cout<<it<<" ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}