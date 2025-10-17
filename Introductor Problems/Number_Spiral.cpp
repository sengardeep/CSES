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
    int y,x;
    cin>>y>>x;
    if(y>=x){
        if(y%2){
            int num=(y-1)*(y-1);
            cout<<num+x<<endl;
        }
        else{
            int num=y*y+1;
            cout<<num-x<<endl;
        }
    }
    else{
        if(x%2){
            int num=x*x+1;
            cout<<num-y<<endl;
        }
        else{
            int num=(x-1)*(x-1);
            cout<<num+y<<endl;
        }
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    solve();
    return 0;
}