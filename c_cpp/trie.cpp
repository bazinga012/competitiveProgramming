#include <iostream>
#include <unordered_map>
using namespace std;

/* Please check python also */
struct Trie
{
    bool isEndOfWord;
    unordered_map<char, Trie *> map;
};

Trie *getNewTrieNode()
{
    Trie *node = new Trie;
    node->isEndOfWord = false;
    return node;
}

void insert(Trie *&root, const string &str)
{
    if (root == nullptr)
    {
        root = getNewTrieNode();
    }
    Trie *temp = root;
    for (int i = 0; i < str.length(); i++)
    {
        char x = str[i];
        if (temp->map.find(x) == temp->map.end())
        {
            temp->map[x] = getNewTrieNode();
        }
        temp = temp->map[x];
    }
    temp->isEndOfWord = true;
}

bool search(Trie *root, const string &str)
{
    if (root == nullptr)
    {
        return false;
    }
    Trie *curr = root;
    Trie *temp;
    for (int i = 0; i < str.length(); i++)
    {
        temp = curr->map.find(str[i]);
        if (temp == curr->map.end())
        {
            return false;
        }
        curr = temp;
    }
    return temp->isEndOfWord;
}
