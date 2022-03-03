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
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL)
            return true;
        int n=0;
        ListNode*temp=head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
            }
       if(n==2){
            if(head->val!=head->next->val)
                return false;
            else
                return true;
        }
        int mid=n/2;
        ListNode *temp1=head,*curr=NULL,*prev=NULL,*nex=NULL;
        temp=head;
        for(int i=0; i<mid-1; i++){
            temp1=temp1->next;
        }
        prev=temp1;
        curr=temp1->next;
        nex=curr->next;
        while(curr!=NULL){
            curr->next=prev;
            prev=curr;
            curr=nex;
            if(nex!=NULL)
                nex=nex->next;
            
        }
       
       temp1->next=NULL;
        temp1=prev;
        for(int i=0; i<mid; i++){
            if(temp->val!=temp1->val)
                return false;
            temp=temp->next;
            temp1=temp1->next;
        }
       
        return true;
    }
};