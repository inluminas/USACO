/*
  Author : inluminas
  Problem: Why Did the Cow Cross the Road II
*/
#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
#define fastio ios_base::sync_with_stdio(false)
#define endl "\n"

const int lmt=1e5+100;
int a[lmt],b[lmt],pos[lmt],n,tree[4*lmt];

void updet(int at,int L,int R,int pos,int u){
  if(L==R){
    tree[at]=max(tree[at],u);
    return;
  }
  int mid=(L+R)>>1;
  if(pos<=mid) updet(at*2,L,mid,pos,u);
  else updet(at*2+1,mid+1,R,pos,u);
  tree[at]=max(tree[at*2],tree[at*2+1]);
}

ll query(int at,int L,int R,int l,int r){
  if(r<l) return 0LL;
  if(R<l || r<L) return 0LL;
  if(l<=L && R<=r) return tree[at];
  int mid=(L+R)>>1;
  ll x=query(at*2,L,mid,l,r),y=query(at*2+1,mid+1,R,l,r);
  return max(x,y);
}

int main(){
  fastio;

  freopen("nocross.in","r",stdin);
  freopen("nocross.out","w",stdout);

  cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  for(int i=1;i<=n;i++){
    cin>>b[i];
    pos[b[i]]=i;
  }
  int ans=0;
  for(int i=1;i<=n;i++){
    vector<pair<int,int>>seg;
    for(int j=a[i];j<=min(a[i]+4,n);j++){
      int res=query(1,1,n,1,pos[j]-1)+1;
      ans=max(ans,res);
      seg.push_back({res,pos[j]});
    }
    for(int j=a[i];j>=max(a[i]-4,1);j--){
      int res=query(1,1,n,1,pos[j]-1)+1;
      ans=max(ans,res);
      seg.push_back({res,pos[j]});
    }

    for(auto [u,v]:seg){
      updet(1,1,n,v,u);
    }
  }
  cout<<ans<<endl;
  return 0;
} 
