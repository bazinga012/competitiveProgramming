#include<iostream>
using namespace std;
 
int main(){
    int tc,n,t,d;
    cin>>tc;
    while(tc--){
        cin>>n>>t>>d;
        int h[n];
        for(int i=0;i<n;i++)
            cin>>h[i];
        int count=0;
        for(int i=0;i<n;i++){
            h[i]-=d;
            while(h[i]>0){
                count++;
                h[i]-=d;
            }
        }
        if(count>=t)
            cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
  
    return 0;
}