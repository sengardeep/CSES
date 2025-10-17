#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {
    vector<string> v(8);
    for(int i=0;i<8;i++) cin>>v[i];
    long long cnt[8][8] = {};
    auto push = [&](int r,int c)->void{
        for(int i=c+1;i<8;i++) cnt[r][i]++;
        int i=r,j=c;
        while(i>=0&&j<8) { cnt[i][j]++; i--; j++; }
        i=r; j=c;
        while(i<8&&j<8){ cnt[i][j]++; i++; j++; }
    };
    auto undo = [&](int r,int c)->void{
        for(int i=c+1;i<8;i++) cnt[r][i]--;
        int i=r,j=c;
        while(i>=0&&j<8) { cnt[i][j]--; i--; j++; }
        i=r; j=c;
        while(i<8&&j<8){ cnt[i][j]--; i++; j++; }
    };
    function<int(int,int)> helper=[&](int r,int c)->int{
        if(v[r][c]=='*' || cnt[r][c]>0) return 0;
        if(c==7) return 1;
        push(r,c);
        int ans=0;
        for(int i=0;i<8;i++){
            ans += helper(i,c+1);
        }
        undo(r,c);
        return ans;
    };
    int ans=0;
    for(int i=0;i<8;i++) ans += helper(i,0);
    cout<<ans;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}