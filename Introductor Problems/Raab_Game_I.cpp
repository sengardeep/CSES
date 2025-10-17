#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int n,a,b;
   cin>>n>>a>>b;
   int m=a+b;
   if(m>n || (a && !b) || (b && !a)){
    cout<<"NO"<<endl;
    return;
   }
   vector<int> p(n);
   iota(begin(p),end(p),1);
   cout<<"YES"<<endl;
   for(auto it : p) cout<<it<<" ";
   cout<<endl;
   reverse(begin(p),begin(p)+a);
   reverse(begin(p)+a,begin(p)+m);
   reverse(begin(p),begin(p)+m);
   for(auto it : p) cout<<it<<" ";
   cout<<endl;
}

int32_t main(){
   ios::sync_with_stdio(0);
   cin.tie(0);

   #ifdef LOCAL
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif

   int t=1;
   cin>>t;
   while(t--){
       solve();
   }

   return 0;
}
