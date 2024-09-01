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
public: ListNode*findmiddle(ListNode*head){
    ListNode*slow=head;
    ListNode*fast=head->next;
    while(fast!=nullptr&&fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
} 
ListNode*merge(ListNode*left,ListNode*right){
             ListNode*head= new ListNode(-1);
             ListNode*temp=head;
             
             while(left!=nullptr && right!=nullptr){
                    
                   if(left->val<=right->val){
                            
                         temp->next=left;
                         
                         left=left->next;
                   }else{
                         
                         temp->next=right;
                         
                         right=right->next;
                        
                   }
                   temp=temp->next;
             }
             while(left){
                   
                   temp->next=left;
                   
                   left=left->next;
                   temp=temp->next;
             }
             while(right){
                   
                   temp->next=right;
                   
                   right=right->next;
                   temp=temp->next;
             }
             return head->next;

}
    ListNode* sortList(ListNode* head) {
        if(head==nullptr|| head->next==nullptr) return head;
        ListNode*left=head;
        ListNode*middle=findmiddle(head);
        ListNode*right=middle->next;
        middle->next=nullptr;
         ListNode*leftpart= sortList(left);
         ListNode*rightpart= sortList(right);
         return merge(leftpart,rightpart);

    }
};