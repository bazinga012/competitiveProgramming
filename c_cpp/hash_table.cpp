#include <unordered_map>

unordered_map<int, bool> myTable;
myTable[5] = true;
myTable.find(5);       //find key 5 in myTable returns an iterator to it if found else will be equal to myTable.end()
myTable.count(5) == 1; //count members with given key since only one key can exist with given value so checks if 5 exists in myTable
unordered_map<Key, T>::iterator it;
(*it).first;  // the key value (of type Key)
(*it).second; // the mapped value (of type T)
(*it);        // the "element value" (of type pair<const Key,T>)
it->first;
it->second;