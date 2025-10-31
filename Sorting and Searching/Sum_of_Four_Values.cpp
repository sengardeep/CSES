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
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++)
        {
            int target=s-(v[i].first+v[j].first);
            int l=j+1,r=n-1;
            while(l<r){
                int sum=v[l].first+v[r].first;
                if(sum<target) l++;
                else if(sum>target) r--;
                else{
                    cout<<v[i].second<<" "<<v[j].second<<" "<<v[l].second<<" "<<v[r].second;
                    return;
                }
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