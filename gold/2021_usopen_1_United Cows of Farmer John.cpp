/*
  Author : inluminas
  Problem: United Cows of Farmer John
*/
#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
#define fastio ios_base::sync_with_stdio(false)
#define endl "\n"

const ll lmt=2e5+10;
ll suf[lmt],pre[lmt],n,a[lmt],ans;
vector<ll>adj[lmt],tree[4*lmt];

void merge(ll at,ll l,ll r){
  for(ll v:tree[l]){
    tree[at].push_back(v);
  }
  for(ll v:tree[r]){
    tree[at].push_back(v);
  }
  sort(tree[at].begin(),tree[at].end());
}

void build(int at,int L,int R){
  if(L==R){
    tree[at].push_back(suf[L]);
    return;
  }
  int mid=(L+R)>>1;
  build(at*2,L,mid);
  build(at*2+1,mid+1,R);
  merge(at,at*2,at*2+1);
}

ll query(int at,int L,int R,int l,int r,ll baad,ll u){
  if(r<L || R<l) return 0LL;
  if(l<=L && R<=r){
    int lo=0,hi=tree[at].size()-1;
    while(hi-lo>1){
      ll mid=(lo+hi)>>1;
      if(tree[at][mid]-baad>=u){
        hi=mid;
      }else{
        lo=mid;
      }
    }
    if(tree[at][lo]-baad>=u){
      return (tree[at].size()-lo);
    }else if(tree[at][hi]-baad>=u){
      return (tree[at].size()-hi);
    }else{
      return 0LL;
    }
  }
  int mid=(L+R)>>1;
  ll x=query(at*2,L,mid,l,r,baad,u);
  ll y=query(at*2+1,mid+1,R,l,r,baad,u);
  return x+y;
}

int main(){
  fastio;

  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    adj[a[i]].push_back(i);
  }
  for(int i=1;i<=n;i++){
    if(adj[i].empty()) continue;
    for(int j=0;j<adj[i].size()-1;j++){
      pre[adj[i][j]]=(adj[i][j+1]-adj[i][j]);
    }
    pre[adj[i].back()]=n-adj[i].back()+1;
    for(int j=adj[i].size()-1;j>0;j--){
      suf[adj[i][j]]=abs(adj[i][j-1]-adj[i][j]);
    }
    suf[adj[i][0]]=adj[i][0];
  }
  for(int i=n,ad=0;i>0;i--,ad++){
    suf[i]+=ad;
  }
  build(1,1,n);
  for(int i=1;i<=n;i++){
    ll l=i,r=pre[i]+i-1;
    if(l==r) continue;
    ans+=query(1,1,n,l+1,r,n-r,pre[i]);
    //cout<<l<<" "<<r<<" "<<pre[i]<<endl;
  }
  cout<<ans<<endl;
} 
