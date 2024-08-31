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
     ListNode*revrse(ListNode*head,ListNode*pre){
        if(head==nullptr) return pre;
        ListNode*temp=head->next;
        head->next=pre;
        return revrse(temp,head);

     }
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;


        }
        ListNode*temp=nullptr;
          ListNode*head2=revrse(slow,temp);
          while(head2!=nullptr){
            if(head2->val!=head->val) return false;
            head2=head2->next;
            head=head->next;
          }
          return true;
    }
};