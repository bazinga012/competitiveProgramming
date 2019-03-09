#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
using namespace std;
int min(int a, int b){
    return (a>b ? b : a);
}
 
int main(){
    int t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int prices[k], dp[k+1][n+1];
        for(int i=0; i<k; i++){
            cin >> prices[i];
            dp[i+1][1] = prices[i]==-1 ? INT_MAX : prices[i];
        }
        for(int i=1; i<=n; i++){
            dp[0][i] = 0;
            dp[1][i] = dp[1][1];
        }
        for(int j=2; j<=k; j++){
            for(int i=2; i<=n; i++){
            	dp[j][i] = dp[j][i-1];
                for(int l=1; l<=j; l++){
                    if(prices[l-1]==-1 || dp[j-l][i-1] == INT_MAX)continue;
                    dp[j][i] = min(prices[l-1] + dp[j-l][i-1], dp[j][i]);
                }
            }
        }
        cout << (dp[k][n] == INT_MAX ? -1 : dp[k][n]) << "\n";
 
    }
    return 0;
} 