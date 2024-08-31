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
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode*temp=head;
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        int a=cnt/2;
        while(a!=0){
            head=head->next;
            a--;
        }
        return head;
    }
};