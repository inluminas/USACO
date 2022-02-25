/*
  Author : Pranshu
  Problem: Farm Updates
*/
#include"bits/stdc++.h"
using namespace std;

#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define inf LLONG_MAX

const int lmt=2e5+10;
int dis[lmt];
vector<pair<int,int>>adj[lmt];

int main(){
  fastio;

  int n,q;
  cin>>n>>q;
  for(int i=1;i<=n;i++) dis[i]=q;

  map<pair<int,int>,int>e;
  vector<pair<int,int>>e2;

  for(int i=1;i<=q;i++){
    char c;
    cin>>c;
    if(c=='A'){
      int u,v;
      cin>>u>>v;
      e[{u,v}]=q;
      e2.emplace_back(u,v);
    }else if(c=='D'){
      int u;
      cin>>u;
      dis[u]=i-1;
    }else{
      int idx;
      cin>>idx;
      int u=e2[idx-1].first,v=e2[idx-1].second;
      e[{u,v}]=i-1;
    }
  }

  for(auto [u,v]:e){
    adj[u.first].push_back({v,u.second});
    adj[u.second].push_back({v,u.first});
  }

  set<pair<int,int>>s;
  for(int i=1;i<=n;i++){
    s.insert({dis[i],i});
  }

  while(!s.empty()){
    auto it=s.end();
    it--;

    int val=(*it).first, u=(*it).second;
    s.erase(it);

    for(auto [w,v]:adj[u]){
      if(dis[v]>=min(w,dis[u])) continue;

      s.erase({dis[v],v});
      dis[v]=min(dis[u],w);
      s.insert({dis[v],v});
    }
  }

  for(int i=1;i<=n;i++) cout<<dis[i]<<endl;
  return 0;
}
