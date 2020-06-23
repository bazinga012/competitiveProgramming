// https://leetcode.com/contest/weekly-contest-127/problems/construct-binary-search-tree-from-preorder-traversal/
#include <iostream>
#include <vector>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{

public:
    void bstFromPreorderC(TreeNode **root, vector<int> &preorder, int *i, int l, int h)
    {
        if ((*i) >= preorder.size())
            return;
        if (preorder[*i] < l || preorder[*i] > h)
            return;
        TreeNode *nn = new TreeNode(preorder[*i]);
        *root = nn;
        (*i)++;
        bstFromPreorderC(&((*root)->left), preorder, i, l, (*root)->val);
        bstFromPreorderC(&((*root)->right), preorder, i, ((*root)->val) + 1, h);
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        if (preorder.size() == 0)
            return NULL;
        TreeNode *root = NULL;
        int i = 0;
        bstFromPreorderC(&root, preorder, &i, INT_MIN, INT_MAX);
        return root;
    }
};