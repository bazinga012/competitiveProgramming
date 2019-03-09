#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

//check if zeroth free
//if free assign
//if not free check its preference 
//if stable with current leave him/her there only try assigning next 
//else remove assignment from previous and assign to this

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second < b.second);
}

int main(){
	int t,n,k,num;
	cin >> t;

	while(t--){
		cin >> n;
		vector<map<int,int> >w_p(n);
		vector<vector<int> > m_p(n,vector<int>(n,0));
		queue<pair<int,int> > unassingned_men;
		map<int,pair<int,int> > assignments;
		for(int i=0;i<n;i++){
			cin >> k;
			for(int j=0;j<n;j++){
				cin >> num;
				w_p[k-1][num-1]=j;
			}
		}
				
		for(int i=0;i<n;i++){
			cin >> k;
			unassingned_men.push(pair<int,int>(k-1,0));
			for(int j=0;j<n;j++){
				cin >> num;
				m_p[k-1][j]=num-1;
			}
		}

		int m,idx,w;
		pair<int,int> curr;
		while(assignments.size()!=n){
			m = unassingned_men.front().first;
			idx = unassingned_men.front().second;
			w = m_p[m][idx];
			if(assignments.find(w)!=assignments.end()){
				curr = assignments[w];
				if(w_p[w][curr.first] <=w_p[w][m]){
					unassingned_men.front().second+=1;
					continue;
				}else{
					curr.second+=1;
					unassingned_men.push(curr);	
				}
			}
			assignments[w]=pair<int,int>(m,idx);
			unassingned_men.pop();
		}

		vector<pair<int,int> > fa;
		for(int i=0;i<n;i++){
			fa.push_back(pair<int,int>(assignments[i].first+1,i+1));
		}
		sort(fa.begin(),fa.end());
		for(int i=0;i<n;i++){
			cout << fa[i].first << " "<< fa[i].second<<endl;
		}
		
	}
	return 0;
}
