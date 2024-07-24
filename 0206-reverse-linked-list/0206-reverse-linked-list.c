/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *c=head,*bc=NULL,*bcc=NULL;
    while(c!=NULL){
        bcc=bc;
        bc=c;
        c=c->next;
        bc->next=bcc;
    }
    return(bc);
}