/*
  Author : inluminas
  Problem: Redistricting
*/
#include"bits/stdc++.h"
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(false)
#define endl "\n"

const int lmt=3e5+100;
const int inf=1e9;
int n,pre[lmt],k,tree[4*lmt],dp[lmt],pre2[lmt];
multiset<int>val[lmt];
string s;


void build(int at,int L,int R){
  if(L==R){
    tree[at]=inf;
    return;
  }
  int mid=(L+R)>>1;
  build(at*2,L,mid);
  build(at*2+1,mid+1,R);
  tree[at]=min(tree[at*2],tree[at*2+1]);
}

void updet(int at,int L,int R,int pos,int u){
  if(L==R){
    tree[at]=u;
    return;
  }
  int mid=(L+R)>>1;
  if(pos<=mid) updet(at*2,L,mid,pos,u);
  else updet(at*2+1,mid+1,R,pos,u);
  tree[at]=min(tree[at*2],tree[at*2+1]);
}

int query(int at,int L,int R,int l,int r){
  if(R<l || r<L) return inf;
  if(l<=L && R<=r) return tree[at];
  int mid=(L+R)>>1;
  return min(query(at*2,L,mid,l,r),query(at*2+1,mid+1,R,l,r));
}

int main(){
  fastio;

  //freopen("redistricting.in","r",stdin);
  //freopen("redistricting.out","w",stdout);

  cin>>n>>k;
  cin>>s;
  int mn=inf;
  for(int i=1;i<=n;i++){
    int ad=0;
    pre[i]=pre[i-1]+(s[i-1]=='H'?1:-1);
    pre2[i]=pre[i];
    mn=min(mn,pre[i]);
  }
  for(int i=1;i<=n;i++){
    pre[i]+=max(0,1-mn);
  }
  build(1,1,n);
  for(int i=1;i<=n;i++){
    int ans=query(1,1,n,pre[i],n)+1;
    ans=min(ans,query(1,1,n,1,pre[i]-1));
    if(i<=k) ans=min(ans,(pre2[i]>0)?0:1);
    dp[i]=ans;
    val[pre[i]].insert(ans);
    updet(1,1,n,pre[i],(*val[pre[i]].begin()));
    if(i>k){
      val[pre[i-k]].erase(val[pre[i-k]].find(dp[i-k]));
      if(val[pre[i-k]].empty()) updet(1,1,n,pre[i-k],inf);
      else updet(1,1,n,pre[i-k],(*val[pre[i-k]].begin()));
    }
  }
  cout<<dp[n]<<endl;
  return 0;
} 
