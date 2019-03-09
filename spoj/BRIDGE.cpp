#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
struct point{
	int x;
	int y;
};
typedef struct point Point;
 
int sortByY(const void* a, const void* b){
	if(((Point*)a)->y == ((Point*)b)->y){
		return ((Point*)a)->x - ((Point*)b)->x;
	}
	return ((Point*)a)->y - ((Point*)b)->y;
}	
 
 
int LIS(Point* points, int n){
	int maxL, maxG = 1;
	int* dp = (int*)malloc(sizeof(int)*n); // dp[i] length of longest increasing subsequence ending at i
	memset(dp,0,sizeof(int)*n);
	dp[0] = 1;
	for(int i=1;i<n;i++){
		maxL = 1;
		for(int j=i;j>=0;j--){
			if(points[j].x <= points[i].x && dp[j]+1 > maxL)
				maxL = dp[j]+1;
		}
		dp[i] = maxL;
		if(dp[i]>maxG){
			maxG = dp[i];
		}
	}
	free(dp);
	return maxG;
}
int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		Point* points = (Point*)malloc(sizeof(Point)*n);
		memset(points,0,sizeof(Point)*n);
		for(int i=0;i<n;i++){
			cin >> points[i].x;
		}
		for(int i=0;i<n;i++){
			cin >> points[i].y;
		}
		qsort(points,n,sizeof(Point),sortByY);
		/*cout << "\n";
		for(int i=0;i<n;i++){
			cout <<points[i].y<<", "<<points[i].x<<"\t";
		}*/
 
		cout<< LIS(points, n) << "\n";
 
		free(points);
	}
} 