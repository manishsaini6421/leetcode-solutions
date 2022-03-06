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
    int getDecimalValue(ListNode* head) {
        ListNode*temp=head;
        int n=0; 
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        int ans=0;
        temp=head;
        while(temp!=NULL){
            ans+=pow(2,n-1)*temp->val;
            temp=temp->next;
            n--;
        }
        return ans;
    }
};