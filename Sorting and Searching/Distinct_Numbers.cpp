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
    set<int> st;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size();
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}