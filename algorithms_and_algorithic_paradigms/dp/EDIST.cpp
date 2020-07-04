#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
 
int min(int a,int b,int c){
	int min = a>b?b:a;
	return min>c?c:min;
}
 
int edit_distance(char* str1,char*str2){
	int n = strlen(str1);
	int m = strlen(str2);
	if(n==0)return m;
	if(m==0)return n;
	int** dp = (int**)malloc(sizeof(int*)*(n+1));
	for(int i=0;i<=n;i++){
		dp[i] = (int*)malloc((m+1)*sizeof(int));
	}
	
	int i,j;
	for(i=0;i<=n;i++){
		dp[i][0]=i;
	}
	for(j=0;j<=m;j++){
		dp[0][j]=j;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			dp[i][j] = (str1[i-1]==str2[j-1]) ? dp[i-1][j-1]: min(dp[i-1][j-1]+1,dp[i-1][j]+1,dp[i][j-1]+1);
		}
	}
	return dp[n][m];
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--){
		char string1[2002],string2[2002];
		scanf("%s",string1);
        scanf("%s",string2);
		printf("%d\n",edit_distance(string1,string2));
	}
	return 0;
}