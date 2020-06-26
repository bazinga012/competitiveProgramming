#include <queue>
#include <vector>
#include <utility> //pair
class prioritize
{
public:
    bool operator()(const ii &p1, const ii &p2)
    {
        return p1.second < p2.second;
    }
};
class prioritize1
{
public:
    bool operator()(const ii &p1, const ii &p2)
    {
        return p2.second < p1.second;
    }
};

typedef pair<int, int> ii;
typedef vector<ii> vii;

priority_queue<ii> Q1;                   //max heap  in pair accor to first value in case of clash last added
priority_queue<ii, vii, greater<ii>> Q2; //min heap in pair accor to first value in case of clash first added

priority_queue<int> q;                            //max heap  in case of clash last added
priority_queue<int, vector<int>, greater<int>> q; //max heap  in case of clash last added

priority_queue<ii, vii, prioritize> Q3;  //max heap in pair accor to second value in case of clash last added
priority_queue<ii, vii, prioritize1> Q4; //min heap in pair accor to second value in case of clash first added

Q1.top();
Q1.pop();
Q1.empty();