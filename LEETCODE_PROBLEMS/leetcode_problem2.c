struct ListNode* removeElements(struct ListNode* head, int val) {
   
    struct ListNode *temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next=head;
    struct ListNode *prev=temp;
    struct ListNode *curr=head;
    while(curr!=NULL){
        if(curr->val==val){
            prev->next=curr->next;
            free(curr);
            curr=prev->next;  
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
    return temp->next;
}
