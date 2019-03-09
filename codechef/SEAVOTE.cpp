#include <stdio.h>
int main(void) {
	// your code goes here
	//t->50,n->10000,b[i]->1000
	int t;
	unsigned long n,lim=0,i;
	long long sum=0,m;
	
	
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%lu",&n);
		//lim = (long long)(n*9)/10;
		lim=n-1;
		for(i=0;i<n;i++){
			scanf("%lld",&m);
			if(m==0){
				lim--;
				//lim = (long long)((long long)((n-zc)*9))/10;
				
			}
			sum+=m;
			//printf("sum:%lld lim:%lld",sum,(100+lim));
			
		}
		if(sum<100 || sum>(long long)(100+lim)){
				printf("NO\n");
				continue;
		}else{
			printf("YES\n");
		}
		
	}
	return 0;
}