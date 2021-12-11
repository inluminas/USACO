/*
  Author : Pranshu
  Problem: I Would Walk 500 Miles
*/
#include"bits/stdc++.h"
using namespace std;

#define ll long long
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define inf LLONG_MAX

int main(){
  fastio;

  freopen("walk.in","r",stdin);
  freopen("walk.out","w",stdout);

  ll n,k;
  cin>>n>>k;
  ll i=k-1,j=n;
  ll ans=(2019201913*i+2019201949*j)%2019201997;
  cout<<ans<<endl;
  return 0;
}
