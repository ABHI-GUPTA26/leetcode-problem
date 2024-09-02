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
public:   int count(ListNode*head){
    int cnt=0;
    while(head!=nullptr){
        head=head->next;
        cnt++;
    }
    return cnt;
}
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr||k==0)return head;
        ListNode*slow=head;
        ListNode*fast=head;
        int cnt=count(head);
        k=k%cnt;
        if(k==0) return head;
           while(k--){
              fast=fast->next;
           }
           while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
           }
           ListNode*newhead=slow->next;
           slow->next=nullptr;
           ListNode*temp=fast;
           
           temp->next=head;
           return newhead;
    }
};