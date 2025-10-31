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
    vector<int> st(4*n),lazy(4*n,0);
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
    auto propogate=[&](int start,int end,int index){
        if(start==end) {
            lazy[index]=0;
            return;
        }
        lazy[2*index]+=lazy[index];
        lazy[2*index+1]+=lazy[index];
        lazy[index]=0;
        return;
    };
    function<void(int,int,int,int,int,int)> update=[&](int start,int end,int index,int l,int r,int val)->void{
        if(lazy[index]){
            st[index]+=(end-start+1)*lazy[index];
            propogate(start,end,index);
        }
        if(l>end||r<start) return;
        if(start>=l&&end<=r){
            lazy[index]=val;
            st[index]+=(end-start+1)*lazy[index];
            propogate(start,end,index);
            return;
        }
        int mid=(start+end)/2;
        update(start,mid,2*index,l,r,val);
        update(mid+1,end,2*index+1,l,r,val);
        st[index]=merge(st[2*index],st[2*index+1]);
    };
    function<int(int,int,int,int)> query=[&](int start,int end,int index,int k)->int{
        if(lazy[index]){
            st[index]+=(end-start+1)*lazy[index];
            propogate(start,end,index);
        }
        if(start==end) return st[index];
        int mid=(start+end)/2;
        if(mid>=k) return query(start,mid,2*index,k);
        else return query(mid+1,end,2*index+1,k);
    };
    build(0,n-1,1);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r,k;
            cin>>l>>r>>k;
            --l;
            --r;
            update(0,n-1,1,l,r,k);
        }else{
            int k;
            cin>>k;
            --k;
            cout<<query(0,n-1,1,k)<<endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}