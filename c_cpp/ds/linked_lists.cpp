#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

int Length(struct node *head)
{
    int count = 0;
    struct node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return (count);
}

void Push(struct node **headRef, int newData)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    // allocate node
    newNode->data = newData; // put in the data
    newNode->next = (*headRef);
    // link the old list off the new node
    (*headRef) = newNode; // move the head to point to the new node
}

int Count(struct node *head, int searchFor)
{
    struct node *current = head;
    int count = 0;
    while (current != NULL)
    {
        if (current->data == searchFor)
            count++;
        current = current->next;
    }
    return count;
}

int Count2(struct node *head, int searchFor)
{
    struct node *current;
    int count = 0;
    for (current = head; current != NULL; current = current->next)
    {
        if (current->data == searchFor)
            count++;
    }
    return count;
}

int GetNth(struct node *head, int index)
{
    struct node *current = head;
    int count = 0; // the index of the node we're currently looking at
    while (current != NULL)
    {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }
    assert(0); // if we get to this line, the caller was asking// for a non-existent element so we assert fail.
}

void DeleteList(struct node **headRef)
{
    struct node *current = *headRef;
    // deref headRef to get the real head
    struct node *next;
    while (current != NULL)
    {
        next = current->next;
        // note the next pointer
        free(current);  // delete the node
        current = next; // advance to the next node
    }
    *headRef = NULL; // Again, deref headRef to affect the real head back// in the caller.
}

int Pop(struct node **headRef)
{
    struct node *head;
    int result;
    head = *headRef;
    assert(head != NULL);
    result = head->data; // pull out the data before the node is deleted
    *headRef = head->next;
    // unlink the head node for the caller
    // Note the * -- uses a reference-pointer
    //  just like Push() and DeleteList().
    free(head);
    // free the head node
    return (result); // don't forget to return the data from the link
}

void InsertNth(struct node **headRef, int index, int data)
{ // position 0 is a special case...
    if (index == 0)
        Push(headRef, data);
    else
    {
        struct node *current = *headRef;
        int i;
        for (i = 0; i < index - 1; i++)
        {
            assert(current != NULL); // if this fails, index was too big
            current = current->next;
        }
        assert(current != NULL);      // tricky: you have to check one last time
        Push(&(current->next), data); // Tricky use of Push()
        // The pointer being pushed on is not
        // in the stack. But actually this works
        // fine -- Push() works for any node pointer.
    }
}

// Uses special case code for the head end
void SortedInsert(struct node **headRef, struct node *newNode)
{ // Special case for the head end
    if (*headRef == NULL || (*headRef)->data >= newNode->data)
    {
        newNode->next = *headRef;
        *headRef = newNode;
    }
    else
    { // Locate the node before the point of insertion
        struct node *current = *headRef;
        while (current->next != NULL && current->next->data < newNode->data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Local references strategy for the head end
void SortedInsert3(struct node **headRef, struct node *newNode)
{
    struct node **currentRef = headRef;
    while (*currentRef != NULL && (*currentRef)->data < newNode->data)
    {
        currentRef = &((*currentRef)->next);
    }
    newNode->next = *currentRef; // Bug: this line used to have// an incorrect (*currRef)->next
    *currentRef = newNode;
}

// Given a list, change it to be in sorted order (using SortedInsert()).
void InsertSort(struct node **headRef)
{
    struct node *result = NULL;
    // build the answer here
    struct node *current = *headRef; // iterate over the original list
    struct node *next;
    while (current != NULL)
    {
        next = current->next; // tricky - note the next pointer before we change it
        SortedInsert(&result, current);
        current = next;
    }
    *headRef = result;
}

void Append(struct node **aRef, struct node **bRef)
{
    struct node *current;
    if (*aRef == NULL)
    { // Special case if a is empty
        *aRef = *bRef;
    }
    else
    {
        // Otherwise, find the end of a, and append b there
        current = *aRef;
        while (current->next != NULL)
        { // find the last node
            current = current->next;
        }
        current->next = *bRef; // hang the b list off the last node
    }
    *bRef = NULL; // NULL the original b, since it has been appended above
}

void FrontBackSplit(struct node *source, struct node **frontRef, struct node **backRef)
{
    int len = Length(source);
    int i;
    struct node *current = source;
    if (len < 2)
    {
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        int hopCount = (len - 1) / 2;
        //(figured these with a few drawings)
        for (i = 0; i < hopCount; i++)
        {
            current = current->next;
        }
        // Now cut at current
        *frontRef = source;
        *backRef = current->next;
        current->next = NULL;
    }
}

// Uses the fast/slow pointer strategy
void FrontBackSplit2(struct node *source, struct node **frontRef, struct node **backRef)
{
    struct node *fast;
    struct node *slow;
    if (source == NULL || source->next == NULL)
    {
        // length < 2 cases
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        slow = source;
        fast = source->next;
        // Advance 'fast' two nodes, and advance 'slow' one node
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        // 'slow' is before the midpoint in the list, so split it in two// at that point.
        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }
}

// Remove duplicates from a sorted list
void RemoveDuplicates(struct node *head)
{
    struct node *current = head;
    if (current == NULL)
        return;
    // do nothing if the list is empty
    // Compare current node with next node
    while (current->next != NULL)
    {
        if (current->data == current->next->data)
        {
            struct node *nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        }
        else
        {
            current = current->next;
            // only advance if no deletion
        }
    }
}

void MoveNode(struct node **destRef, struct node **sourceRef)
{
    struct node *newNode = *sourceRef;
    // the front source node
    assert(newNode != NULL);
    *sourceRef = newNode->next; // Advance the source pointer
    newNode->next = *destRef;   // Link the old dest off the new node
    *destRef = newNode;         // Move dest to point to the new node
}

// will be in reverse order
void AlternatingSplit(struct node *source, struct node **aRef, struct node **bRef)
{
    struct node *a = NULL;
    // Split the nodes to these 'a' and 'b' lists
    struct node *b = NULL;
    struct node *current = source;
    while (current != NULL)
    {
        MoveNode(&a, &current);
        // Move a node to 'a'
        if (current != NULL)
        {
            MoveNode(&b, &current); // Move a node to 'b'
        }
    }
    *aRef = a;
    *bRef = b;
}

void AlternatingSplit2(struct node *source, struct node **aRef, struct node **bRef)
{
    struct node aDummy;
    struct node *aTail = &aDummy;
    // points to the last node in 'a'
    struct node bDummy;
    struct node *bTail = &bDummy;
    // points to the last node in 'b'
    struct node *current = source;
    aDummy.next = NULL;
    bDummy.next = NULL;
    while (current != NULL)
    {
        MoveNode(&(aTail->next), &current);
        // add at 'a' tail
        aTail = aTail->next;
        // advance the 'a' tail
        if (current != NULL)
        {
            MoveNode(&(bTail->next), &current);
            bTail = bTail->next;
        }
    }
    *aRef = aDummy.next;
    *bRef = bDummy.next;
}

struct node *ShuffleMerge(struct node *a, struct node *b)
{
    struct node *result;
    struct node *recur;
    if (a == NULL)
        return (b);
    // see if either list is empty
    else if (b == NULL)
        return (a);
    else
    {
        // it turns out to be convenient to do the recursive call first --
        // otherwise a->next and b->next need temporary storage.
        recur = ShuffleMerge(a->next, b->next);
        result = a;      // one node from a
        a->next = b;     // one from b
        b->next = recur; // then the rest
        return (result);
    }
}

struct node *ShuffleMerge2(struct node *a, struct node *b)
{
    struct node *result = NULL;
    struct node **lastPtrRef = &result;
    while (1)
    {
        if (a == NULL)
        {
            *lastPtrRef = b;
            break;
        }
        else if (b == NULL)
        {
            *lastPtrRef = a;
            break;
        }
        else
        {
            MoveNode(lastPtrRef, &a);
            lastPtrRef = &((*lastPtrRef)->next);
            MoveNode(lastPtrRef, &b);
            lastPtrRef = &((*lastPtrRef)->next);
        }
    }
    return (result);
}

struct node *SortedMerge(struct node *a, struct node *b)
{
    struct node *result = NULL;
    struct node **lastPtrRef = &result;
    // point to the last result pointer
    while (1)
    {
        if (a == NULL)
        {
            *lastPtrRef = b;
            break;
        }
        else if (b == NULL)
        {
            *lastPtrRef = a;
            break;
        }
        if (a->data <= b->data)
        {
            MoveNode(lastPtrRef, &a);
        }
        else
        {
            MoveNode(lastPtrRef, &b);
        }
        lastPtrRef = &((*lastPtrRef)->next);
        // tricky: advance to point to// the next ".next" field
    }
    return (result);
}

struct node *SortedMerge2(struct node *a, struct node *b)
{
    struct node *result = NULL;
    // Base cases
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    // Pick either a or b, and recur
    if (a->data <= b->data)
    {
        result = a;
        result->next = SortedMerge2(a->next, b);
    }
    else
    {
        result = b;
        result->next = SortedMerge2(a, b->next);
    }
    return (result);
}

void MergeSort(struct node **headRef)
{
    struct node *head = *headRef;
    struct node *a;
    struct node *b;
    // Base case -- length 0 or 1
    if ((head == NULL) || (head->next == NULL))
    {
        return;
    }
    FrontBackSplit(head, &a, &b);
    // Split head into 'a' and 'b' sublists// We could just as well use AlternatingSplit()
    MergeSort(&a); // Recursively sort the sublists
    MergeSort(&b);
    *headRef = SortedMerge(a, b); // answer = merge the two sorted lists together
}

struct node *SortedIntersect2(struct node *a, struct node *b)
{
    struct node *result = NULL;
    struct node **lastPtrRef = &result;
    // Advance comparing the first nodes in both lists.
    // When one or the other list runs out, we're done.
    while (a != NULL && b != NULL)
    {
        if (a->data == b->data)
        {
            // found a node for the intersection
            Push(lastPtrRef, a->data);
            lastPtrRef = &((*lastPtrRef)->next);
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
        { // advance the smaller list
            a = a->next;
        }
        else
        {
            b = b->next;
        }
    }
    return (result);
}

static void Reverse(struct node **headRef)
{
    struct node *result = NULL;
    struct node *current = *headRef;
    struct node *next;
    while (current != NULL)
    {
        next = current->next;
        // tricky: note the next node
        current->next = result; // move the node onto the result
        result = current;
        current = next;
    }
    *headRef = result;
}

static void Reverse2(struct node **headRef)
{
    struct node *result = NULL;
    struct node *current = *headRef;
    while (current != NULL)
    {
        MoveNode(&result, &current);
    }
    *headRef = result;
}

void RecursiveReverse(struct node **headRef)
{
    struct node *first;
    struct node *rest;
    if (*headRef == NULL)
        return;         // empty list base case
    first = *headRef;   // suppose first = {1, 2, 3}
    rest = first->next; //         rest = {2, 3}
    if (rest == NULL)
        return;
    // empty rest base case
    RecursiveReverse(&rest);   // Recursively reverse the smaller {2, 3} case// after: rest = {3, 2}
    first->next->next = first; // put the first elem on the end of the list
    first->next = NULL;        // (tricky step -- make a drawing)
    *headRef = rest;           // fix the head pointer
}

void removeLoop(struct node *head, struct node *pointOfMeet)
{
    struct node *curr = head;
    while (curr != pointOfMeet->next)
    {
        curr = curr->next;
        pointOfMeet = pointOfMeet->next;
    }
    pointOfMeet->next = NULL;
}

void detectCorrectLoop(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL)
    {
        if (slow == fast)
        {
            removeLoop(head, fast);
            return;
        }
        fast = fast->next;
        if (fast != NULL)
        {
            if (slow == fast)
            {
                removeLoop(head, fast);
                return;
            }
            slow = slow->next;
            fast = fast->next;
        }
    }
}