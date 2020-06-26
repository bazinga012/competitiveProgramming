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
    Trie *curr = root;
    for (int i = 0; i < str.length(); i++)
    {
        char x = str[i];
        if (curr->map.find(x) == curr->map.end())
        {
            curr->map[x] = getNewTrieNode();
        }
        curr = curr->map[x];
    }
    curr->isEndOfWord = true;
}

bool search(Trie *root, const string &str)
{
    if (root == nullptr)
    {
        return false;
    }
    Trie *curr = root;
    for (int i = 0; i < str.length(); i++)
    {
        if (curr->map.find(str[i]) == (curr->map).end())
        {
            return false;
        }
        curr = curr->map[str[i]];
    }
    return curr->isEndOfWord;
}
