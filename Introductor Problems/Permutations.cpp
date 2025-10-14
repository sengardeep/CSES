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
    if(n==2 || n==3){
        cout<<"NO SOLUTION";
        return;
    }
    cout<<(n/2)+1<<" ";
    int l=1,r=n;
    int steps=n-1;
    while (steps)
    {
        cout<<l++<<" ";
        steps--;
        if(!steps) return;
        cout<<r--<<" ";
        steps--;
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}