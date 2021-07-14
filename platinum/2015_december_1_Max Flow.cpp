/*
  Author : inluminas
  Problem: Max Flow
*/
#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
#define fastio ios_base::sync_with_stdio(false)
#define endl "\n"

const int lmt=1e5+10;
int sum[lmt],/*idx,*/n,k/*,t*/,par[lmt][20],lvl[lmt],ans=0;
//array<int,2>nod[lmt];
vector<int>adj[lmt];

void dfs(int u,int p){
  if(p) par[u][0]=p;
  lvl[u]=lvl[p]+1;
  //t++;
  //nod[u][0]=t;
  for(int v:adj[u]){
    if(v==p) continue;
    dfs(v,u);
  }
  //t++;
  //nod[u][1]=t;
}

void build(){
  for(int j=1;(1<<j)<=n;j++){
    for(int i=1;i<=n;i++){
      if(par[i][j-1]!=-1){
        par[i][j]=par[par[i][j-1]][j-1];
      }
    }
  }
}

int getpar(int p,int q){
  if(lvl[p]<lvl[q]) swap(p,q);

  for(int i=19;i>=0;i--){
    if(lvl[p]-(1<<i)>=lvl[q]){
      p=par[p][i];
    }
  }
  if(p==q) return p;
  for(int i=19;i>=0;i--){
    if(par[p][i]!=-1 && par[p][i]!=par[q][i]){
      p=par[p][i],q=par[q][i];
    }
  }
  return par[p][0];
}

void dpdfs(int u,int p){
  for(int v:adj[u]){
    if(v==p) continue;
    dpdfs(v,u);
    sum[u]+=sum[v];
  }
  ans=max(ans,sum[u]);
}

int main(){
  fastio;

  //freopen("maxflow.in","r",stdin);
  //freopen("maxflow.out","w",stdout);

  cin>>n>>k;

  for(int i=0;i<lmt;i++){
    for(int j=0;j<20;j++){
      par[i][j]=-1;
    }
  }

  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  } 
  dfs(1,0);
  build();
  //par[1][0]=0;

  while(k--){
    int s,t;
    cin>>s>>t;
    int p=getpar(s,t);
    if(p==s || p==t){
      if(lvl[t]>lvl[s]) s=t;
      sum[s]++;
      if(p==1) continue;
      sum[par[p][0]]--; 
    }else{
      sum[s]++,sum[t]++;
      sum[p]--;
      if(p==1) continue;
      sum[par[p][0]]--;
    }
    //cout<<s<<" "<<t<<" "<<p<<endl;
  }

  dpdfs(1,0);
  cout<<ans<<endl;
  return 0;
} 
