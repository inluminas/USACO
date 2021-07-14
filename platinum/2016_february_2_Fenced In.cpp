/*
  Author : inluminas
  Problem: Fenced In
*/
#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
#define fastio ios_base::sync_with_stdio(false)
#define endl "\n"

int main(){
  fastio;

  //freopen("fencedin.in","r",stdin);
  //freopen("fencedin.out","w",stdout);

  ll A,B,n,m;
  cin>>A>>B>>n>>m;
  n++,m++;
  ll a[n+1],b[m+1];
  for(int i=1;i<n;i++){
    cin>>a[i];
  }
  for(int i=1;i<m;i++){
    cin>>b[i];
  }
  a[n]=A,b[m]=B;;
  a[0]=0,b[0]=0;
  sort(a+1,a+n+1);
  sort(b+1,b+m+1);
  /*for(int i=1;i<=n;i++) cout<<a[i]<<" ";
  cout<<endl;
  for(int i=1;i<=m;i++) cout<<b[i]<<" ";
  cout<<endl;*/
  ll sa[n+1],sb[m+1];
  for(int i=1;i<=n;i++){
    sa[i]=a[i]-a[i-1];
  }
  for(int i=1;i<=m;i++){
    sb[i]=b[i]-b[i-1];
  }
  sort(sa+1,sa+n+1);
  sort(sb+1,sb+m+1);
  ll tot=0;
  /*for(int i=1;i<=n;i++){
    cout<<sa[i]<<" ";
  }
  cout<<endl;
  for(int i=1;i<=m;i++){
    cout<<sb[i]<<" ";
  }
  cout<<endl;*/
  for(int i=1;i<=n;i++){
    tot+=(sa[i]*(m-1));
  }
  for(int i=1;i<=m;i++){
    tot+=(sb[i]*(n-1));
  }
  vector<pair<ll,ll>>e;
  for(int i=1;i<=n;i++){
    e.push_back({sa[i],0});
  }
  for(int i=1;i<=m;i++){
    e.push_back({sb[i],1});
  }
  sort(e.begin(),e.end());
  reverse(e.begin(),e.end());
  ll z=0,o=0,need=(n-1)*(m-1);
  for(auto [u,v]:e){
    if(!need) break;

    if(!v){
      ll here=min(m-1-o,need);
      tot-=(u*here);
      need-=here;
      z++;
    }else{
      ll here=min(n-1-z,need);
      tot-=(u*here);
      need-=here;
      o++;
    }
  }
  cout<<tot<<endl;
  return 0;
} 
