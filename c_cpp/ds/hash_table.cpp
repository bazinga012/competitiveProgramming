#include <unordered_map>
using namespace std;
int main()
{
    /* 
    unordered_map vs map :
        map (like set) is an ordered sequence of unique keys whereas in unordered_map key can be stored in any order, so unordered.
        Map is implemented as balanced tree structure that is why it is possible to maintain an order between the elements 
        (by specific tree traversal). Time complexity of map operations is O(Log n) while for unordered_map, it is O(1) on average. 
    */

    /* 
    https://codeforces.com/blog/entry/21853
    unordered_map<pair<int,int>,int>mp; //You will get Compilation Error!
    struct HASH{
        size_t operator()(const pair<int,int>&x)const{
            return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
        }
    };
    unordered_map<pair<int,int>,int,HASH>mp;
    */

    unordered_map<int, bool> myTable;
    myTable[5] = true;
    myTable.find(5);       //find key 5 in myTable returns an iterator to it if found else will be equal to myTable.end()
    myTable.count(5) == 1; //count members with given key since only one key can exist with given value so checks if 5 exists in myTable
    //unordered_map<Key, T>::iterator it;
    unordered_map<int, bool>::iterator it;
    (*it).first;  // the key value (of type Key)
    (*it).second; // the mapped value (of type T)
    (*it);        // the "element value" (of type pair<const Key,T>)
    it->first;
    it->second;
    return 0;
}
