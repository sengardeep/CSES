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
    map<char,int> map;
    for(auto c : s) map[c]++;
    int flag=0;
    for(auto [c,f] : map){
        if(f%2)
        {
            if(flag) 
            {
                cout<<"NO SOLUTION";
                return;
            }
            else flag=1;
        }
    }
    int n=s.size();
    int i=0,j=n-1;
    for(auto [c,f] : map){
        if(f%2) 
        {
            s[n/2]=c;
            f--;
        }
        while(f){
            s[i++]=s[j--]=c;
            f-=2;
        }
    }
    cout<<s;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}