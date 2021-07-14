/*
  Author : inluminas
  Problem: Counting Haybales
*/
#include"bits/stdc++.h"
using namespace std;

#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)

const int lmt=2e5+5;
const ll inf=9e18;
ll a[lmt],n,q,lazy[4*lmt],mn[lmt*4],sum[lmt*4];

void build(int at,int L,int R){
  if(L==R){
    mn[at]=a[L], sum[at]=a[L];
    return;
  }
  int mid=(L+R)/2;
  build(at*2,L,mid);
  build(at*2+1,mid+1,R);
  mn[at]=min(mn[at*2],mn[at*2+1]);
  sum[at]=sum[at*2]+sum[at*2+1];
}


void propagate(int at,int L,int R){
  sum[at]+=((R-L+1)*lazy[at]);
  mn[at]+=lazy[at];

  if(L==R){
    lazy[at]=0;
    return;
  }
  lazy[at*2]+=lazy[at], lazy[at*2+1]+=lazy[at];
  lazy[at]=0;
  return;
}

void updet(int at,int L,int R,int l,int r,ll u){
  if(lazy[at]) propagate(at,L,R);
  if(r<L || R<l) return;
  if(l<=L && R<=r){
    lazy[at]+=u;
    propagate(at,L,R);
    return;
  }
  int mid=(L+R)>>1;
  updet(at*2,L,mid,l,r,u);
  updet(at*2+1,mid+1,R,l,r,u);
  sum[at]=sum[at*2]+sum[at*2+1];
  mn[at]=min(mn[at*2],mn[at*2+1]);
}

ll query(int at,int L,int R,int l,int r,bool v){
  if(lazy[at]) propagate(at,L,R);
  if(r<L || R<l){
    if(v) return 0;
    return -1;
  }
  if(l<=L && R<=r){
    if(v) return sum[at];
    return mn[at];
  }
  int mid=(L+R)>>1;
  ll x=query(at*2,L,mid,l,r,v);
  ll y=query(at*2+1,mid+1,R,l,r,v);
  if(v){
    return (x+y);
  }
  if(x==-1) return y;
  if(y==-1) return x;
  return min(x,y);
}

int main(){
  fastio;

  //freopen("haybales.in","r",stdin);
  //freopen("haybales.out","w",stdout);

  cin>>n>>q;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  build(1,1,n);
  while(q--){
    char ch;
    cin>>ch;
    if(ch=='M'){
      ll a,b;
      cin>>a>>b;
      cout<<query(1,1,n,a,b,0)<<endl;
    }else if(ch=='S'){
      ll a,b;
      cin>>a>>b;
      cout<<query(1,1,n,a,b,1)<<endl;
    }else{
      ll a,b,c;
      cin>>a>>b>>c;
      updet(1,1,n,a,b,c);
    }
  }
} 
