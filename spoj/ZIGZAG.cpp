#include <iostream>
using namespace std;
typedef long long ll;
ll get_num(int i,int j,int n,int m,ll* dp){
	//i,j lie on i+j+1th diagonal
	ll num;
	if((i+j+1) & 1){
		ll imax = (i+j-(n-1))>=0?(n-1):(i+j);
		num = dp[i+j-1]+imax-i+1;//dp[i+j-1]: covered till i+jth digonal
	}else{
		ll imin = (m-1-(i+j)>=0)?0:(i+j-m+1);
		num = dp[i+j-1]+i-imin+1;
	}
	return num;
}
int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	int max_d = 2*n-1;
	ll dp[max_d];//no of diagonals=n+m-1 dp[i] numbers covered till diagonal i+1
	int min = n;
	dp[0]=1;
	int i;
	for(i=1;i<min-1;i++){
		dp[i] = dp[i-1]+i+1;
	}
	for(i=min-1;i<=max_d-min;i++)dp[i]=dp[i-1]+min;
	int j=min-1;
	for(i=max_d-min+1;i<max_d;i++){
		dp[i]=dp[i-1]+j;
		j--;
	}
	i=0;j=0;
	ll sum=1;
	char str[k+1];
	cin>>str;
	for(int l=0;l<k;l++){
		if(str[l]=='D'){
			i++;
		}else if(str[l]=='R'){
			j++;
		}else if(str[l]=='U'){
			i--;
		}else if(str[l]=='L'){
			j--;
		}if(i==0&&j==0)sum+=1;
		else{
			sum+=get_num(i,j,n,n,dp);	
		}
	}
	cout<<sum;
	return 0;
} 