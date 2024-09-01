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
           if(headA==nullptr||headB==nullptr) return nullptr;
           unordered_map<ListNode*,int>mp;
         while(headA!=nullptr){
            mp[headA]=1;
              headA=headA->next;

         }
         while(headB!=nullptr){
            if(mp.find(headB)!=mp.end()){
                return headB;
            }else{
                headB=headB->next;
            }
         }
         return nullptr;
          
    }
};