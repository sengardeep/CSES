#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
#define endl "\n"
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define pii pair<int,int>
#define pb push_back

void solve() {
   int k;
   cin>>k;
   int cnt=9,len=1;
   int skipped=0;
   while(true){
    if(k>len*cnt){
        k-=len*cnt;
        skipped+=cnt;
    }
    else{
        int skip=(k-1)/len;
        skipped+=skip;
        k-=skip*len;
        int ans=skipped+1;
        cout<<to_string(ans)[k-1]<<endl;
        return;
    }
    len++;
    cnt*=10;
   }
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
