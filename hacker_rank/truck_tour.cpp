// https://www.hackerrank.com/challenges/truck-tour/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,p,d;
    scanf("%d",&N);
    
    long long st[N];
    for(int i=0;i<N;i++){
        scanf("%lld",&p);
        scanf("%lld",&d);
        st[i] = p-d;
    }
    long long prev=0;
    long long curr=0;
    int i=0,j=0;
    
    while(i<N){
        if(st[i]<0){prev+=st[i];i++;continue;}
        j=i;
        while(curr>=0 && i<N){
            curr+=st[i];
            i++;
        }
        if(i<N && curr<0){
            prev +=curr;
            curr=0;
        }
    }
    if(i>=N){
       if(curr+prev>=0){printf("%d",j);}
    }
    
    
    return 0;
}
