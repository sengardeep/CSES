#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

const int N=1e6+5;
void solve() {
    vector<int> divs(N, 0);
    for(int i=1; i<N; i++){
        for(int j=i; j<N; j+=i) divs[j]++;
    }
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        cout<<divs[n]<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}