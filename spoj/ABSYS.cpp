#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(){
	int t;
	cin >>t ;
	string inkBlot = "machula";
	while(t--){
		string s1,s2,s3,s4,s5;
		cin >> s1 >> s2 >> s3 >> s4 >> s5;
		//s1, s3, s5
		int inkBlotIdx = strstr(s1.c_str(), inkBlot.c_str()) ? 1 : ( strstr(s3.c_str(), inkBlot.c_str()) ? 3 : 5 );
		if(inkBlotIdx == 1){
			cout << atoi(s5.c_str()) - atoi(s3.c_str()) << " + "<< s3 << " = " << s5 << "\n";
		}else if(inkBlotIdx == 3){
			cout << s1 << " + " << atoi(s5.c_str()) - atoi(s1.c_str()) << " = " << s5 << "\n";
		}else{
			cout << s1 << " + " << s3 << " = " <<atoi(s1.c_str()) + atoi(s3.c_str()) << "\n";
		}
	}
	return 0;
} 