#include <iostream>
using namespace std;


/* https://web.stanford.edu/class/archive/cs/cs166/cs166.1146/lectures/02/Small02.pdf */
/* 
RedBlackTree:
  Red-Black Tree is a self-balancing Binary Search Tree (BST) where every node follows following rules.

  1) Every node has a color either red or black.

  2) Root of tree is always black.

  3) There are no two adjacent red nodes (A red node cannot have a red parent or red child).

  4) Every path from a node (including root) to any of its descendant NULL node has the same number of black nodes.


 */

/* 
https://www.geeksforgeeks.org/red-black-tree-set-2-insert/

https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
Implementation Note:
r = root
n = newNode
p = parent
gp = grand_parent
u = uncle (sibling of parent)

1) r.color = black #always. 
2) n.color = red # always. 
3) perform standard bst insert of n
4) n.color == p.color == red # voilation of property 3.
    Fix:
      u.color == red
          gp.color = red
          u.color = p.color = black
          recur_fix_for(gp)
      else:
        gp.left == p and p.left == n (left left case):
          right_rotate(gp)
          swap(gp, p)
        gp.left == p and p.right == n (left right case):
          left_rotate(p)
          right_rotate(gp)
          swap(gp, n)
        gp.right == p and p.right == n (right right case):
          left_rotate(gp)
          swap(gp, p)
        gp.right == p and  p.left == n (right left case)
          right_rotate(p)
          left_rotate(gp)
          swap(gp, n)

else part can be simplified
    gp.left == p and p.right == n:
      # (left right case)
      left_rotate(p)
      n = n.left
      # now its equivalent to left left case
    
    gp.right == p and  p.left == n:
      # (right left case)
      right_rotate(p)
      n = n.right 
      # now it's equivalent to right right case
 */


enum color_t { BLACK, RED };

struct Node {
  Node* parent;
  Node* left;
  Node* right;
  enum color_t color;
  int key;
};

Node* GetParent(Node* n) {
  // Note that parent is set to null for the root node.
  return n == nullptr ? nullptr : n->parent;
}

Node* GetGrandParent(Node* n) {
  // Note that it will return nullptr if this is root or child of root
  return GetParent(GetParent(n));
}

Node* GetSibling(Node* n) {
  Node* p = GetParent(n);

  // No parent means no sibling.
  if (p == nullptr) {
    return nullptr;
  }

  if (n == p->left) {
    return p->right;
  } else {
    return p->left;
  }
}

Node* GetUncle(Node* n) {
  Node* p = GetParent(n);

  // No parent means no uncle
  return GetSibling(p);
}

void RotateLeft(Node* n) {
  Node* nnew = n->right;
  Node* p = GetParent(n);
  assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.
  n->right = nnew->left;
  nnew->left = n;
  n->parent = nnew;
  // Handle other child/parent pointers.
  if (n->right != nullptr) {
    n->right->parent = n;
  }

  // Initially n could be the root.
  if (p != nullptr) {
    if (n == p->left) {
      p->left = nnew;
    } else if (n == p->right) {
      p->right = nnew;
    }
  }
  nnew->parent = p;
}

void RotateRight(Node* n) {
  Node* nnew = n->left;
  Node* p = GetParent(n);
  assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.

  n->left = nnew->right;
  nnew->right = n;
  n->parent = nnew;

  // Handle other child/parent pointers.
  if (n->left != nullptr) {
    n->left->parent = n;
  }

  // Initially n could be the root.
  if (p != nullptr) {
    if (n == p->left) {
      p->left = nnew;
    } else if (n == p->right) {
      p->right = nnew;
    }
  }
  nnew->parent = p;
}

void InsertCase1(Node* n) {
  n->color = BLACK; // root node is always black
}

void InsertCase2(Node* n) {
  // Do nothing since tree is still valid.
  return;
}


void InsertRepairTree(Node* n) {
  if (GetParent(n) == nullptr) {
    InsertCase1(n);
  } else if (GetParent(n)->color == BLACK) {
    InsertCase2(n);
  } else if (GetUncle(n) != nullptr && GetUncle(n)->color == RED) {
    InsertCase3(n);
  } else {
    InsertCase4(n);
  }
}

void InsertCase3(Node* n) {
  GetParent(n)->color = BLACK;
  GetUncle(n)->color = BLACK;
  GetGrandParent(n)->color = RED;
  InsertRepairTree(GetGrandParent(n));
}

void InsertCase4Step2(Node* n) {
  Node* p = GetParent(n);
  Node* g = GetGrandParent(n);

  if (n == p->left) {
    RotateRight(g);
  } else {
    RotateLeft(g);
  }
  p->color = BLACK;
  g->color = RED;
}

void InsertCase4(Node* n) {
  Node* p = GetParent(n);
  Node* g = GetGrandParent(n);

  if (n == p->right && p == g->left) {
    RotateLeft(p);
    /* tricky: to make equivalent to ll case. Just draw (N and P are swapped to make equal to ll case.) Now same color swapping will happen */
    n = n->left;
  } else if (n == p->left && p == g->right) {
    RotateRight(p);
    n = n->right; // tricky: to make equivalent to rr case. Now same color swapping will happen
  }
  InsertCase4Step2(n);
}




/* Deletion */
/* https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/ */
/* In delete operation, we check color of sibling to decide the appropriate case. */
/*  the main violated property is, change of black height in subtrees as deletion of
 a black node may cause reduced black height in one root to leaf path. */


/* 
v = node to be deleted
peform_standard_bst_delete(v) 
    When we perform standard delete operation in BST, we always end up deleting a node which is either leaf 
    or has only one child (For an internal node, we copy the successor and then recursively call delete for successor, 
    successor is always a leaf node or a node with one child). 

i = inorder_successor_of(v.value) # to get inorder_successor go to the leftmost node of right subtree of v.value
swap(v.value, i.value)
v = i

v can either be a leaf or atmost can have once child (u)

u == NULL: 
  u.color = black# color of NULL is always black in redblack tree

u.color == v.color == red:
  raise Exception # v is parent of u and two consecutive reds are not allowed in red-black tree.

u.color != v.color:
  # that means either v is red or u is red both can't be red
  swap(v.value, u.value)
  free(u)

u.color == v.color == black:
  swap(v.value, u.value)
  free(u)

  v.double_black = True
  p = parent(v) 
  s = sibling(v)
  if v == root:
    v.double_black  = False
    v.color = black
    return

  if v.double_black and v != root:
    s.color == black:
      (s.left.color == red or s.right.color == red):
        cases
      else:
        s.color = red
        if p.color == black:
          recur_for(p)
    else:
      p.left == v:
        left_rotate(p)
        swap(s.color, p.color)
        swap(p.color, p.right.color)
      p.right == v:
        right_rotate(p)
        swap(s.color, p.color)
        swap(p.color, p.left.color)
*/

/* code in this section will assume that null leaves are represented by actual node objects rather than NULL. */

void ReplaceNode(Node* v, Node* u) {
  u->parent = v->parent;
  if (v == v->parent->left) {
    v->parent->left = u;
  } else {
    v->parent->right = u;
  }
}

void DeleteOneChild(Node* v) {
  // Precondition: v has at most one non-leaf child.
  Node* u = (v->right == nullptr) ? v->left : v->right;
  assert(u);

  ReplaceNode(v, u);
  if (v->color == BLACK) {
    if (u->color == RED) {
      u->color = BLACK;
    } else {
      DeleteCase1(u); // v and u both black
    }
  }
  free(v);
}

void DeleteCase1(Node* v) {
  // if v is root we are done.
  if (v->parent != nullptr) {
    DeleteCase2(v);
  }
}

void DeleteCase2(Node* v) {
  Node* s = GetSibling(v);

  if (s->color == RED) {
      // if s->color == RED p and s.child have to be black (2 reds can't come consecutively)
      // p -> s(red) -> s.child (2 blacks 1 red) vs p -> v -> NULL (3 blacks) voilation
    s->parent->color = RED;
    s->color = BLACK;

    // rotations to not affect tree above p
    if (v == v->parent->left) {
      RotateLeft(v->parent);
    } else {
      RotateRight(v->parent);
    }
  }
  DeleteCase3(v);
}

void DeleteCase3(Node* v) {
  Node* s = GetSibling(v);

  if ((v->parent->color == BLACK) && (s->color == BLACK) &&
      (s->left->color == BLACK) && (s->right->color == BLACK)) {
    s->color = RED;
    DeleteCase1(v->parent);
  } else {
    DeleteCase4(v);
  }
}

void DeleteCase4(Node* n) {
  Node* s = GetSibling(n);

  if ((n->parent->color == RED) && (s->color == BLACK) &&
      (s->left->color == BLACK) && (s->right->color == BLACK)) {
    s->color = RED;
    n->parent->color = BLACK;
  } else {
    DeleteCase5(n);
  }
}

void DeleteCase5(Node* n) {
  Node* s = GetSibling(n);

  // This if statement is trivial, due to case 2 (even though case 2 changed
  // the sibling to a sibling's child, the sibling's child can't be red, since
  // no red parent can have a red child).
  if (s->color == BLACK) {
    // The following statements just force the red to be on the left of the
    // left of the parent, or right of the right, so case six will rotate
    // correctly.
    if ((n == n->parent->left) && (s->right->color == BLACK) &&
        (s->left->color == RED)) {
      // This last test is trivial too due to cases 2-4.
      s->color = RED;
      s->left->color = BLACK;
      RotateRight(s);
    } else if ((n == n->parent->right) && (s->left->color == BLACK) &&
               (s->right->color == RED)) {
      // This last test is trivial too due to cases 2-4.
      s->color = RED;
      s->right->color = BLACK;
      RotateLeft(s);
    }
  }
  DeleteCase6(n);
}

void DeleteCase6(Node* n) {
  Node* s = GetSibling(n);

  s->color = n->parent->color;
  n->parent->color = BLACK;

  if (n == n->parent->left) {
    s->right->color = BLACK;
    RotateLeft(n->parent);
  } else {
    s->left->color = BLACK;
    RotateRight(n->parent);
  }
}