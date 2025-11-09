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
    int n;
    cin>>n;
    vector<pii> v(n);
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        v[i]={x,i};
    }
    vector<int> ngl(n,-1),ngr(n,n);  //Next greater left and right
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && v[st.top()].first<v[i].first) st.pop();
        if(!st.empty()) ngl[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && v[st.top()].first<v[i].first) st.pop();
        if(!st.empty()) ngr[i]=st.top();
        st.push(i);
    }
    sort(all(v));
    vector<int> dp(n,1); //dp[i] : maximum possible mountain climb if starts from i
    //Transition will be look like dp[i]=1+max(dp[Li+1]...dp[Ri-1]) where Li will be ngl[i] & Ri will be ngr[i]
    vector<int> segTree(4*n,0);
    auto merge=[](int a,int b)->int{
        return max(a,b);
    };
    function<void(int,int,int)>  build=[&](int start,int end,int index)->void{
        if(start==end){
            segTree[index]=dp[start];
            return;
        }
        int mid=(start+end)/2;
        build(start,mid,2*index);
        build(mid+1,end,2*index+1);
        segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
    };
    function<void(int,int,int,int,int)>  update=[&](int start,int end,int index,int k,int val)->void{
        if(start==end){
            segTree[index]=val;
            return;
        }
        int mid=(start+end)/2;
        if(k<=mid)
        update(start,mid,2*index,k,val);
        else
        update(mid+1,end,2*index+1,k,val);
        segTree[index]=merge(segTree[2*index],segTree[2*index+1]);
    };
    function<int(int,int,int,int,int)> query=[&](int start,int end,int index,int l,int r)->int{
        if(start>=l && end<=r) return segTree[index];
        if(start>r || end<l) return 0;
        int mid=(start+end)/2;
        int left=query(start,mid,2*index,l,r);
        int right=query(mid+1,end,2*index+1,l,r);
        return max(left,right);
    };
    build(0,n-1,1);
    for(int i=0;i<n;i++){
        auto [val,index]=v[i];
        int l=ngl[index],r=ngr[index];
        ++l;
        --r;
        if(l>=r) dp[index]=1;
        else dp[index]=1+query(0,n-1,1,l,r);
        update(0,n-1,1,index,dp[index]);
    }
    int ans=*max_element(all(dp));
    cout<<ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}