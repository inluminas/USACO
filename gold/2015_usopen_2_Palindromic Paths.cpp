/*
	Author : Pranshu
	Problem: Palindromic Paths
*/
#include"bits/stdc++.h"
using namespace std;
 
#define ll long long
#define fastio ios_base::sync_with_stdio(false)
#define endl "\n"

const int lmt=501;
const ll mod=1e9+7;
ll dp[lmt][lmt];
string s[lmt];

int main(){
	fastio;

	//freopen("palpath.in","r",stdin);
	//freopen("palpath.out","w",stdout);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		reverse(s[i].begin(),s[i].end());
		s[i]='#'+s[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=1;
	}

	for(int num=1;num<n;num++){
		ll now[lmt][lmt];
		for(int i=0;i<lmt;i++){
			for(int j=0;j<lmt;j++){
				now[i][j]=0;
			}
		}

		int colum=1;


		for(int row=num+1;row<=n;row++){
			for(int ad=0;ad<num+num+1;ad++){
				int rowa=row-ad,columa=colum+(num+num-ad);
				if(rowa<0 || rowa>n || columa<0 || columa>n) continue;
				//cout<<row<<" "<<colum<<" "<<rowa<<" "<<columa<<endl;
				if(s[row][colum]==s[rowa][columa]){
					now[row][rowa]+=dp[row][rowa];
					if(rowa+1<=row) now[row][rowa]+=dp[row][rowa+1];
					if(row-1>=rowa) now[row][rowa]+=dp[row-1][rowa];
					if(row-1>=rowa && rowa+1<=row) now[row][rowa]+=dp[row-1][rowa+1];
				}
				now[row][rowa]%=mod;
			}
			colum++;
		}
		for(int i=0;i<lmt;i++){
			for(int j=0;j<lmt;j++){
				dp[i][j]=now[i][j];
			}
		}
	}
	cout<<dp[n][1]<<endl;
	return 0;
}
