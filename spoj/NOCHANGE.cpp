#include <iostream>
#include <bitset>
using namespace std;
int main(){
	int x,k;
	cin >> x >> k;
	int coins[k],sum[k];
	bitset<100000> sumX;
	cin >> coins[0];
	sum[0] = coins[0];
	sumX[sum[0]] = 1;
	for(int i=1;i<k;i++){
		cin>> coins[i];
		sum[i] = sum[i-1] + coins[i];
		sumX[sum[i]] = 1;
	}
	if(sumX[x]){cout << "YES"; return 0;}
 
	for(int i=1;i<=x;i++){
		for(int j=0;j<k;j++){
			if(i-sum[j] < 0 )break;
			if(sumX[i-sum[j]]==1){
				sumX[i] = 1;
			}
		}
	}
	if(sumX[x]){cout << "YES"; return 0;}
	cout << "NO";
	return 0;
}