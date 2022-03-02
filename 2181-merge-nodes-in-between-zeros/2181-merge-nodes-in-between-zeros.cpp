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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *head1=NULL,*temp=head->next,*temp1;
        int sum = 0;
        while(temp!=NULL){
            if(temp->val==0){
                ListNode *new_node=new ListNode();
               new_node->val=sum;
                new_node->next=NULL;
                if(head1==NULL)
                    head1=temp1=new_node;
                else{
                    temp1->next=new_node;
                    temp1=temp1->next;
                }
                    
                
               sum=0;
            }
           sum+=temp->val;
            temp=temp->next;
                
            
        }
        return head1;
    }
};