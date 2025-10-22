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
    int n,m;
    cin>>n>>m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            set<char> st;
            int flag=false;
            if(i!=0) st.insert(v[i-1][j]);
            if(j!=0) st.insert(v[i][j-1]);
            st.insert(v[i][j]);
            for(char c='A';c<='D';c++){
                if(!st.count(c)){
                    v[i][j]=c;
                    flag=1;
                    break;
                }
            }
            if(!flag) {
                cout<<"IMPOSSIBLE";
                return;
            }
        }
    }
    for(auto it : v) cout<<it<<endl;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}