#include <iostream>
#include <queue>
#include <deque>
#include <list>
#include <stack>
typedef long long ll;
using namespace std;

/* declarations */
stack<int> sortStack(stack<int> s);

void printStack(stack<int> s);
void printStack2(stack<int> s);

int main()
{
    queue<int, std::list<int>> Q;
    cout << Q.size() << "\n";
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
    S.push(100);
    S.push(30);
    S.push(20);
    S.push(80);
    S.push(25);
    printStack2(sortStack(S));
    return 0;
}

/* print stack */
void printStack(stack<int> s)
{
    if (s.empty())
    {
        return;
    }
    int val = s.top();
    cout << val;
    s.pop();
    printStack(s);
    s.push(val);
}

void printStack2(stack<int> s)
{
    if (s.empty())
    {
        return;
    }
    stack<int> aux;
    int val;
    while (!s.empty())
    {
        val = s.top();
        cout << val;
        s.pop();
        aux.push(val);
    }
    while (!aux.empty())
    {
        s.push(aux.top());
        aux.pop();
    }
}
//sort stack
stack<int> sortStack(stack<int> s)
{
    if (s.size() <= 1)
    {
        return s;
    }
    stack<int> aux;
    int a;
    while (!s.empty())
    {
        a = s.top();
        s.pop();
        while (!aux.empty() && a < aux.top())
        {
            s.push(aux.top());
            aux.pop();
        }
        aux.push(a);
    }
    return aux;
}

/* reverse first k elements in queue */
queue<ll> modifyQueue(queue<ll> q, int k)
{
    //add code here.
    stack<ll> s;
    int i = k;
    while (!q.empty() && i--)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    i = q.size();
    while (i > k)
    {
        q.push(q.front());
        q.pop();
        i--;
    }
    return q;
}

/* min in o(1) time o(n) space
keep additional stack
stack<int> minStack;
*/
void pushInSWithMin(int a, stack<int> s, stack<int> minStack)
{
    //add code here.
    if (minStack.empty() || a <= minStack.top())
    {
        minStack.push(a);
    }
    s.push(a);
}

int popFromSWithMin(stack<int> s, stack<int> minStack)
{
    //add code here.
    if (s.top() == minStack.top())
    {
        minStack.pop();
    }
    s.pop();
}

/* min in o(1) time o(1) space
https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
*/
void pushInSWithMinEff(int x, stack<int> s, int *minStack)
{
    //add code here.
    int minEle = *minStack;
    if (s.empty())
    {
        minEle = x;
        s.push(x);
        *minStack = minEle;
        return;
    }
    if (x >= minEle)
    {
        s.push(x);
    }
    else
    {
        s.push((2 * x) - minEle);
        minEle = x;
    }
    *minStack = minEle;
}

int popFromSWithMinEff(stack<int> s, int *minStack)
{
    //add code here.
    if (s.empty())
        return -1;
    int minEle = *minStack;
    int t = s.top();
    int newMin;
    s.pop();
    if (t < minEle)
    {
        newMin = (2 * minEle) - t;
        t = minEle;
        minEle = newMin;
    }
    if (s.empty())
    {
        minEle = -1;
    }
    *minStack = minEle;
    return t;
}

/*  print-leaf-nodes-from-preorder-traversal-of-bst */
void printLeafNodesFromPreOrderBST(int* preOrder, int n){
    if(n==0)return;
    if(n==1){cout << preOrder[0] << "\n"; return;}
    stack<int> dec_l;
    dec_l.push(0);
    int i=1;
    while(i<n){
        if(preOrder[i] <= preOrder[i-1]){
            dec_l.push(i);
        }else{
            if(dec_l.top() == i-1){
                dec_l.pop();
            }
            if(!dec_l.empty() && (preOrder[i] > preOrder[dec_l.top()])){
                cout << preOrder[i-1] << " ";
            }
            /* maintaining decreasing order */
            while(!dec_l.empty() && preOrder[dec_l.top()] < preOrder[i]){
                dec_l.pop();
            }
            dec_l.push(i);
        }
        i+=1;
    }
    cout << preOrder[n-1] << "\n";
}

void printLeafNodesFromPreOrderBST2(int* preOrder, int n){
    if(n==0)return;
    if(n==1){cout << preOrder[0] << "\n"; return;}
    stack<int> dec_l;
    dec_l.push(0);
    int i=1;
    while(i<n){
        if(preOrder[i] <= preOrder[i-1]){
            dec_l.push(i-1);
        }else{
            if(!dec_l.empty() && (preOrder[i] > preOrder[dec_l.top()])){
                cout << preOrder[i-1] << " ";
            }
            /* maintaining decreasing order */
            while(!dec_l.empty() && preOrder[dec_l.top()] < preOrder[i]){
                dec_l.pop();
            }
            dec_l.push(i);
        }
        i+=1;
    }
    cout << preOrder[n-1] << "\n";
}

/* 
Algorithm for Prefix to Postfix:

Read the Prefix expression in reverse order (from right to left)
If the symbol is an operand, then push it onto the Stack
If the symbol is an operator, then pop two operands from the Stack
Create a string by concatenating the two operands and the operator after them.
string = operand1 + operand2 + operator
And push the resultant string back to Stack
Repeat the above steps until end of Prefix expression.
 */

/* 
Following is algorithm for evaluation postfix expressions.
1) Create a stack to store operands (or values).
2) Scan the given expression and do following for every scanned element.
…..a) If the element is a number, push it into the stack
…..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
3) When the expression is ended, the number in the stack is the final answer
 */

// max rectangular area under histogram
ll maxAreaUnderHistogram(ll *arr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int l[n];
    /*l[i] length of subarray greater than me in left excluding myself*/
    stack<int> inc_l;
    ll m = -1, a, t;
    l[n - 1] = 0;
    for (int i = 0; i < n; i++)
    {
        if (!inc_l.empty())
        {
            t = inc_l.top();
            while (!inc_l.empty() && arr[i] <= arr[t])
            {
                inc_l.pop();
                a = (l[t] + i - t) * (arr[t]); // t to i-1 = r[t] inclusive t can be included in area with height arr[t]
                if (a > m)
                {
                    m = a;
                }
                t = inc_l.empty() ? -1 : inc_l.top();
            }
            l[i] = i - (t + 1);
        }
        else
        {
            l[i] = 0;
        }
        inc_l.push(i);
    }
    if (!inc_l.empty())
    {
        t = inc_l.top();
        int k;
        while (!inc_l.empty())
        {
            k = inc_l.top();
            a = (l[k] + t - k + 1) * (arr[k]); // k(incl) to t(incl) + l[k]  elements of area arr[k]
            if (a > m)
            {
                m = a;
            }
            inc_l.pop();
        }
    }
    return m;
}

ll maxAreaUnderHistogramEff(ll *arr, int n)
{
    if (n == 0)
    {
        return 0;
    }
    /*l[i] length of subarray greater than me in left excluding myself*/
    stack<int> inc_l; // increasing elements stack
    ll m = 0, a, t, l;
    for (int i = 0; i < n; i++)
    {
        if (!inc_l.empty())
        {
            t = inc_l.top();
            while (!inc_l.empty() && arr[i] <= arr[t])
            {
                inc_l.pop();
                l = inc_l.empty() ? t : t - inc_l.top() - 1; // length of subarray greater than t in left of t excluding t
                a = (l + i - t) * (arr[t]);                  // i - t is length of subarray greater than t in right of t including t
                if (a > m)
                {
                    m = a;
                }
                t = inc_l.empty() ? -1 : inc_l.top();
            }
        }
        inc_l.push(i);
    }
    if (!inc_l.empty())
    {
        t = inc_l.top();
        int k;
        while (!inc_l.empty())
        {
            k = inc_l.top();
            inc_l.pop();
            l = inc_l.empty() ? k : k - inc_l.top() - 1;
            a = (l + t - k + 1) * (arr[k]); // k(incl) to t(incl) + l[k]  elements of area arr[k]
            if (a > m)
            {
                m = a;
            }
        }
    }
    return m;
}

int maxRactangularAreaWithAllOne(ll **M, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    int r = maxAreaUnderHistogram(M[0], m);
    int a;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
            {
                M[i][j] += M[i - 1][j];
            }
        }
        a = maxAreaUnderHistogram(M[i], m);
        if (a > r)
        {
            r = a;
        }
    }
    return r;
}

/* Parenthesis checker */
bool isOpening(char ch)
{
    return ch == '{' || ch == '[' || ch == '(';
}

bool isClosing(char ch)
{
    return ch == '}' || ch == ']' || ch == ')';
}

char getParedClosing(char ch)
{
    return ch == '{' ? '}' : (ch == '[' ? ']' : (ch == '(' ? ')' : '\0'));
}
void checkParenthesis(string str)
{
    int n = str.length();
    if (n == 0)
    {
        cout << "balanced\n";
        return;
    }
    stack<char> s;
    string res;
    char ch;
    for (int i = 0; i < n; i++)
    {
        ch = str[i];
        if (isOpening(ch))
        {
            s.push(ch);
        }
        else
        {
            if (s.empty() || (isOpening(s.top()) && getParedClosing(s.top()) != ch))
            {
                cout << "not balanced\n";
                return;
            }
            s.pop();
        }
    }
    cout << ((s.size() > 0) ? "not balanced\n" : "balanced\n");
}

/* Print Next Greater */
void printNextGreater(ll *arr, int n)
{
    if (n == 0)
        return;
    stack<ll> s, ans;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] >= s.top())
        {
            s.pop();
        }
        ans.push((s.empty() ? -1 : s.top()));
        s.push(arr[i]);
    }
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << "\n";
}

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


/* queues */

/* minimum-cost-of-ropes */
ll minCostForRopeJoining(int* arr, int n){
    if(n==0 || n==1)return 0;
    priority_queue<ll, vector<ll> ,greater<ll> > q;
    for(int i=0; i<n ;i++){
	       q.push(arr[i]);	    
	}
	ll r1, r2, cost = 0;
	while(q.size() > 1){
	    r1 = q.top();
	    q.pop();
	    r2 = q.top();
	    cost += (r1+r2);
	    q.pop();
	    q.push(r1+r2);
	}
	return cost;
}