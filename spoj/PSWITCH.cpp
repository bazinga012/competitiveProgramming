#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
 
int main(){
	int n,c,k, p;
	cin >> n >> c >> k;
	string desired_state = "******";
	string all_states[8] = {"000000","001110","010101","011011","100100","101010","110001","111111"};
	while(k != -1){
		k = k%6;
		if(k==0){k=6;}
		desired_state[k-1] = '1';
		cin >> k;
	}
	cin >> k;
	while(k != -1){
		k = k%6;
		if(k==0){k=6;}
		if(desired_state[k-1] == '1'){
			cout <<"Impossible\n";
			return 0;
		}
		desired_state[k-1] = '0';//desired_state[k-1] = "0" will throw error '0' is char but "0" is string
		cin >> k;
	}
	vector<string> possible_states;
	for(int j=0;j<8;j++){
		//if((c&1 && j==7) || (c==1 && (j==1 || j == 4 || j ==6)))continue; will break in n=20 c=3 -1 -1
		if(c==1 && (j==1 || j == 4 || j ==6 || j ==7))continue; 
		string state = all_states[j];
		bool flag = true;
		for(int i=0;i<6;i++){
			if(desired_state[i]=='*')continue;
			if(desired_state[i]!=state[i]){
				flag = false;
				break;
			}
		}
		if(flag){
			possible_states.push_back(state);
		}
	}
	p = possible_states.size();
	if(p == 0){
		cout <<"Impossible\n";
		return 0;
	}
	for(int i=0;i<p;i++){
		string res;
		int m = n/6, pad = n%6;
		for(int l=0;l<m;l++){
			res += possible_states[i];
		}
		for(int l=0;l<pad;l++){
			res.push_back(possible_states[i][l]);
		}
		cout << res<<"\n";
	}
 
	return 0;
} 