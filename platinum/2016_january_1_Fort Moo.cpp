/*
  Author : inluminas
  Problem: Fort Moo
*/
#include"bits/stdc++.h"
using namespace std;

#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)

const int lmt=205;
char c[lmt][lmt];
int up[lmt][lmt],n,m,ans;

int main(){
  fastio;

  //freopen("fortmoo.in","r",stdin);
  //freopen("fortmoo.out","w",stdout);

  cin>>n>>m;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin>>c[i][j];
    }
  }

  for(int i=0;i<lmt;i++){
    for(int j=0;j<lmt;j++){
      up[i][j]=n+1;
    }
  }

  for(int r=1;r<=n;r++){
    for(int i=1;i<=m;i++){
      int cnt=0;
      for(int j=i;j<=m;j++){
        if(c[r][i]=='X' || c[r][j]=='X'){
          up[i][j]=n+1;
        }
        if(c[r][j]=='X') cnt++;
        if(cnt) continue;
        up[i][j]=min(up[i][j],r);
        ans=max(ans,(r-up[i][j]+1)*(j-i+1));
        //cout<<r<<" "<<up[i][j]<<" "<<j<<" "<<i<<endl;
        /*if(up[i][j]!=inf && r-up[i][j]>0 && j-i>0){
          ans=max(ans,(r-up[i][j]+1)*(j-i+1));
        }
        up[i][j]=min(up[i][j],r);*/
      }
    }
  }
  cout<<ans<<endl;
  return 0;
} 
