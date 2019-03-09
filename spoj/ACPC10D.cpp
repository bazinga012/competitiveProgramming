#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
using namespace std;
typedef long long ll;
 
int main(){
	int n, k =0;
	ll min1,min2,min3;
	cin >> n;
	while(n!=0){
		int arr[n][3];
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin >> arr[i][j];
			}
		}
		ll *dp_l = (ll*)malloc(sizeof(ll)*n);
		ll *dp_m = (ll*)malloc(sizeof(ll)*n);
		ll *dp_r = (ll*)malloc(sizeof(ll)*n);
		memset(dp_l,0,sizeof(ll)*n);
		memset(dp_m,0,sizeof(ll)*n);
		memset(dp_r,0,sizeof(ll)*n);
 
		dp_l[0] = LONG_MAX;
		dp_m[0] = arr[0][1];
		dp_r[0] = arr[0][1] + arr[0][2];
		for(int i=1; i<n; i++){
			min1 = min(dp_m[i-1], dp_l[i-1]);
			dp_l[i] = arr[i][0] + min1 ; //min(dp_m[i-1], dp_l[i-1]);
			min2 = min(dp_r[i-1], dp_l[i]);
			dp_m[i] = arr[i][1] + min(min1, min2);//min(dp_m[i-1],dp_r[i-1],dp_l[i-1],dp_l[i]);
			min3 = min(dp_m[i-1], dp_r[i-1]);
			dp_r[i] = arr[i][2] + min(dp_m[i], min3);//min(dp_m[i-1],dp_m[i],dp_r[i-1]);
		}
		cout << k+1 <<". " << dp_m[n-1] << "\n";
		cin >> n;
		k++;
		free(dp_l);
		free(dp_m);
		free(dp_r);
	}
	return 0;
} 