/*
  Author : Pranshu
  Problem: Why Did the Cow Cross the Road
*/
#include"bits/stdc++.h"
using namespace std;

#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)

const ll lmt=100100;
ll cnt[3*lmt],c[lmt],a[lmt],b[lmt],n;


void updet(int at,int L,int R,int pos){
  if(L==R){
    cnt[at]=1;
    return;
  }
  int mid=(L+R)>>1;
  if(pos<=mid) updet(at*2,L,mid,pos);
  else updet(at*2+1,mid+1,R,pos);
  cnt[at]=cnt[at*2]+cnt[at*2+1];
}

ll query(int at,int L,int R,int l,int r){
  if(r<l) return 0LL;
  if(r<L || R<l) return 0LL;
  if(l<=L && R<=r) return cnt[at];
  int mid=(L+R)>>1;
  ll x=query(at*2,L,mid,l,r),y=query(at*2+1,mid+1,R,l,r);
  return x+y;
}

int main(){
  fastio;

  freopen("mincross.in","r",stdin);
  freopen("mincross.out","w",stdout);

  cin>>n;
  for(ll i=1;i<=n;i++){
    ll pos;
    cin>>pos;
    a[pos]=i;
  }
  for(ll i=1;i<=n;i++){
    ll pos;
    cin>>pos;
    b[pos]=i;
  }
  for(ll i=1;i<=n;i++){
    c[a[i]]=b[i];
  }
  ll ans,res=0;
  for(ll i=n;i>0;i--){
    res+=query(1,1,n,1,c[i]);
    updet(1,1,n,c[i]);
  }
  ans=res;
  for(ll i=n;i>0;i--){
    res+=(c[i]-1-n+c[i]);
    ans=min(ans,res);
  }
  for(int i=1;i<=n;i++){
    c[b[i]]=a[i];
  }
  for(int i=0;i<3*lmt;i++){
    cnt[i]=0;
  }
  res=0;
  for(ll i=n;i>0;i--){
    res+=query(1,1,n,1,c[i]);
    updet(1,1,n,c[i]);
  }
  ans=min(ans,res);
  for(ll i=n;i>0;i--){
    res+=(c[i]-1-n+c[i]);
    ans=min(ans,res);
  }
  cout<<ans<<endl;
  return 0;
} 
