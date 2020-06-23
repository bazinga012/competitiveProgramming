#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void getAtDistK(TreeNode *node, int k, vector<int> &res)
    {
        if (node == NULL)
            return;
        if (k == 0)
        {
            res.push_back(node->val);
            return;
        }
        getAtDistK(node->left, k - 1, res);
        getAtDistK(node->right, k - 1, res);
    }

    void getAtDistKMaster(TreeNode *root, TreeNode *target, int k, vector<int> &res, int &d)
    {
        if (root == NULL)
            return;
        if (root == target)
        {
            getAtDistK(root, k, res);
            d = 1;
            return;
        }
        getAtDistKMaster(root->left, target, k, res, d);
        if (d != -1)
        {
            if (d == k)
            {
                res.push_back(root->val);
                d++;
                return;
            }
            if (k - d >= 0)
                getAtDistK(root->right, k - d - 1, res);
            d++;
            return;
        }
        getAtDistKMaster(root->right, target, k, res, d);
        if (d != -1)
        {
            if (d == k)
            {
                res.push_back(root->val);
                d++;
                return;
            }
            if (k - d > 0)
                getAtDistK(root->left, k - d - 1, res);
            d++;
            return;
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        vector<int> nodes;
        if (root == NULL)
            return nodes;
        int d = -1;
        getAtDistKMaster(root, target, K, nodes, d);
        return nodes;
    }
};