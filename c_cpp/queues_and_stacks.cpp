#include <queue>
#include <deque>
#include <stack>

queue<int> Q;
Q.push(1);
Q.empty(); //check if Q is empty
Q.front();
Q.pop(); // pop from front
Q.push(4);
Q.back();

deque<int> dQ;
dQ.push_back(5);
dQ.front();
dQ.back();
dQ.push_front(5);
dQ.pop_front();
dQ.pop_back();

stack<int> S;
S.push(4);
S.top();
S.empty();
S.pop();