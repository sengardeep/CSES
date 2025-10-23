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
    int n,s;
    cin>>n>>s;
    vector<pii> v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.pb({x,i+1});
    }
    sort(all(v));
    int i=0,j=n-1;
    while(i<j){
        int sum=v[i].first+v[j].first;
        if(sum==s){
            cout<<v[i].second<<" "<<v[j].second;
            return;
        }
        if(sum<s){
            i++;
        }else{
            j--;
        }
    }
    cout<<"IMPOSSIBLE";
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}