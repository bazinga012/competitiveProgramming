#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
int move_gen[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
int max(int a,int b){return a>b?a:b;}
int DFS(vector<pii> g, bitset<101>& rt, int r, int c, int i, int j){
	rt[(i*c) + j] = true;
	int u,v,tmp,m=0;
	for(int k=0;k<8;k++){
		u = i+move_gen[k][0], v = j + move_gen[k][1];
		if(u>=0 && u<r && v>=(g[u].first) && v < (g[u].first + g[u].second) && !rt[u*c + v]){
			tmp = DFS(g,rt,r,c,u,v);
			m = max(tmp,m);
		}
	}
	rt[(i*c)+j] = false;
	return m+1;
}
 
int main(){
	int n,a,b,tc=0;
	cin >> n;
	while(n!=0){
		tc++;
		vector<pii> g;
		bitset<101> rt;
		int k=0;
		for(int i=0;i<n;i++){
			cin >> a >> b;
			g.push_back(pii(a,b));
			k+=b;
		}
		k = k - DFS(g,rt,n,11,0,g[0].first);
		cout << "Case "<< tc <<", "<< k << (k==1 ? " square" : " squares")<<" can not be reached.\n";
		cin >> n;
	}
	return 0;
} 
