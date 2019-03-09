#include<iostream>
#include<cmath>
#include<map>
using namespace std;

int subset_sum(int a[],int n){
    int m=(int)pow(2.0,n);
    map<int,int> sums;
    for(int i=1;i<m;i++){
        int j=i,k=0,sum=0;
        while(j>0){
            if(j&1){
                sum=sum+a[k];
            }
            j=j>>1;
            k++;
        } 
        if(sums.find(sum)!=sums.end()){
            return 1;
        }
        sums[sum]=1;      
    }
    return 0;
}
int main(){
int tc;
cin>>tc;   
while(tc--){
    int n;
    cin>>n;
    int a[n];
    for(int j=0;j<n;j++){
        cin>>a[j];
    }
    if(n>9){
        cout<<"YES\n";
    }else{
        if(subset_sum(a,n)==1){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
        
}
return 0;    
} 