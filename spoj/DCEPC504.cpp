#include<cstdio>
typedef long long ll;
 
using namespace std;
int func(ll p,int i,int *arr){
	if(p == 1){
		arr[i] = 0;
		return i;
	}
	if(p&1){
		arr[i]=0;
		return func(p/2+1,i+1,arr);
		
	}else{
		arr[i]=1;
		return func(p/2,i+1,arr);
		
	}
}
 
int main(){
	int n,tc;
	ll k;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		int arr[n];
		scanf("%llu",&k);
		int l = func(k,0,arr);
		int result =0;
		// for(int i=l;i>=0;i--){
		// 	printf("%d\n",arr[i] );
		// }
		for(int i=l;i>=0;i--){
			if(result==0){
				if(arr[i]==0){
					result = 0;
				}else{
					result = 1;
				}
			}else{
				if(arr[i]==0){
					result = 1;
				}else{
					result = 0;
				}
			}
		}
		if(result==0){
			printf("Male\n");
		}else{
			printf("Female\n");
		}
	}
}