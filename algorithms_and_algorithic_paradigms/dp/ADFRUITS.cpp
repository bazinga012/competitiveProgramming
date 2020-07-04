#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#define MAX_BUFFER 102
 
using namespace std;
 
void LCS(char* str1,char* str2, int n, int m){
      /*cout << "str1: " << str1 << " str2: " << str2 << "\n";
      cout << "n: " << n <<" m: "<<m<<"\n";*/
      int arr[n+1][m+1], b[n+1][m+1];
      char* solu = (char*)malloc(sizeof(char)*(n+m));
      memset(solu,0,(n+m)*sizeof(char));
 
      for(int i=0;i<=n;i++){
         for(int j=0;j<=m;j++){
              arr[i][j]=0;
              b[i][j]=0;
              
         }     
      }
      for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
               arr[i][j]=arr[i-1][j-1]+1;
               b[i][j]=5;
            }
            else{
               if(arr[i-1][j]<arr[i][j-1]){
                   arr[i][j]=arr[i][j-1];
                   b[i][j]=10;
               }   
               else{
                   arr[i][j]=arr[i-1][j];
                   b[i][j]=15;
               }                             
            }
         }
      }
      
      /*for(int i=0;i<=n;i++){
         for(int j=0;j<=m;j++){
              cout << arr[i][j] << ".." << b[i][j]<<"\t";
              
         }    
         cout << "\n"; 
      }*/
      
      int i=n, j=m, k=0;
      while(i!=0 && j!=0){
         if(b[i][j]==15){
              solu[k]=str1[i-1];
              i--;
              k++;
         }
         else{
              if(b[i][j]==10){
                  solu[k]=str2[j-1];
                  j--;
                  k++;
              }
              else{
                  solu[k]=str1[i-1];
                  i--;
                  j--;
                  k++;  
              }
         }
      }
      if(i==0)
      while(j!=0){
          solu[k]=str2[j-1];
          j--;
          k++;
      }
      if(j==0)
      while(i!=0){
          solu[k]=str1[i-1];
          i--;
          k++;
      }
      /*reverse the string*/ 
      int ls = strlen(solu);
      int t=0, s =ls-1;
      while(t<=s){
         char temp=solu[t];
         solu[t]=solu[s];
         solu[s]=temp;
         t++;
         s--;
      }
      cout << solu << "\n";
      free(solu);
      return;
 
}
int main(){
    char str1[MAX_BUFFER],
         str2[MAX_BUFFER];
    
    while(cin >> str1 && cin >> str2){
        LCS(str1,str2, strlen(str1), strlen(str2));      
    }             
    
    return 0;
}