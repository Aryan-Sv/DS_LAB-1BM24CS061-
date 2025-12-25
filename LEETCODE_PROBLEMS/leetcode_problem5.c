struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;


    struct ListNode *temp = list1;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = list2;


    struct ListNode *ptr;
    struct ListNode *lptr = NULL;
    int swap;
   
    if(list1 == NULL || list1->next == NULL) return list1;
   
    do {
        swap = 0;
        ptr = list1;
        while(ptr != lptr && ptr->next != NULL) {
            if(ptr->val > ptr->next->val) {
                int temp = ptr->val;
                ptr->val = ptr->next->val;
                ptr->next->val = temp;
                swap = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while(swap);
   
    return list1;
}
