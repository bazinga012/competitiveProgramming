#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
 
using namespace std;
typedef long long ll;
struct tableEntry{
	ll smoke;
	int colour;
};
typedef struct tableEntry TableEntry;
 
ll findSmoke(int c1, int c2){
	return (ll)c1*c2;
}
int findColour(int c1, int c2){
	return (c1+c2)%100;
}
 
int main(){
	int n;
	while(cin >> n){
		int *colours = (int*)malloc(sizeof(int)*n);
		TableEntry **table = (TableEntry**)malloc(sizeof(TableEntry*)*n);
		for(int i=0; i<n; i++){
			table[i] = (TableEntry*)malloc(sizeof(TableEntry)*n);
		}
		memset(colours,0,sizeof(int)*n);
		memset(table[0],0,sizeof(TableEntry)*n*n);
		for(int i=0; i<n; i++){
			cin >> colours[i];
			table[i][i].colour = colours[i];
		}
		for(int l=2;l<=n;l++){
			for(int i=0;i<=n-l;i++){
				int j = l + i -1;
				table[i][j].smoke = LONG_MAX;
				for(int k=i; k<j; k++){
					TableEntry t1 = table[i][k];
					TableEntry t2 = table[k+1][j];
					ll smoke = t1.smoke + t2.smoke + findSmoke(t1.colour, t2.colour);
					if(smoke < table[i][j].smoke){
						table[i][j].smoke = smoke;
						table[i][j].colour = findColour(t1.colour, t2.colour); 
					}
				}
			}
		}
 
 
		cout <<table[0][n-1].smoke << "\n";
	}
 
 
	return 0;
}