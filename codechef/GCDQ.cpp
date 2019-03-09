#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

int gcd(int a,int b){
  if(b==0){
  	return a;
  }
  return gcd(b,a%b);
}
int make_st(vector<int>&arr,int si,int ei,int* st,int ist){
   if(si==ei){
   	  st[ist]=arr[si];
   	  return st[ist];
   }	
   int mid = (si+ei)/2;
   int left = make_st(arr,si,mid,st,(ist*2)+1);
   int right = make_st(arr,mid+1,ei,st,(ist*2)+2);
   st[ist] = gcd(left,right);
   return st[ist];
}
int find_val(int* st,int si,int ei,int l,int r,int ist){
	if(si>r ||l>ei){
	    return -1;	
	}else if((si>=l && ei <= r)){
		return st[ist];
	}else{
		int mid = (si+ei)/2;
		int left = find_val(st,si,mid,l,r,ist*2+1);
   		int right = find_val(st,mid+1,ei,l,r,ist*2+2);
   		int result;
   		if(left==-1 ){
   			result=right;
   		}else if(right==-1){
   			result=left;
   		}else{
   			 result = gcd(left,right);
   		}
   	    return result;
	}
}
int main() {
	// your code goes here'
	int tc,n,q,l,r,i;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d%d",&n,&q);
		vector<int> arr(n);
		i=0;
		int input;
		while(i<n){
			scanf("%d",&input);
			arr[i] =input;
			i++;
		}
		
		i=0;
		int h = ceil(log2(n));
		int size = 2* pow(2,h)-1;
		int* st = (int*)malloc(sizeof(int)*size);
		memset(st,0,sizeof(int)*size);
		make_st(arr,0,n-1,st,0);
		i=0;
		i=q;
		while(i--){
			scanf("%d%d",&l,&r);
			int left=0,right=0,result; 
			if(l-2 >= 0){
			   left = find_val(st,0,n-1,0,l-2,0);
			}if(r<=n-1){
			   right = find_val(st,0,n-1,r,n-1,0);
			}
			if(left==0){
				result=right;
			}else if(right==0){
				result=left;
			}else{
				result = gcd(left,right);
			}
			printf("%d\n",result);
		}
	}
	return 0;
}