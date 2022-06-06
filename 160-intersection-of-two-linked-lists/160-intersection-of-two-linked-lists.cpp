/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode *,int> m;
        
        ListNode *temp1=headA;
        while(temp1!=NULL){
            m[temp1]++;
            temp1=temp1->next;
        }
        ListNode *temp2=headB;
        while(temp2!=NULL){
            m[temp2]++;
            temp2=temp2->next;
        }
        
        for(auto x:m){
            if(x.second==2) return x.first;
        }
        return NULL;
    }
};