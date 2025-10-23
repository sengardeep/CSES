#include <bits/stdc++.h>
using namespace std;
#define int long long
int calc(int n) {return n*(n+1)/2;}
signed main() {
	int t=1;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
		}
		map<int,int> map;
		int start=0,end=0,mid=-1;
		int ans=0;
		while(end<n)
		{
			if(map[v[end]] > 0)
			{
				int curr=(end-1)-start+1;
				ans += calc(curr);
				curr = mid-start+1;
				ans -= calc(curr);
				mid = end-1;
				while(map[v[end]] != 0 && start <= end)
				{
					map[v[start]]--;
					start++;
				}
			}
			map[v[end]]++;
			end++;
		}
		int curr=(end-1)-start+1;
		ans += calc(curr);
		curr = mid-start+1;
		ans -= calc(curr);
		cout<<ans;
	}
 
}