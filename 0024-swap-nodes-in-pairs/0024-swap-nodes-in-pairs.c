/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
   if(head==NULL || head->next==NULL) return head;
  struct  ListNode *new, *temp;
    new=head->next;
    temp=head->next->next;
    new->next=head;
    head->next=swapPairs(temp);
    return new;
}