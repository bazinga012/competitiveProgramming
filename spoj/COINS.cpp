#include<cstdio>
 
using namespace std;
typedef long long ll;
ll memo[100000]; 
 
 
ll max(ll a,ll b){ return (a>b) ? a : b; }
 
 ll coins_max(ll n){    
     if(n<12){
        memo[n]=n;
        return memo[n];          
     }    
    else{
      if(n<100000 && memo[n]){
        return memo[n];
      }
      else{ 
        ll a=coins_max((ll)(n/2));
        ll b=coins_max((ll)(n/3));
        ll c=coins_max((ll)(n/4));
        ll sumf=a+b+c;
       
        if(n<100000){
          memo[n]=max(n,sumf);
          return memo[n];
        }
        return max(n,sumf);
      }    
    }     
}
 
int main(){   
  ll n;
  int count=0;
  ll output[10];
  scanf("%llu",&n);
  output[count]=coins_max(n);
  count++;
  while(scanf("%llu",&n) != EOF){ 
    output[count]=coins_max(n);
    count++;
  }   
  for(int i=0; i<count; i++){
    printf("%llu\n",output[i]);        
  }    
  return 0;
} 