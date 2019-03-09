#include <iostream>
#include <utility>
#include <climits>
using namespace std;
typedef pair<long long, long long> pll;
pll maxPair(pll a, pll b){
	if(a.first>b.first){
		return a.second>b.first ? a : pll(a.first,b.first);
	}
	return b.second>a.first ? b : pll(b.first,a.first);
}
pll find(pll* st, int n, int l, int r){
	pll m=pll(INT_MIN,INT_MIN);
	for(l+=n, r+=n; l<r; l>>=1,r>>=1){
		if(l&1){
			m = maxPair(m,st[l]); l++;
		}
		if(r&1){
			r--; m = maxPair(st[r],m);
		}
	}
	return m;
}
int main(){
	int n,ops, idx, a,b;
	long long valI, ipt;
	char ch;
	cin >> n;
	pll st[2*n];
	pll findRes;
	for(int i=0;i <n; i++){
		cin >> ipt;
		st[i+n] = pll(ipt,INT_MIN);
	}
	for(int j=n-1; j>0; j--){
		st[j] = maxPair(st[j<<1], st[j<<1 | 1]);
	}
	cin >> ops;
	for(int i=0; i<ops; i++){
		cin >>  ch;
		if(ch=='Q'){
			cin >> a >>b;
			findRes = find(st, n, a-1, b);
			cout << (findRes.first + findRes.second) << "\n";
		}else if(ch=='U'){
			cin >> idx >> valI;
			idx = idx-1+n;
			st[idx] = pll(valI, INT_MIN);
			for(int k=idx; k>1; k>>=1){
				st[k>>1] = maxPair(st[k],st[k^1]);
			}
		}else{
			i--;
		}
	}
	return 0;
} 