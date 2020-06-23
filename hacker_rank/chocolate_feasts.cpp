#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
   int T,N,C,M;
   cin>>T;
    while(T){
      cin>>N>>C>>M;
      int out=N/C;
      int wrap=out;
      while(wrap>=M){
            int temp=(int)(wrap/M);
            out=out+temp;
            wrap=temp+wrap%M;
      }
      cout<<out<<"\n"; 
      T--;   
    }
    return 0;
}
