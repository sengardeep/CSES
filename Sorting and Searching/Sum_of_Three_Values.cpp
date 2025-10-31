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
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v[i]={x,i+1};
    }
    sort(all(v));
    for(int i=0;i<n-2;i++){
        auto [num,idx]=v[i];
        int l=i+1,r=n-1,target=s-num;
        while(l<r){
            int sum=v[l].first+v[r].first;
            if(sum<target) l++;
            else if(sum>target) r--;
            else{
                cout<<idx<<" "<<v[l].second<<" "<<v[r].second;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}