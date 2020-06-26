#include <ctype.h>
#include <map>
#include <iostream>
using namespace std;
int directions[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

struct trieNode
{
    char ch;
    int refC; // #words ending at this node
    struct trieNode *arr[26];
};
struct trieNode *newNode(char ch)
{
    trieNode *nn = (struct trieNode *)malloc(sizeof(struct trieNode));
    nn->ch = ch;
    nn->refC = 0;
    for (int i = 0; i < 26; i++)
    {
        nn->arr[i] = NULL;
    }
}

void insertWord(string word, bool lower, struct trieNode **trie)
{
    int n = word.length();
    int k = 0;
    struct trieNode *prev = *trie;
    char ch = 'a';
    if (!lower)
    {
        ch = 'A';
    }
    for (int i = 0; i < n; i++)
    {
        if (prev->arr[word[i] - ch] == NULL)
            prev->arr[word[i] - ch] = newNode(word[i]);
        prev = prev->arr[word[i] - ch];
    }
    prev->refC += 1;
}

bool searchWord(string word, bool lower, struct trieNode *trie)
{
    int n = word.length();
    int k = 0;
    struct trieNode *prev = trie;
    char ch = 'a';
    if (!lower)
    {
        ch = 'A';
    }
    for (int i = 0; i < n; i++)
    {
        if (prev->arr[word[i] - ch] == NULL)
            return false;
        prev = prev->arr[word[i] - ch];
    }
    if (prev->refC == 0)
        return false;
    return true;
}
bool deleteWord(string word, bool lower, struct trieNode **trie)
{
    char ch = 'a';
    if (!lower)
    {
        ch = 'A';
    }
    if ((*trie)->arr[word[0] - ch] == NULL)
        return false;
    struct trieNode **node = &((*trie)->arr[word[0] - ch]);
    if (word.length() == 1)
    {
        if ((*node)->refC == 0)
            return false;
        (*node)->refC -= 1;
        if ((*node)->refC == 0)
        {
            free(*node);
            *node = NULL;
        }
        return true;
    }
    return deleteWord(word.substr(1), lower, node);
}

void find_word(struct trieNode *trie, char **boggle, bool **visited, int i, int j, int n, int m, char *str, int k, map<string, bool> &solu, bool lower)
{
    char ch = 'a';
    if (!lower)
    {
        ch = 'A';
    }
    if (i < 0 || i >= n || j < 0 || j >= m)
        return;
    if (visited[i][j] == true)
        return;
    if (trie->arr[boggle[i][j] - ch] == NULL)
    {
        return;
    }
    if (trie->arr[boggle[i][j] - ch]->refC > 0)
    {
        str[k] = boggle[i][j];
        str[k + 1] = '\0';
        if (solu.find((string)str) == solu.end())
        {
            string strc = (string)str;
            solu[strc] = 1;
        }
    }
    str[k] = boggle[i][j];
    visited[i][j] = true;
    for (int d = 0; d < 8; d++)
    {
        find_word(trie->arr[boggle[i][j] - ch], boggle, visited, i + directions[d][0], j + directions[d][1], n, m, str, k + 1, solu, lower);
    }
    visited[i][j] = false;
}
void print_trie(struct trieNode *trie, char str[100], int j)
{
    if (trie->refC > 0)
    {
        str[j] = trie->ch;
        str[j + 1] = '\0';
        cout << str << endl;
        return;
    }
    for (int i = 0; i < 26; i++)
    {
        if (trie->arr[i] != NULL)
        {
            str[j] = trie->ch;
            print_trie(trie->arr[i], str, j + 1);
        }
    }
}

int main()
{
    int t, x, n, m;
    string word;
    cin >> t;
    while (t--)
    {
        bool lower = true;
        cin >> x; //number of words in dict
        struct trieNode *trie = newNode('\0');
        for (int i = 0; i < x; i++)
        {
            cin >> word;
            lower = islower(word[0]);
            insertWord(word, lower, &trie);
        }
        cin >> n >> m;
        char **boggle = (char **)malloc(sizeof(char *) * n);
        for (int i = 0; i < n; i++)
        {
            boggle[i] = (char *)malloc(sizeof(char) * m);
        }
        bool **visited = (bool **)malloc(sizeof(bool *) * n);
        for (int i = 0; i < n; i++)
        {
            visited[i] = (bool *)malloc(sizeof(bool) * m);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> boggle[i][j];
                visited[i][j] = false;
            }
        }
        map<string, bool> solu;
        char str[100];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                find_word(trie, boggle, visited, i, j, n, m, str, 0, solu, lower);
                visited[i][j] = false;
            }
        }
        if (solu.size() == 0)
        {
            cout << -1;
        }
        else
        {
            map<string, bool>::iterator itr;
            for (itr = solu.begin(); itr != solu.end(); itr++)
            {
                cout << itr->first << " ";
            }
        }
        cout << endl;
    }
    return 0;
}