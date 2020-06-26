#include <queue>
#include <deque>
#include <list>
#include <stack>
using namespace std;
int main()
{
    queue<int, std::list<int>> Q;
    Q.push(1);
    Q.empty(); //check if Q is empty
    Q.front();
    Q.pop(); // pop from front
    Q.push(4);
    Q.back();

    deque<int> dQ;
    dQ.push_back(5);
    dQ.front();
    dQ.back();
    dQ.push_front(5);
    dQ.pop_front();
    dQ.pop_back();

    stack<int> S;
    S.push(4);
    S.top();
    S.empty();
    S.pop();
    return 0;
}
//sort stack
stack<int> sortStack(stack<int> s)
{
    stack<int> aux1, aux2;
    while (!s.empty())
    {
        while (!aux2.empty() && aux2.top() < s.top())
        {
            aux1.push(aux2.top());
            aux2.pop();
        }
        while (aux1.empty() || (s.top() >= aux1.top()))
        {
            aux1.push(s.top());
            s.pop();
        }
        if (!s.empty())
        {
            while (!aux1.empty() && aux1.top() > s.top())
            {
                aux2.push(aux1.top());
                aux1.pop();
            }
            aux1.push(s.top());
            s.pop();
        }
    }
    while (!aux2.empty())
    {
        aux1.push(aux2.top());
        aux2.pop();
    }
    return aux1;
}
//stacks using 2 queues

// the celebrity problem

// check mirror in n-ary tree

// next larger element

// paranthesis checker

// print lead nodes from preorder traversal of bst

// longest valid parenthesis

// get min element from stack

// decode the string

// max of min for every window size

// immediate smaller element

// valid substring

// max rectangle

// queue using two stacks

// infix to postfix

// preorder to postorder

// implement stacks using queue

// max rectangular area under histogram

/* 
Queue using stacks
    Method 1 (By making enQueue operation costly) 
        enQueue(q, x):

        While stack1 is not empty, push everything from stack1 to stack2.
        Push x to stack1 (assuming size of stacks is unlimited).
        Push everything back to stack1.
        Here time complexity will be O(n)

        deQueue(q):

        If stack1 is empty then error
        Pop an item from stack1 and return it
        Here time complexity will be O(1)
    
    Method 2 (By making deQueue operation costly)
        enQueue(q,  x)
            1) Push x to stack1 (assuming size of stacks is unlimited).
                Here time complexity will be O(1)

        deQueue(q)
            1) If both stacks are empty then error.
            2) If stack2 is empty
                While stack1 is not empty, push everything from stack1 to stack2.
            3) Pop the element from stack2 and return it.
            Here time complexity will be O(n)
    
    Method 3 (Queue can also be implemented using one user stack and one Function Call Stack.)
        enQueue(x)
            1) Push x to stack1.

        deQueue:
            1) If stack1 is empty then error.
            2) If stack1 has only one element then return it.
            3) Recursively pop everything from the stack1, store the popped item 
                in a variable res,  push the res back to stack1 and return res
 */

/* 
Stack using queues
    Method 1 (By making push operation costly)
        push(s, x) operation’s step are described below:
            Enqueue x to q2
            One by one dequeue everything from q1 and enqueue to q2.
            Swap the names of q1 and q2

        pop(s) operation’s function are described below:
        Dequeue an item from q1 and return it.
    
    Method 2 (By making pop operation costly)
    push(s, x) operation:
        Enqueue x to q1 (assuming size of q1 is unlimited).
    
    pop(s) operation:
        One by one dequeue everything except the last element from q1 and enqueue to q2.
        Dequeue the last item of q1, the dequeued item is result, store it.
        Swap the names of q1 and q2
        Return the item stored in step 2.
 */