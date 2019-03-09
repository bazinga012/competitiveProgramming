#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;
long long min(long long a, long long b){return a<b ? a:b;}
long long find(long long* st, int n, int l, int r){
	long long m = st[l+n];
	for(l+=n,r+=n; l<r; l>>=1, r>>=1){
		if(l&1){
			m = min(m,st[l]); l++;
		}
		if(r&1){
			--r; m = min(m, st[r]);
		}
	}
	return m;
}
 
int main(){
	int t,n,q,a,b,i=1;
	cin >> t;
	while(i<=t){
		cin >> n >> q;
		long long st[2*n];
		for(int j=0;j<n;j++){
			cin >> st[j+n];
		}
 
		for(int j=n-1;j>0; j--){
			st[j] = min(st[j<<1],st[j<<1 | 1]);
		}
		vector<pair<int, int> >queries;
		for(int j=0;j<q;j++){
			cin >> a >> b;
			queries.push_back(pair<int, int>(a-1,b-1));
		}
		cout << "Scenario #"<<i<<":\n";
		for(int k=0;k<queries.size();k++){
			a = queries[k].first, b = queries[k].second;
			cout << find(st,n,a,b+1) << "\n";
		}
		i++;
	}
	return 0;
} 