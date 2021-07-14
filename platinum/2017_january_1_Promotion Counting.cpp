/*
  Author : inluminas
  Problem: Promotion Counting
*/
#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
#define fastio ios_base::sync_with_stdio(false)
#define endl "\n"

const int lmt=2e5+100;
ll a[lmt],n,m,p[lmt],t=1,ans[lmt],tree[4*lmt];
array<int,2>indx[lmt];
vector<int>adj[lmt];



void dfs(int u){
  indx[u][0]=t;
  for(int v:adj[u]){
    t++;
    dfs(v);
  }
  t++;
  indx[u][1]=t;
}

void updet(int at,int L,int R,int pos){
  if(L==R){
    tree[at]=1;
    return;
  }
  int mid=(L+R)>>1;
  if(pos<=mid) updet(at*2,L,mid,pos);
  else updet(at*2+1,mid+1,R,pos);
  tree[at]=tree[at*2]+tree[at*2+1];
}

ll query(int at,int L,int R,int l,int r){
  if(r<L || R<l) return 0LL;
  if(l<=L && R<=r) return tree[at];
  int mid=(L+R)>>1;
  ll x=query(at*2,L,mid,l,r);
  ll y=query(at*2+1,mid+1,R,l,r);
  return x+y;
}

int main(){
  fastio;

  freopen("promote.in","r",stdin);
  freopen("promote.out","w",stdout);

  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>p[i];
  }
  for(int i=2;i<=n;i++){
    int b;
    cin>>b;
    adj[b].push_back(i);
  }
  dfs(1);
  pair<pair<ll,ll>,pair<ll,ll>>b[n+1];
  int idx=0;
  for(int i=1;i<=n;i++){
    idx++;
    b[idx].first.first=p[i];
    b[idx].first.second=i;
    b[idx].second.first=indx[i][0];
    b[idx].second.second=indx[i][1];
  }
  sort(b+1,b+n+1);
  int l=n;
  m=n+n;
  for(int i=n;i>0;i--){
    while(l>i && b[i].first.first<b[l].first.first){
      updet(1,1,m,b[l].second.first);
      updet(1,1,m,b[l].second.second);
      l--;
    }
    ans[b[i].first.second]=query(1,1,m,b[i].second.first,b[i].second.second);
  }
  for(int i=1;i<=n;i++){
    cout<<ans[i]/2<<endl;
  }
  return 0;
} 
