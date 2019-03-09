#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int tc;
	int n;
	scanf("%d",&tc);
	long long prev;
	long long curr;
	long long sum=0;
	while(tc--){
		scanf("%d",&n);
		scanf("%lld",&prev);
		sum = prev;
		for(int i=1;i<n;i++){
			scanf("%lld",&curr);
			sum = curr-prev>0 ? sum+curr-prev: sum;
			prev = curr;
		}
		printf("%lld\n",sum);
	}
	return 0;
}