/*
  Author : Pranshu
  Problem: Drought
*/
#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define inf LLONG_MAX

const ll mod=1e9+7;
ll dp[110][1010];

int main(){
  fastio;

  int n;
  cin>>n;
  int h[n+1],mn=1e9;
  for(int i=1;i<=n;i++){
    cin>>h[i];
    mn=min(mn,h[i]);
  }

  ll ans=0;

  for(int l=0;l<=mn;l++){
    for(int i=0;i<=h[1]-l;i++) dp[1][i]=1;
    for(int i=2;i<=n;i++){
      for(int k=0;k<=h[i]-l;k++){
        dp[i][h[i]-l-k]+=dp[i-1][k];
        dp[i][h[i]-l-k]%=mod;
      }
      for(int j=h[i]-l-1;j>=0;j--){
        dp[i][j]+=dp[i][j+1];
        dp[i][j]%=mod;
      }
    }

    if(n%2==0){
      cout<<dp[n][0]<<endl;
      return 0;
    }

    ans+=dp[n][0];
    ans%=mod;

    for(int i=0;i<=n;i++){
      for(int j=0;j<=h[i];j++) dp[i][j]=0;
    }
  }

  cout<<ans<<endl;
  return 0;
}
