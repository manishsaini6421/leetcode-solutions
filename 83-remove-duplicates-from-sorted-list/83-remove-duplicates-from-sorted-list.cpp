/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode*temp=head,*temp1=NULL;
        while(temp->next!=NULL ){
            if(temp->val==temp->next->val){
                temp1=temp->next;
                temp->next=temp->next->next;
                delete(temp1);
                continue;
            }
            temp=temp->next;
            if(temp==NULL)
                return head;
        }
        return head;
    }
};