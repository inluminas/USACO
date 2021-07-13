/*
	Author : inluminas
	Problem: Guard Mark
*/
#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
#define fastio ios_base::sync_with_stdio(false)
#define endl "\n"
 
struct cow{
	ll height=0,weight=0,strength=0;
};
const ll inf=1e18;
const int lmt=(1<<20)+2;
ll dp[lmt],weight[lmt],height[lmt];

int main(){
	fastio;

	//freopen("guard.in","r",stdin);
	//freopen("guard.out","w",stdout);

	int n,h;
	cin>>n>>h;
	cow a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].height>>a[i].weight>>a[i].strength;
	}
	for(int i=0;i<(1<<n);i++){
		dp[i]=-inf;
		for(int j=0;j<n;j++){
			if(i&(1<<j)) weight[i]+=a[j].weight;
			if(i&(1<<j)) height[i]+=a[j].height;
		}
	}
	ll ans=-1;
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i&(1<<j)) continue;
			int id=i|(1<<j);
			if(dp[i]==-inf) dp[i]=inf;
			dp[id]=max(dp[id],max(min(dp[i]-a[j].weight,a[j].strength),min(a[j].strength-weight[i],dp[i])));
			if(height[id]>=h) ans=max(ans,dp[id]);
		}
	}
	if(ans==-1) cout<<"Mark is too tall"<<endl;
	else cout<<ans<<endl;

	return 0;
} 
