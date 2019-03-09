ListNode *detectCycle(ListNode *head) {
    map<ListNode*,bool> hash;
    ListNode *curr=head;
    while(curr!=NULL){
       if(hash.find(curr) == hash.end()){
           hash[curr]  = true;
           curr = curr->next;
       }else{
           return curr;
       }
    }
    return NULL;
}