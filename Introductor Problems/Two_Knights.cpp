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
    for(int i=1;i<=n;i++){
        int size=i*i;
        int total = size*(size-1)/2;
        int bad = 0;
        bad += 8*(i-4)*(i-4);
        bad += 6*(i-4)*4;
        bad += 4*(i-3)*4;
        bad += 3*8;
        bad += 2*4;
        bad/=2;
        cout<<total-bad<<endl;
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}