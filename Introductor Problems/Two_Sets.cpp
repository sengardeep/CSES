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
    int sum = n*(n+1)/2;
    if(sum%2) cout<<"NO";
    else{
        cout<<"YES"<<endl;
        int target=sum/2;
        multiset<int> st1;
        set<int> st2;
        for(int i=1;i<=n;i++) st1.insert(i);
        while(target){
            auto it = st1.upper_bound(target);
            if(it != st1.begin()) {
                --it;
                int lb = *it;
                st2.insert(lb);
                st1.erase(it);
                target -= lb;
            } else {
                break;
            }
        }
        cout<<st1.size()<<endl;
        for(auto x:st1) cout<<x<<" ";
        cout<<endl;
        cout<<st2.size()<<endl;
        for(auto x:st2) cout<<x<<" ";
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}