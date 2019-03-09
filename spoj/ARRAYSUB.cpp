#include <iostream>
#include <climits>
using namespace std;
int max(int a, int b){return a>b?a:b;}
int find(int* st, int n, int l, int r){
	int m=INT_MIN;
	for(l+=n, r+=n; l<r; l>>=1,r>>=1){
		if(l&1){
			m = max(m,st[l]); l++;
		}
		if(r&1){
			r--; m = max(st[r],m);
		}
	}
	return m;
}
int main(){
	int n,k;
	cin >> n;
	int st[2*n];
	for(int i=0;i <n; i++){
		cin >> st[i+n];
	}
	cin >> k;
	for(int j=n-1;j>0;j--){
		st[j] = max(st[j<<1],st[j<<1 | 1]); 
	}
	for(int i=0;i <=n-k; i++){
		cout << find(st, n, i,i+k) << " ";
	}
	return 0;
} 