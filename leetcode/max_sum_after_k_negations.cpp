#include <vector>
#include <queue>
using namespace std;
// https://leetcode.com/contest/weekly-contest-127/problems/maximize-sum-of-array-after-k-negations/
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
        for(int i=0;i<A.size();i++){
            q.push({A[i], i});
        }
        for(int i=0;i<K;i++){
            pair<int,int> p = q.top(); q.pop();
            q.push({-p.first,p.second});
            A[p.second] = -p.first;
        }
        int s=0;
        for(int i=0;i<A.size();i++){
            s+=A[i];
        }
        return s;
    }
};