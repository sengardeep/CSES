#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;

void solve() {
    int n;
    cin>>n;
    auto binexp = [](int base,int exp){
      int ans=1;
      while(exp){
        if(exp&1) ans = (ans*base)%mod;
        base = (base*base)%mod;
        exp>>=1;
      }  
      return ans;
    };
    cout<<binexp(2,n);
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}