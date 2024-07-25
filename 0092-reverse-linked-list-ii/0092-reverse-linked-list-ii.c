/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if(head==NULL || head->next==NULL || left==right) return(head);
    struct ListNode *c=head,*bc=NULL;
    for(int i=1; i<left; i++){
        bc=c;
     c=c->next;
    }
    struct ListNode *nc=c,*nbc=NULL,*bcc=NULL;
    for(int i=left; i<=right; i++){
        bcc=nbc;
        nbc=nc;
        nc=nc->next;
        nbc->next=bcc;
    }
    if(left!=1){
        bc->next=nbc;
        c->next=nc;
   return(head);
    }
    else{
        c->next=nc;
        return(nbc);
    }
    return head;
   
}