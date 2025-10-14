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
    string s;
    cin>>s;
    int ans=1;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            int j=i+1;
            while(j<s.size()&&s[i]==s[j]) j++;
            j--;
            ans=max(ans,j-i+1);
            i=j;
        }
    }
    cout<<ans;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}