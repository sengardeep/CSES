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
    int q;
    cin>>q;
    function<int(int,int)> find=[&](int n,int k)->int{
        if(n==1) return 1;
        if(k<=(n+1)/2){
            if(2*k>n) return (2*k)%n;
            return 2*k;
        }
        int x=find(n/2,k-(n+1)/2);
        if(n%2) return 2*x+1;
        else return 2*x-1;
    };
    while(q--){
        int n,k;
        cin>>n>>k;
        cout<<find(n,k)<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}