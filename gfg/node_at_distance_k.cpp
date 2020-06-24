#include <iostream>
using namespace std;
// https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

struct node
{
    int data;
    struct node *left, *right;
}; 

/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */
void printkdistanceNodeDown(node *root, int k)
{
    // Your code here
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printkdistanceNodeDown(root->left, k - 1);
    printkdistanceNodeDown(root->right, k - 1);
}
/* Prints all nodes at distance k from a given target node.
 The k distant nodes may be upward or downward.  This function
 Returns distance of root from target node, it returns -1 if target
 node is not present in tree rooted with root. */
int printkdistanceNode(node *root, node *target, int k)
{
    // Your code here
    if (root == NULL)
        return -1;
    if (root->data == target->data)
    {
        printkdistanceNodeDown(root, k);
        return 0;
    }
    int l, r, d;
    l = printkdistanceNode(root->left, target, k);
    if (l != -1)
    {
        d = l + 1;
        if (d == k)
            cout << root->data << " ";
        else
        {
            printkdistanceNodeDown(root->right, k - d - 1);
        }
        return d;
    }
    r = printkdistanceNode(root->right, target, k);
    if (r != -1)
    {
        d = r + 1;
        if (d == k)
            cout << root->data << " ";
        else
        {
            printkdistanceNodeDown(root->left, k - d - 1);
        }
        return d;
    }
    return -1;
}
