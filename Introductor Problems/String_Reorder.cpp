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
    map<char,int> freq;
    for(auto c : s) freq[c]++;
 
    string ans="";
    int n = (int)s.size();
    for(int pos=0; pos<n; ++pos){
        char prev = ans.empty() ? '\0' : ans.back();
        bool placed = false;
        for(auto &kv : freq){
            char ch = kv.first;
            int &f = kv.second;
            if(f==0) continue;
            if(ch == prev) continue;
            f--;
            int rem = n - (int)ans.size() - 1;
            int mx = 0;
            for(auto &q : freq) mx = max(mx, q.second);
            if(mx <= (rem + 1) / 2){
                ans += ch;
                placed = true;
                break;
            }
            f++;
        }
        if(!placed){
            cout << -1;
            return;
        }
    }
    cout << ans;
}
 
#undef int
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    solve();
    return 0;
}
