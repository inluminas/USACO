/*
  Author : inluminas
  Problem: Lifeguards
*/
#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)

const int lmt=1e5+5;
vector<pair<int,int>>adj[lmt];
int dp[lmt][101],n,k;
array<int,2>a[lmt];

int main(){
  fastio;

  //freopen("lifeguards.in","r",stdin);
  //freopen("lifeguards.out","w",stdout);

  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>a[i][0]>>a[i][1];
  }
  sort(a+1,a+n+1);
  for(int i=0;i<lmt;i++){
    for(int j=0;j<101;j++){
      dp[i][j]=1e9;
    }
  }
  for(int i=n;i>0;i--){
    for(int j=0;j<=k;j++){
      if(n-i<j) continue;
      int mx=a[i][1]-a[i][0];
      for(pair<int,int>x:adj[i+j+1]){
        if(a[i][1]>=x.second){
          mx=max(mx,a[i][1]-a[i][0]+x.first-(a[i][1]-x.second));  
        }else{
          mx=max(mx,a[i][1]-a[i][0]+x.first);
        }
      }
      dp[i][j]=mx;
      adj[i+j].push_back({dp[i][j],a[i][0]});
    }
  }
  int ans=0;
  for(int i=1;i-1<=k;i++){
    ans=max(ans,dp[i][k-i+1]);
  }
  cout<<ans<<endl;
  return 0;
} 
