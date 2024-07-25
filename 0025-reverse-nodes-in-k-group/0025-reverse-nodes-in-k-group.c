/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode*temp=head;
    for(int i=1; i<=k; i++){
        if(temp==NULL) return(head);
        temp=temp->next;
    }
    struct ListNode *c=head,*bc=NULL,*bbc=NULL;
    for(int i=1; i<=k; i++){
        bbc=bc;
        bc=c;
        c=c->next;
        bc->next=bbc;
    }
    head->next=reverseKGroup(c,k);
    return(bc);
}