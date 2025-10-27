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
    int n,q;
    cin>>n>>q;
    set<int> lights{0,n};
    multiset<int> dist{n};
    while(q--){
        int x;
        cin>>x;
        auto it1 = lights.upper_bound(x);
        auto it2=it1;
        it1--;
        dist.erase(dist.find(*it2-*it1));
        dist.insert(*it2-x);
        dist.insert(x-*it1);
        lights.insert(x);
        cout<<*dist.rbegin()<<" ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}