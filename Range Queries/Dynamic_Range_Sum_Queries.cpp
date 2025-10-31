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
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> st(4*n);
    auto merge=[](int a,int b){return a+b;};
    function<void(int,int,int)> build=[&](int start,int end,int index)->void{
        if(start==end) {
            st[index]=v[start];
            return;
        }
        int mid=(start+end)/2;
        build(start,mid,2*index);
        build(mid+1,end,2*index+1);
        st[index]=merge(st[2*index],st[2*index+1]);
    };
    function<void(int,int,int,int,int)> update=[&](int start,int end,int index,int k,int val)->void{
        if(start==end){
            st[index]=val;
            return;
        }
        int mid=(start+end)/2;
        if(k<=mid){
            update(start,mid,2*index,k,val);
        }else{
            update(mid+1,end,2*index+1,k,val);
        }
        st[index]=merge(st[2*index],st[2*index+1]);
    };
    function<int(int,int,int,int,int)> query=[&](int start,int end,int index,int l,int r)->int{
        if(start>=l&&end<=r) return st[index];
        if(start>r||end<l) return 0;
        int mid=(start+end)/2;
        int left=query(start,mid,2*index,l,r);
        int right=query(mid+1,end,2*index+1,l,r);
        return left+right;
    };
    build(0,n-1,1);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int k,val;
            cin>>k>>val;
            --k;
            update(0,n-1,1,k,val);
        }else{
            int l,r;
            cin>>l>>r;
            --l;
            --r;
            cout<<query(0,n-1,1,l,r)<<endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}