/*
  Author : inluminas
  Problem: Subsequence Reversal
*/
#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
#define fastio ios_base::sync_with_stdio(false)
#define endl "\n"

int a[60],dp[60][60][60][60];

int f(int i,int j,int b,int c){
  if(dp[i][j][b][c]!=-1) return dp[i][j][b][c];
  if(c<b) return -1e9;
  if(i>j) return 0;
  if(i==j){
    if(a[i]>=b && a[i]<=c) return 1;
    else return 0;
  }
  int ans=0;
  ans=max(ans,f(i+1,j-1,b,c));
  if(a[j]>=b){
    ans=max(ans,f(i+1,j-1,a[j],c)+1);
  }
  if(a[i]<=c){
    ans=max(ans,f(i+1,j-1,b,a[i])+1);
  }
  if(b<=a[j] && a[j]<=a[i] && a[i]<=c){
    ans=max(ans,f(i+1,j-1,a[j],a[i])+2);
  }
  ans=max(ans,f(i+1,j,b,c));
  if(a[i]>=b){
    ans=max(ans,f(i+1,j,a[i],c)+1);
  }
  ans=max(ans,f(i,j-1,b,c));
  if(a[j]<=c){
    ans=max(ans,f(i,j-1,b,a[j])+1);
  }
  return dp[i][j][b][c]=ans;
}

int main(){
  fastio;

  freopen("subrev.in","r",stdin);
  freopen("subrev.out","w",stdout);

  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  for(int i=0;i<=50;i++){
    for(int j=0;j<=50;j++){
      for(int k=0;k<=50;k++){
        for(int l=0;l<=50;l++){
          dp[i][j][k][l]=-1;
        }
      }
    }
  }
  cout<<f(1,n,0,50)<<endl;
} 
