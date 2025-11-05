#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<long long>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin>>n;
    vector<pii> v(n);
    for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second;
    const int mod=1e9+7;
    auto binPow = [&](int a,int b,int m){
        int ans=1 % m;
        a%=m;
        while(b){
            if(b&1) ans=(ans*1LL*a)%m;
            a=(a*1LL*a)%m;
            b>>=1;
        }
        return ans;
    };
    // number of divisors and D modulo (mod-1)
    int numDiv=1;
    int Dmod=1; // modulo (mod-1)
    bool allEven=true;
    for(auto [p,a] : v){
        numDiv = (numDiv*1LL*(a+1))%mod;
        Dmod = (Dmod*1LL*((a+1)%(mod-1)))%(mod-1);
        if(a&1) allEven=false;
    }
    cout<<numDiv<<" ";
    // sum of divisors
    int sumDiv=1;
    for(auto [p,a] : v){
        int x=(binPow(p,a+1,mod)-1+mod)%mod;
        int den=(p-1+mod)%mod;
        int mul=(x*1LL*binPow(den,mod-2,mod))%mod;
        sumDiv = (sumDiv*1LL*mul)%mod;
    }
    cout<<sumDiv<<" "; 
    // product of divisors
    int prodDiv=1;
    if(!allEven){
        int halfD=1;
        bool halved=false;
        for(auto [p,a] : v){
            int term=a+1;
            if(!halved && (term%2==0)){
                term/=2;
                halved=true;
            }
            halfD = (halfD*1LL*(term%(mod-1)))%(mod-1);
        }
        for(auto [p,a] : v){
            int exp = ((a%(mod-1))*1LL*halfD)%(mod-1);
            prodDiv = (prodDiv*1LL*binPow(p,exp,mod))%mod;
        }
    }else{
        for(auto [p,a] : v){
            int exp = (((a/2)%(mod-1))*1LL*Dmod)%(mod-1);
            prodDiv = (prodDiv*1LL*binPow(p,exp,mod))%mod;
        }
    }
    cout<<prodDiv;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}