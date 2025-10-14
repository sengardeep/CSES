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
    while(true){
        cout<<n<<" ";
        if(n==1) break;
        if(n%2) n=n*3+1;
        else n/=2;
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}