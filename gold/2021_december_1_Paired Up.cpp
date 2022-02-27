/*
  Author : Pranshu
  Problem: Paired Up
*/
#include"bits/stdc++.h"
using namespace std;

#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define inf LLONG_MAX

ll MN(vector<array<ll,2>>a,ll k){
  ll res=inf;
  for(int i=0;i<a.size();i++){
    if(!(i&1) || a[i-1][0]+k>=a[i+1][0]){
      res=min(res,a[i][1]);
    }
  }
  return res;
}

ll MX(vector<array<ll,2>>a,ll k){
  ll n=a.size();
  if(!n) return 0LL;
  array<ll,2>dp[n+1];
  dp[0][0]=0,dp[0][1]=-inf;

  for(int i=1;i<=n;i++){
    int lo=1,hi=i;
    while(hi-lo>1){
      int mid=(lo+hi)>>1;
      if(a[mid-1][0]+k>=a[i-1][0]) hi=mid;
      else lo=mid;
    }
    int last=0;
    if(a[hi-1][0]+k<a[i-1][0]) last=hi;
    else if(a[lo-1][0]+k<a[i-1][0]) last=lo;

    dp[i]=dp[i-1];

    if(i==1 || i==n || i&1 || (i<n && a[i][0]-a[i-2][0]<=k)){
      dp[i][1]=max(dp[i][1],dp[last][0]+a[i-1][1]);
    }

    if(i==1 || i==n || !(i&1) || (i<n && a[i][0]-a[i-2][0]<=k)){
      dp[i][0]=max(dp[i][0],dp[last][1]+a[i-1][1]);
    }
  }

  return dp[n][n%2];
}

int main(){
  fastio;

  ll t,n,k;
  cin>>t>>n>>k;
  vector<array<ll,2>>cow;
  ll ans=0;
  for(int i=1;i<=n;i++){
    ll x,y;
    cin>>x>>y;
    if(!cow.empty() && cow.back()[0]+k<x){
      if(t==1 && (cow.size()%2)){
        ans+=MN(cow,k);
      }else if(t==2) ans+=MX(cow,k);
      cow.clear();
    }
    cow.push_back({x,y});
  }

  if(!cow.empty()){
    if(t==1 && (cow.size()%2)){
      ans+=MN(cow,k);
    }else if(t==2) ans+=MX(cow,k);
  }

  cout<<ans<<endl;
  return 0;
}
