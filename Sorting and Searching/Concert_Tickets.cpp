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
    vi b(m);
    multiset<int> ms;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ms.insert(x);
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
        if(ms.empty()){
            cout<<-1<<endl;
            continue;
        }
        auto it=ms.upper_bound(b[i]);
        if(it==ms.begin()){
            cout<<-1<<endl;
        }
        else{
            --it;
            cout<<*it<<endl;
            ms.erase(it);
        }
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}