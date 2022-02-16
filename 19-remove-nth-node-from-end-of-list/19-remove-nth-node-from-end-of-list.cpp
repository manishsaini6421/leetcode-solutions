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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        
        ListNode* temp=head,*temp1=head;
       
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
         if(count==n){
             temp=head;
             head=head->next;
             delete(temp);
         }
        else if(n>1 && n<count){
           temp=head;
        for(int i=0; i<count-n; i++){
            temp1=temp;
            temp=temp->next;
        }

        temp1->next=temp->next;
        
        delete(temp);
        
        }
        else{
            temp=head;
           while(temp->next!=NULL){
               temp1=temp;
               temp=temp->next;
               
           }
            temp1->next=NULL;
         delete(temp);
        }
        return head; 
    }
};