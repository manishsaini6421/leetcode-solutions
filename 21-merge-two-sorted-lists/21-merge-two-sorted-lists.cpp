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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p=list1,*q=list2,*s=NULL,*temp=NULL;
        if(p!=NULL && q!=NULL){
            if(p->val <= q->val){
                s=temp=p;
                p=p->next;
            }
            else{
                s=temp=q;
                q=q->next;
            }
            while(p!=NULL && q!=NULL){
                if(p->val <= q->val){
                    temp->next=p;
                    temp=p;
                    p=p->next;
                }
                else{
                    temp->next=q;
                    temp=q;
                    q=q->next;
                }
            }
            if(p!=NULL){
                temp->next=p;
            }
            if(q!=NULL){
                temp->next=q;
            }
        }
        else if(p!=NULL && q==NULL){
            s=p;
        }
        else{
            s=q;
        }
        return s;
    }
};