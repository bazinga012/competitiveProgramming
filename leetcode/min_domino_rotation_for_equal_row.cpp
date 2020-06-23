#include <vector>
#include <bitset>
using namespace std;
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        bitset<20000> bitA[6];
        bitset<20000> bitB[6];
        int size = A.size();
        for(int i=0;i<size;i++){
         bitA[A[i]-1][i] = 1;   
        }
        
        for(int i=0;i<size;i++){
         bitB[B[i]-1][i] = 1;   
        }
        
        int m = INT_MAX;
        for(int i=0;i<6;i++){
            if((bitA[i] | bitB[i]).count() == size){
                int p = size - ((bitA[i].count() > bitB[i].count()) ? bitA[i].count() : bitB[i].count());
                if(p<m)m=p;
            }
        }
        return (m==INT_MAX) ? -1 : m;
   }
};