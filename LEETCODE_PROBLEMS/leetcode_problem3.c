struct ListNode *findMid(struct ListNode* head){
    struct ListNode *fast = head, *slow = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}


struct ListNode *mergeList(struct ListNode* l1,struct ListNode* l2){
    struct ListNode res;
    struct ListNode *t = &res;
    while(l1!=NULL && l2!=NULL){
        if(l1->val < l2->val){
            t->next = l1;
            l1 = l1->next;
        }
        else{
            t->next = l2;
            l2 = l2->next;
        }
        t=  t->next;
    }
    while(l1!=NULL){
        t->next = l1;
        l1 = l1->next;
        t= t->next;
    }
    while(l2!=NULL){
        t->next = l2;
        l2 = l2->next;
        t= t->next;
    }
    return res.next;
}


struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;


    struct ListNode *left = head;
    struct ListNode *mid = findMid(head);
    struct ListNode *right = mid->next;
    mid->next = NULL;
    left = sortList(left);
    right = sortList(right);
    return mergeList(left,right);
}
