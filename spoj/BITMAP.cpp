#include <iostream>
#include <queue>
#include <climits>
#include <stdlib.h>
using namespace std;
 
int main(){
	int tc;
	cin>>tc;
	bool matrix[182][182];
	int res[182][182];
	while(tc--){
		int n,m,min,curr;
		cin>>n>>m;
		queue<pair<int,int> > impact_propagation_queue;
		for(int i=0;i<n;i++){
			char str[m+1];
			cin>>str;
			for(int j=0;j<m;j++){
				if(str[j]=='0'){
					matrix[i][j]=false;
					res[i][j]=INT_MAX;
				}
				else{
					matrix[i][j]=true;
					res[i][j]=0;
					impact_propagation_queue.push(pair<int,int>(i,j));
				}
			}
		}
		while(!impact_propagation_queue.empty()){
			pair<int,int>ip_cord = impact_propagation_queue.front();
			impact_propagation_queue.pop();
			if(ip_cord.first+1<n && (res[ip_cord.first][ip_cord.second]+1<res[ip_cord.first+1][ip_cord.second])){
				res[ip_cord.first+1][ip_cord.second] = res[ip_cord.first][ip_cord.second]+1;
				impact_propagation_queue.push(pair<int,int>(ip_cord.first+1,ip_cord.second));
			}
			if(ip_cord.first-1>=0 && (res[ip_cord.first][ip_cord.second]+1<res[ip_cord.first-1][ip_cord.second])){
				res[ip_cord.first-1][ip_cord.second] = res[ip_cord.first][ip_cord.second]+1;
				impact_propagation_queue.push(pair<int,int>(ip_cord.first-1,ip_cord.second));
			}
				
			if(ip_cord.second+1<m && (res[ip_cord.first][ip_cord.second]+1<res[ip_cord.first][ip_cord.second+1])){
				res[ip_cord.first][ip_cord.second+1] = res[ip_cord.first][ip_cord.second]+1;
				impact_propagation_queue.push(pair<int,int>(ip_cord.first,ip_cord.second+1));
			}
			if(ip_cord.second-1>=0 && (res[ip_cord.first][ip_cord.second]+1<res[ip_cord.first][ip_cord.second-1])){
				res[ip_cord.first][ip_cord.second-1] = res[ip_cord.first][ip_cord.second]+1;
				impact_propagation_queue.push(pair<int,int>(ip_cord.first,ip_cord.second-1));
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<res[i][j]<<" ";
			}
			cout<<endl;
		}
 
 
	}
	return 0;
} 