/*
  Author : inluminas
  Problem: Tests for Haybales
*/
#include"bits/stdc++.h"
using namespace std;

#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define inf LLONG_MAX

const int lmt=1e5+10;
vector<int>adj[lmt];
ll ans[lmt],n,idx=0;
vector<pair<ll,int>>e;

void dfs(int u,ll w){
  e.push_back({w,u});
  if(adj[u].empty()){
    idx++,ans[u]=idx+(w*n);
    return;
  }
  for(int v:adj[u]) dfs(v,w-1);
}

int main(){
  fastio;

  cin>>n;
  int a[n+1];
  vector<int>r;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    if(a[i]==i){
      r.push_back(i);
      continue;
    }
    adj[a[i]].push_back(i);
  }

  ll last=n,last2=n;

  for(int x:r){
    dfs(x,last);
    sort(e.begin(),e.end());
    for(auto [w,u]:e){
      if(adj[u].empty()){
        continue;
      }else{
        ans[u]=ans[adj[u][0]]+n;
      }
    }
    e.clear();
    idx=0;
    last2+=n;
    last=last2;
  }

  cout<<n<<endl;
  for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
  return 0;
}
