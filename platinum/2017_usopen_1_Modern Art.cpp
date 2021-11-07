/*
	Author : Pranshu
	Problem: Modern Art
*/
#include"bits/stdc++.h"
using namespace std;

#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define inf LLONG_MAX

const int lmt=1e3+10;
const int lmt2=1e6+10;
int a[lmt][lmt],cnt[lmt][lmt];
bool ok[lmt2],pre[lmt2];
int mnx[lmt2],mxx[lmt2],mny[lmt2],mxy[lmt2];

int main(){
  fastio;

  freopen("art.in","r",stdin);
  freopen("art.out","w",stdout);

  int n;
  cin>>n;

  for(int i=1;i<=n*n;i++){
    mny[i]=mnx[i]=1e9;
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>a[i][j];
      if(!a[i][j]) continue;
      pre[a[i][j]]=1;
      mny[a[i][j]]=min(mny[a[i][j]],j);
      mxy[a[i][j]]=max(mxy[a[i][j]],j);
      mnx[a[i][j]]=min(mnx[a[i][j]],i);
      mxx[a[i][j]]=max(mxx[a[i][j]],i);
    }
  }
  for(int i=1;i<n*n;i++){
    if(mnx[i]==1e9) continue;
    int x1=mnx[i],y1=mny[i],x2=mxx[i],y2=mxy[i];
    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    cnt[x1][y1]++,cnt[x1][y2+1]--,cnt[x2+1][y1]--,cnt[x2+1][y2+1]++;
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) cnt[i][j]+=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1];
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(!a[i][j]) continue;
      if(cnt[i][j]-1) ok[a[i][j]]=1;
    }
  }

  int cntcol=0;
  for(int i=1;i<=n*n;i++){
    if(pre[i]) cntcol++;
  }

  if(cntcol==1){
    cout<<n*n-1<<endl;
    return 0;
  }

  int ans=0;
  for(int i=1;i<=n*n;i++){
    if(ok[i]) continue;
    ans++;
  }

  cout<<ans<<endl;
  return 0;
}
