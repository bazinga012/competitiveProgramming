#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int move_gen[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
int max(int a,int b){return a>b?a:b;}
int DFS(char** chars,int** dp, int r, int c, int i, int j){
	int u,v,tmp,m=0;
	for(int k=0;k<8;k++){
		u = i+move_gen[k][0], v = j+move_gen[k][1];
		if(u>=0 && u<r && v>=0 && v<c && (chars[u][v] - chars[i][j])==1){
			tmp = dp[u][v]!=0 ? dp[u][v] : DFS(chars,dp,r,c,u,v);
			m = max(tmp,m);
		}
	}
	return dp[i][j] = m+1;
}
int main(){
	int r,c,tc=0;
	cin >> r >> c;
	while(r!=0 && c!=0){
		tc++;
		char** chars = (char**)malloc(r*sizeof(char*));
		int** dp = (int**)malloc(r*sizeof(int*));
		vector<pair<int,int> > srcs;
		for(int i=0;i<r;i++){
			chars[i] = (char*)malloc(c*sizeof(char));
			dp[i] = (int*)malloc(c*sizeof(int));
			for(int j=0;j<c;j++){
				cin >> chars[i][j];
				if(chars[i][j]=='A')srcs.push_back(pair<int,int>(i,j));
				dp[i][j]=0;
			}
		}
		int m = 0;
		for(int i=0;i<srcs.size();i++){
			m = max(m,DFS(chars,dp, r,c,srcs[i].first,srcs[i].second));
		}
		cout << "Case "<<tc<<": "<<m<< "\n";
		cin >> r >> c;
	}
	return 0;
} 