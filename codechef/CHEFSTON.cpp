#include<iostream>
#include <stdio.h>
#include <vector>
using namespace std;
 
 
 
int main(void) {
	int t;
	//n=10^5,k=10^9,b=10^9,T[i]=10^9
	long n,i;
	long long k,b,max,result;;
	scanf("%d",&t);
 	while(t--){
 	   scanf("%ld%lld",&n,&k);
 	   vector<long long> T(n);
 	   max=0;
 	   
	   for(i=0;i<n;i++){
	   	scanf("%lld",&b);
	   	T[i]=b;
	   }
	   for(i=0;i<n;i++){
	   	 scanf("%lld",&b);
	   	 result = (long long)((long long)(k/T[i])*b) ;
	   	 max = result>max ? result :max;
	   }
	   printf("%lld\n",max);
    }
	return 0;
}