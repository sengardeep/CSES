#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
const int INF = 1e18;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> ans(n,vi(n,INF));
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    ans[0][0]=0;
    queue<pii> q;
    q.push({0,0});
    vis[0][0]=true;
    auto isValid=[&](int r,int c)->bool{
        return (r>=0&&r<n&&c>=0&&c<n);
    };
    pii dir[8]={{2,1},{-2,1},{2,-1},{1,2},{-1,2},{1,-2},{-1,-2},{-2,-1}};
    while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int row=r+dir[i].first,col=c+dir[i].second;
            if(isValid(row,col) && !vis[row][col]){
                ans[row][col]=min(ans[r][c]+1,ans[row][col]);
                vis[row][col]=true;
                q.push({row,col});
            }
        }
    }
    for(auto it : ans) {
        for(auto x : it) cout<<x<<" ";
        cout<<endl;
    }

}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}