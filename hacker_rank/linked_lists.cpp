/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked list in the below method.
*/
// https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem
#include <iostream>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
};
Node *Insert(Node *head, int data)
{
  // Complete this method
  Node *node = new Node;
  node->data = data;
  node->next = NULL;
  if (head != NULL)
  {
    node->next = head;
  }
  head = node;
  return head;
}

Node *Reverse(Node *head)
{
  // Complete this method
  if (head == NULL)
  {
    return head;
  }
  Node *first = head;
  Node *rest = first->next;
  if (rest == NULL)
  {
    return head;
  }
  rest = Reverse(rest);
  first->next->next = first;
  first->next = NULL;
  head = rest;
  return head;
}

void ReversePrint(Node *head)
{
  // This is a "method-only" submission.
  // You only need to complete this method.
  if (head == NULL)
  {
    return;
  }
  else
  {
    ReversePrint(head->next);
    printf("%d\n", head->data);
  }
}

Node *Delete(Node *head, int position)
{
  // Complete this method
  if (head == NULL || (head->next == NULL && position == 0))
  {
    head = NULL;
  }
  else
  {
    int l = 0;
    Node *curr = head;
    Node *parent = NULL;
    if (position == 0)
    {
      Node *curr = head;
      head = head->next;
    }
    else
    {
      while (l != position)
      {
        parent = curr;
        curr = curr->next;
        l++;
      }
      parent->next = curr->next;
    }
    delete curr;
  }
  return head;
}

Node *InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function.
  Node *node = new Node;
  node->data = data;
  node->next = NULL;
  Node *curr = head;
  Node *parent = NULL;
  int l = 0;

  if (head == NULL)
  {
    head = node;
    return head;
  }
  if (position == 0)
  {
    node->next = head;
    head = node;
    return head;
  }
  while (l != position)
  {
    parent = curr;
    curr = curr->next;
    l++;
  }
  parent->next = node;
  node->next = curr;
  return head;
}

Node *InsertTail(Node *head, int data)
{
  // Complete this method
  Node *node = new Node;
  node->data = data;
  node->next = NULL;
  if (head == NULL)
  {
    head = node;
  }
  else
  {
    Node *curr = head;
    while (curr->next != NULL)
    {
      curr = curr->next;
    }
    curr->next = node;
  }
  return head;
}

void Print(Node *head)
{
  // This is a "method-only" submission.
  // You only need to complete this method.
  Node *curr = head;
  while (curr != NULL)
  {
    printf("%d\n", curr->data);
    curr = curr->next;
  }
}
