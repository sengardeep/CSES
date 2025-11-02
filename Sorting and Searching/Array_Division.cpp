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
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int start=*max_element(all(v)),end=accumulate(all(v),0LL);
    auto check=[&](int x){
        int count=0,sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum+v[i]>x){
                count++;
                sum=0;
            }
            sum+=v[i];
        }
        if(sum) count++;
        return count<=k;
    };
    int ans=end;
    while(start<=end){
        int mid=end+(start-end)/2;
        if(check(mid))
        {
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