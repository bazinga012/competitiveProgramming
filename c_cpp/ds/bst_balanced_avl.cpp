#include <iostream>
using namespace std;

/* 
Why balanced binary search trees: 
Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. 
The cost of these operations may become O(n) for a skewed Binary tree. 
If we make sure that height of the tree remains O(Logn) after every insertion and deletion,
 then we can guarantee an upper bound of O(Logn) for all these operations. 
The height of a Red-Black tree is always O(Logn) where n is the number of nodes in the tree. 
*/

// An AVL tree node
class Node
{
public:
  int key;
  Node *left;
  Node *right;
  int height;
};

Node *newNode(int key)
{
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int height(Node *N)
{
  if (N == NULL)
    return 0;
  return N->height;
}

int getBalance(Node *N)
{
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

Node *rightRotate(Node *y)
{
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left),
                  height(y->right)) +
              1;
  x->height = max(height(x->left),
                  height(x->right)) +
              1;

  return x;
}

Node *leftRotate(Node *x)
{
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left),
                  height(x->right)) +
              1;
  y->height = max(height(y->left),
                  height(y->right)) +
              1;

  return y;
}

Node *ensureBalance(Node *node)
{
  int balance = getBalance(node);
  // If this node becomes unbalanced,
  // then there are 4 cases

  // Left Left Case
  if (balance > 1 &&
      getBalance(node->left) >= 0)
    return rightRotate(node);

  // Left Right Case
  if (balance > 1 &&
      getBalance(node->left) < 0)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Right Case
  if (balance < -1 &&
      getBalance(node->right) <= 0)
    return leftRotate(node);

  // Right Left Case
  if (balance < -1 &&
      getBalance(node->right) > 0)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

Node *insert(Node *node, int key)
{
  /* 1. Perform the normal BST insertion */
  if (node == NULL)
    return (newNode(key));

  if (key <= node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  /* 2. Update height of this ancestor node */
  node->height = 1 + max(height(node->left),
                         height(node->right));

  return ensureBalance(node);
}

Node *minValueNode(Node *node)
{
  Node *current = node;

  /* loop down to find the leftmost leaf */
  while (current->left != NULL)
    current = current->left;

  return current;
}

Node *deleteNode(Node *root, int key)
{

  // STEP 1: PERFORM STANDARD BST DELETE
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else
  {
    // node with only one child or no child
    if ((root->left == NULL) ||
        (root->right == NULL))
    {
      Node *temp = root->left ? root->left : root->right;

      // No child case
      if (temp == NULL)
      {
        temp = root;
        root = NULL;
      }
      else             // One child case
        *root = *temp; // Copy the contents of
                       // the non-empty child
      free(temp);
    }
    else
    {
      // node with two children: Get the inorder
      // successor (smallest in the right subtree)
      Node *temp = minValueNode(root->right);

      // Copy the inorder successor's
      // data to this node
      root->key = temp->key;

      // Delete the inorder successor
      root->right = deleteNode(root->right,
                               temp->key);
    }
  }

  // If the tree had only one node
  // then return
  if (root == NULL)
    return root;

  // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
  root->height = 1 + max(height(root->left),
                         height(root->right));

  // STEP 3: GET THE BALANCE FACTOR OF
  // THIS NODE (to check whether this
  // node became unbalanced)
  int balance = getBalance(root);

  return ensureBalance(root);
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void preOrder(Node *root)
{
  if (root != NULL)
  {
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

// Driver Code
int main()
{
  Node *root = NULL;

  /* Constructing tree given in  
    the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  /* The constructed AVL Tree would be  
                30  
            / \  
            20 40  
            / \ \  
        10 25 50  
    */
  cout << "Preorder traversal of the "
          "constructed AVL tree is \n";
  preOrder(root);

  return 0;
}