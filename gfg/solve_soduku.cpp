#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

vector<bitset<9> > row_bitset(9,bitset<9>(0));
vector<bitset<9> > col_bitset(9,bitset<9>(0));
vector<bitset<9> > cell_group_bitset(9,bitset<9>(0));
vector<vector<int> > soduku(9,vector<int>(9,0));
vector<vector<bool> > is_mutable(9,vector<bool>(9,true));

void print_soduku(){
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)
			cout<<soduku[i][j]<<" ";
	}
}

bool check_violation(int i,int j, int val){
	return row_bitset[i][val-1] || col_bitset[j][val-1] || cell_group_bitset[3*(i/3)+(j/3)][val-1];
}

bool try_cell_fill(int i,int j, bool backtracking){
	if(i>8)return true;
	if(i<0)return false;
	if(is_mutable[i][j]==false){
		if(backtracking){
			if(j>0)
				return try_cell_fill(i, j-1, backtracking);
			else
				return try_cell_fill(i-1, 8, backtracking);
		}else{
			if(j<8)
				return try_cell_fill(i, j+1, backtracking);
			else
				return try_cell_fill(i+1, 0, backtracking);	
		}
	}else{
		int start = 1;
		if(backtracking){
			row_bitset[i][soduku[i][j]-1] = 0;
			col_bitset[j][soduku[i][j]-1] = 0;
			cell_group_bitset[3*(i/3)+(j/3)][soduku[i][j]-1] = 0;
			start = soduku[i][j]+1;  
		}
		for(int v=start;v<=9;v++){
			if(!check_violation(i,j,v)){
				soduku[i][j]=v;
				row_bitset[i][v-1] = 1;
				col_bitset[j][v-1] = 1;
				cell_group_bitset[3*(i/3)+(j/3)][v-1] = 1;
				if(j<8)
					return try_cell_fill(i, j+1, false);
				else
					return try_cell_fill(i+1, 0, false);
			}
		}
		if(j>0){
			return try_cell_fill(i, j-1, true);
		}
		else{
			return try_cell_fill(i-1, 8, true);
		}
	}
}

void solve_soduku_wrapper(){
	try_cell_fill(0,0, false);
	print_soduku();
}

int main(){
	int t,cell;
	cin >> t;
	while(t--){
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cin >> cell;
				soduku[i][j] = cell;
				if(cell>0)
				    is_mutable[i][j] = false;
				row_bitset[i][cell-1]=1;
				col_bitset[j][cell-1]=1;
				cell_group_bitset[3*(i/3)+(j/3)][cell-1]=1;
			}
		}
		//print_soduku();
		solve_soduku_wrapper();
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
			    soduku[i][j]=0;
				is_mutable[i][j] = true;
				row_bitset[i][j] = 0;
				col_bitset[i][j] = 0;
				cell_group_bitset[i][j]=0;
			}
		}
		cout << endl;
	}
	return 0;
}