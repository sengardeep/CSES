#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

int f(string s){
    vector<vector<vector<vector<int>>>> dp(s.size(),vector<vector<vector<int>>>(11,vector<vector<int>>(2,vector<int>(2,-1))));
    function<int(int,int,int,int)> helper=[&](int index,int last,int isTight,int flag)->int{
        if(index==s.size()) return 1;
        if(dp[index][last][isTight][flag] != -1) return dp[index][last][isTight][flag];
        int ans=0;
        for(int d=0;d<=(isTight?(s[index]-'0'):9);d++){
            if (flag == 0 && d == last) continue; 
            ans+=helper(index+1,d,(isTight && d==(s[index]-'0')),(flag && d==0));
        }
        return dp[index][last][isTight][flag]=ans;
    };
    return helper(0,10,1,1);
}
void solve() {
    string a,b;
    cin>>a>>b;
    int ans1=f(b);
    int x=stoll(a);
    x--;
    if(x>=0){
        a=to_string(x);
        int ans2=f(a);
        ans1-=ans2;
    }
    cout<<ans1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}