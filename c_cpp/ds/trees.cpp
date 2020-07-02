#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <stack>
using namespace std;
struct bTreeNode
{
    bTreeNode *left;
    bTreeNode *right;
    int val;
};

struct node
{
    int data;
    node *left, *right;
};

node *newNode(int data)
{
    node *nn = (node *)malloc(sizeof(node));
    nn->data = data;
    nn->left = nn->right = NULL;
    return nn;
}

node *insertNode(node *root, node *nn)
{
    if (root == NULL)
        return nn;
    if (nn->data > root->data)
    {
        root->right = insertNode(root->right, nn);
    }
    else
    {
        root->left = insertNode(root->left, nn);
    }
    return root;
}

void printInorder(node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

void printPreorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printInorder(root->left);
    printInorder(root->right);
}

void printPostorder(node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    printInorder(root->right);
    cout << root->data << " ";
}

void printLevelorder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        node *n = Q.front();
        Q.pop();
        cout << n->data << "";
        if (n->left != NULL)
            Q.push(n->left);
        if (n->right != NULL)
            Q.push(n->right);
    }
}

void spiralOrderTrav(node *root)
{
    if (root == NULL)
        return;
    stack<node *> s1, s2;
    s1.push(root);
    node *temp;
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            printf(" %d ", temp->data);
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }
        while (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            printf(" %d ", temp->data);
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}

// Pre: preorder traversal;  preLN[i]: leaf/or non leaf
void constructBT(node **root, int *i, int n, int *pre, char *preLN)
{
    if ((*i) >= n)
        return;
    *root = newNode(pre[*i]);
    (*i)++;
    if (preLN[(*i) - 1] == 'L')
        return;
    constructBT(&((*root)->left), i, n, pre, preLN);
    constructBT(&((*root)->right), i, n, pre, preLN);
}

/* BST from preorder */
void bstFromPreorderC(node **root, vector<int> &preorder, int *i, int l, int h)
{
    if ((*i) >= preorder.size())
        return;
    if (preorder[*i] < l || preorder[*i] > h)
        return;
    node *nn = newNode(preorder[*i]);
    *root = nn;
    (*i)++;
    bstFromPreorderC(&((*root)->left), preorder, i, l, (*root)->data);
    bstFromPreorderC(&((*root)->right), preorder, i, ((*root)->data) + 1, h);
}

/* TopView */
void topView(struct node *root)
{
    if (root == NULL)
        return;
    map<int, bool> visited = map<int, bool>();
    queue<pair<node *, int>> Q;
    Q.push(pair<node *, int>(root, 0));
    pair<node *, int> n;
    while (!Q.empty())
    {
        n = Q.front();
        Q.pop();
        if (visited.find(n.second) == visited.end())
        {
            cout << (n.first)->data << " ";
            visited[n.second] = true;
        }
        if ((n.first)->left != NULL)
            Q.push(pair<node *, int>((n.first)->left, n.second - 1));
        if ((n.first)->right != NULL)
            Q.push(pair<node *, int>((n.first)->right, n.second + 1));
    }
}

/* BottomView */
typedef pair<node *, int> pni;
void bottomView(node *root)
{
    if (root == NULL)
        return;
    map<int, int> visited = map<int, int>();
    int minVl = 0, maxVl = 0;
    queue<pni> Q;
    pni n;
    Q.push(pni(root, 0));
    while (!Q.empty())
    {
        n = Q.front();
        Q.pop();
        visited[n.second] = (n.first)->data;
        if ((n.first)->left != NULL)
        {
            Q.push(pni((n.first)->left, n.second - 1));
            if (n.second - 1 < minVl)
                minVl = n.second - 1;
        }
        if ((n.first)->right != NULL)
        {
            Q.push(pni((n.first)->right, n.second + 1));
            if (n.second + 1 > maxVl)
                maxVl = n.second + 1;
        }
    }
    for (int i = minVl; i <= maxVl; i++)
    {
        cout << visited[i] << " ";
    }
}

/* RightView */
void rightView(node *root)
{
    if (root == NULL)
        return;
    queue<node *> Q;
    node *n;
    Q.push(root);
    Q.push(NULL);
    while (!Q.empty())
    {
        n = Q.front();
        Q.pop();
        if (n == NULL)
        {
            if (Q.empty())
                break;
            Q.push(NULL);
            continue;
        }
        if (!Q.empty() && Q.front() == NULL)
        {
            cout << n->data << " ";
        }
        if (n->left != NULL)
            Q.push(n->left);
        if (n->right != NULL)
            Q.push(n->right);
    }
}

/* LeftView */
void leftView(node *root)
{
    if (root == NULL)
        return;
    queue<node *> Q;
    node *n;
    Q.push(NULL);
    Q.push(root);
    while (!Q.empty())
    {
        n = Q.front();
        Q.pop();
        if (n == NULL)
        {
            if (Q.empty())
                break;
            n = Q.front();
            Q.pop();
            cout << n->data << " ";
            Q.push(NULL);
        }
        if (n->left != NULL)
            Q.push(n->left);
        if (n->right != NULL)
            Q.push(n->right);
    }
}

/* DiagonalView */
typedef map<int, vector<int>> ivmap;
void digView(node *root, ivmap &sameDNodes, int d)
{
    if (root == NULL)
        return;
    if (sameDNodes.find(d) == sameDNodes.end())
    {
        sameDNodes[d] = vector<int>();
    }
    sameDNodes[d].push_back(root->data);
    digView(root->left, sameDNodes, d + 1);
    digView(root->right, sameDNodes, d);
}
void digViewWrapper(node *root)
{
    ivmap sameDNodes;
    digView(root, sameDNodes, 0);
    int i = 0;
    while (true)
    {
        if (sameDNodes.find(i) == sameDNodes.end())
            break;
        for (int j = 0; j < sameDNodes[i].size(); j++)
        {
            cout << sameDNodes[i][j] << "";
        }
        cout << "\n";
        i++;
    }
}

/* IsBST check */
bool isBst(node *root, int minLim, int maxLim)
{
    if (root == NULL)
        return true;
    if (root->data > maxLim && root->data < minLim)
    {
        return false;
    }
    return (isBst(root->left, minLim, root->data) &&
            isBst(root->right, root->data + 1, maxLim));
}

/* FindInBst */
bool findInBst(node *root, int val)
{
    if (root == NULL)
        return false;
    if (root->data == val)
        return true;
    if (val > root->data)
        return findInBst(root->right, val);
    if (val < root->data)
        return findInBst(root->left, val);
    return false;
}

/* LeastCommonAncestor In BST */
node *compare(node *nd, int val)
{
    if (nd == NULL)
        return NULL;
    if (val > nd->data)
        return nd->right;
    if (val < nd->data)
        return nd->left;
    return nd;
}
node *lcaBst(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    node *f = compare(root, n1);
    node *s = compare(root, n2);
    if (f == s)
    {
        if (f == root)
            return root;
        return lcaBst(f, n1, n2);
    }
    if (findInBst(f, n1) && findInBst(s, n2))
        return root;
    return NULL;
}

/* LeastCommonAncestor in BinaryTree */
void getLCA(node *root, int n1, int n2, node **lca, bitset<2> &searchBits)
{
    if ((*lca) != NULL || root == NULL)
        return;
    if (root->data == n1)
        searchBits[0] = 1;
    if (root->data == n2)
        searchBits[1] = 1;
    if (searchBits.to_ulong() == 3)
    {
        *lca = root;
        return;
    }
    getLCA(root->left, n1, n2, lca, searchBits);
    if (*lca != NULL)
        return;
    if (searchBits.to_ulong() == 3)
    {
        *lca = root;
        return;
    }
    getLCA(root->right, n1, n2, lca, searchBits);
    if (*lca != NULL)
        return;
    if (searchBits.to_ulong() == 3)
    {
        *lca = root;
        return;
    }
}
node *lcaBinary(node *root, int n1, int n2)
{
    node *lca = NULL;
    bitset<2> searchBits;
    getLCA(root, n1, n2, &lca, searchBits);
    return lca;
}

/* MaxDiagonal or Width of BinaryTree */
int customDiameter(node* root, int* h){
    if(root==NULL)return 0;
    int l=0, r=0;
    int ld = customDiameter(root->left, &l);
    int rd = customDiameter(root->right, &r);
    *h = max(l ,r) + 1;
    return max(max(ld, rd), l + 1 + r); 
}

/* Computes the diameter of binary tree with given root.  */
int diameter(node* root) {
    // Your code here
    if(root==NULL)return 0;
    int h = 0;
    return customDiameter(root, &h);
}

/* BST delete node */
node* deleteNode(node* root, int k) 
{
    if (root == NULL) 
        return root; 
   
    if (root->data > k) { 
        root->left = deleteNode(root->left, k); 
        return root; 
    } 
    else if (root->data < k) { 
        root->right = deleteNode(root->right, k); 
        return root; 
    } 
    // root is the node to be deleted. 
    
    if (root->left == NULL) { 
        node* temp = root->right; 
        delete root; 
        return temp; 
    } 
    else if (root->right == NULL) { 
        node* temp = root->left; 
        delete root; 
        return temp; 
    } 
    else { 
  
        node* succParent = root; 
        node* succ = root->right; 
        while (succ->left != NULL) { 
            succParent = succ; 
            succ = succ->left; 
        }  
        if (succParent != root) 
            succParent->left = succ->right; 
        else
            succParent->right = succ->right; 
  
        root->data = succ->data; 
        delete succ;          
        return root; 
    } 
} 