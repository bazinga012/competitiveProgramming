int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    if(headA==NULL && headB==NULL){return 1;}
    if((headA==NULL && headB!=NULL) ||(headA!=NULL && headB==NULL)|| (headA->data!=headB->data)){return 0;}
    Node* curr1 = headA;
    Node* curr2 = headB;
    while(curr1->next!=NULL && curr2->next!=NULL){
        if(curr1->data!=curr2->data){
            return 0;
        }
        curr1=curr1->next;
        curr2=curr2->next;
    }if(!(curr1->next==NULL && curr2->next==NULL)){
        return 0;
    }
    return 1;
}