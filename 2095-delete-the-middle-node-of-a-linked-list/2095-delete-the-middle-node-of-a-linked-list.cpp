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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*temp=head,*temp1=NULL;
        int count=0;
        while(temp!=NULL){
            count++; 
            temp=temp->next;
        }
        if(count==1)
            return NULL;
        temp=head;
        for(int i=0; i<(count/2); i++){
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=temp->next;
        delete(temp);
        return head;
    }
};