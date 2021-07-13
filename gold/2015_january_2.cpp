/*
	Author : inluminas
	Problem: Moovie Mooving
*/
#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
#define fastio ios_base::sync_with_stdio(false)
#define endl "\n"

const int lmt=(1<<20)+1;
ll dp[lmt],d[21];
vector<ll>c[21];

int bs(ll val,int id){
	int lo=0,hi=c[id].size()-1;
	while(hi-lo>1){
		int mid=(lo+hi)>>1;
		if(c[id][mid]<=val) lo=mid;
		else hi=mid;
	}
	if(c[id][hi]<=val) return c[id][hi];
	else return c[id][lo];
}

ll btnct(ll v){
	ll cnt=0;
	for(int i=0;i<20;i++){
		if(v&(1<<i)) cnt++;
	}
	return cnt;
}

int main(){
	fastio;

	//freopen("movie.in","r",stdin);
	//freopen("movie.out","w",stdout);

	ll n,L;
	cin>>n>>L;
	for(int i=0;i<lmt;i++){
		dp[i]=-1;
	}
	for(int i=1;i<=n;i++){
		cin>>d[i];
		int m;
		cin>>m;
		while(m--){
			ll s;
			cin>>s;
			c[i].push_back(s);
			if(s) continue;
			dp[(1<<(i-1))]=d[i];
		}
	}

	ll ans=1e18;

	for(ll mask=1;mask<(1<<n);mask++){
		if(dp[mask]==-1) continue;
		for(int i=0;i<n;i++){
			if(mask&(1<<i)) continue;

			ll v=mask+(1<<i);
			int indx=bs(dp[mask],i+1);
			if(indx>dp[mask]) continue;
			dp[v]=max(dp[v],max(dp[mask],indx+d[i+1]));
		}
	}

	for(int i=1;i<(1<<n);i++){
		if(dp[i]<L) continue;
		ans=min(ans,btnct(i));
	}

	if(ans==1e18) ans=-1;
	cout<<ans<<endl;
	return 0;

	return 0;
} 
