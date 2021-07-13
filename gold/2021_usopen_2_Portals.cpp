/*
  Author : inluminas
  Problem: Portals
*/
#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
#define fastio ios_base::sync_with_stdio(false)
#define endl "\n"

const int lmt=2e5+100;
int par[lmt];

int findpar(int u){
  if(par[u]==u) return u;
  else return par[u]=findpar(par[u]);
}

void unite(int u,int v){
  u=findpar(u),v=findpar(v);
  if(u==v) return;
  par[u]=v;
}

int main(){
  fastio;

  int n;
  cin>>n;
  for(int i=1;i<=n+n;i++){
    par[i]=i;
  }
  vector<pair<ll,pair<ll,ll>>>edge;

  for(int i=1;i<=n;i++){
    int c,u[4];
    cin>>c;
    for(int j=0;j<4;j++) cin>>u[j];
    unite(u[0],u[1]);
    unite(u[2],u[3]);
    edge.push_back({c,{u[1],u[2]}});
  }

  sort(edge.begin(),edge.end());
  ll ans=0;

  for(auto x:edge){
    int c=x.first,u=x.second.first,v=x.second.second;
    u=findpar(u),v=findpar(v);
    if(u==v) continue;
    unite(u,v);
    ans+=c;
  }

  cout<<ans<<endl;
  return 0;
} 
