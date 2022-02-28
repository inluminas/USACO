/*
  Author : Pranshu
  Problem: HILO
*/
#include"bits/stdc++.h"
using namespace std;

#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define inf LLONG_MAX

const int lmt=2e5+10;
vector<pair<int,char>>adj[lmt];

int main(){
  fastio;

  int n;
  cin>>n;
  int a[n+1],par[n+1],L[n+1],H[n+1],D[n+1];
  for(int i=1;i<=n;i++){
    cin>>a[i];
    par[a[i]]=i;
    L[i]=a[i];
  }
  for(int i=1;i<=n;i++) D[i]=n+1;
  set<int>s;
  for(int i=1;i<=n;i++){
    auto it=s.lower_bound(a[i]);
    if(s.empty() || it==s.begin()) H[i]=0;
    else{
      it--;
      H[i]=(*it);
    }

    s.insert(L[i]);
  }
  s.clear();
  for(int i=1;i<=n;i++){
    auto it=s.lower_bound(L[i]);
    if(it!=s.end()) D[i]=(*it);
    s.insert(L[i]);
  }

  for(int i=1;i<=n;i++){
    adj[H[i]].push_back({i,'H'});
    adj[L[i]].push_back({i,'L'});
    adj[D[i]].push_back({i,'D'});
  }

  char pos[n+1];
  for(int i=1;i<=n;i++) pos[i]='#';

  int ans=0;
  s.clear();

  for(int i=0;i<=n;i++){
    for(auto [u,c]:adj[i]){
      int age=-1,pore=-1;
      auto it=s.lower_bound(u);
      if(it!=s.end() && (*it)>u) pore=(*it);

      auto it2=it;

      if(it!=s.end()){
        if((*it)>u) pore=(*it);
        else{
          it++;
          if(it!=s.end()) pore=(*it);
        }
      }

      if(!s.empty() && it2!=s.begin()){
        it2--;
        if((*it2)<u) age=(*it2);
      }

      if(c=='H'){
        if(pore!=-1 && pos[pore]=='L'){
          ans++;
          if(age!=-1 && pos[age]=='H'){
            ans--;
          }
        }
        pos[u]='H',s.insert(u);

      }else if(c=='L'){
        if(pore!=-1 && pos[pore]=='L'){
          ans--;
        }
        if(age!=-1 && pos[age]=='H') ans++;
        pos[u]='L';

      }else{
        if(age!=-1 && pos[age]=='H'){
          ans--;
          if(pore!=-1 && pos[pore]=='L') ans++;
        }
        pos[u]='D',s.erase(u);
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
