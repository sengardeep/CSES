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
    using T=tuple<int,int,int>;
    vector<T> v(n);
    for(int i=0;i<n;i++) 
    {
        int x,y;
        cin>>x>>y;
        v[i]={x,y,i};
    }
    sort(all(v));
    vector<int> ans(n);
    int x=1;
    priority_queue<pii,vector<pii>,greater<pii>> pq; //end,val
    for(auto [s,e,index] : v){
        if(!pq.empty() && pq.top().first < s){
            auto [end,val]=pq.top();
            pq.pop();
            ans[index]=val;
            pq.push({e,val});
        }else{
            ans[index]=x;
            pq.push({e,x});
            x++;
        }
    }
    cout<<x-1<<endl;
    for(auto it : ans) cout<<it<<" ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}