/*
	Author : inluminas
	Problem: Moo Network
*/
#include"bits/stdc++.h"
using namespace std;

#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define inf LLONG_MAX

const ll lmt=1e5+10;
vector<pair<ll,ll>>adj[11];
ll par[lmt];

ll findpar(ll u){
	if(par[u]==u) return u;
	return par[u]=findpar(par[u]);
}

int main(){
	fastio;

	ll n;
	cin>>n;
	ll x[n+1];
	for(ll i=1;i<=n;i++){
		ll y;
		cin>>x[i]>>y;
		adj[y].push_back({x[i],i});
	}

	for(ll i=0;i<=10;i++) sort(adj[i].begin(),adj[i].end());

	vector<array<ll,3>>e;

	for(ll i=0;i<=10;i++){
		for(ll j=1;j<adj[i].size();j++){
			ll val=(adj[i][j].first-adj[i][j-1].first)*(adj[i][j].first-adj[i][j-1].first);
			e.push_back({val,adj[i][j].second,adj[i][j-1].second});
		}
	}

	for(ll i=0;i<=10;i++){
		if(adj[i].empty()) continue;
		for(ll j=0;j<=10;j++){
			if(i==j || adj[j].empty()) continue;

			for(auto [x,idx]:adj[i]){

				ll lo=0,hi=adj[j].size()-1;
				while(hi-lo>1){
					ll mid=(lo+hi)>>1;
					if(adj[j][mid].first<x) lo=mid;
					else hi=mid;
				}
	
				ll id=-1;

				if(adj[j][hi].first<x) id=hi;
				else if(adj[j][lo].first<x) id=lo;

				int cnt=0;

				for(ll id2=max(0LL,id);id2<adj[j].size();id2++,cnt++){
					ll val=(x-adj[j][id2].first)*(x-adj[j][id2].first);
					val+=(i-j)*(i-j);
					e.push_back({val,idx,adj[j][id2].second});
					if(cnt==2) break;
				} 
			}
		}
	}

	sort(e.begin(),e.end());

	for(ll i=1;i<=n;i++) par[i]=i;

	ll ans=0;

	for(auto x:e){
		ll val=x[0],i=x[1],j=x[2];

		ll i2=findpar(i),j2=findpar(j);
		if(i2==j2) continue;

		ans+=val;

		par[i2]=j2;
	}

	cout<<ans<<endl;
	return 0;
}
