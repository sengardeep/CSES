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
    int n,t;
    cin>>n>>t;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int start=0,end=(*min_element(all(v)))*t,ans=0;
    while(start<=end){
        int mid=end+(start-end)/2;
        auto check=[&](){
            int cnt=0;
            for(int i=0;i<n;i++) cnt+=(mid/v[i]);
            return cnt>=t;
        };
        if(check()){
            ans=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}