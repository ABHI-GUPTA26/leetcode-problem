class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        int listlength = 0;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while (temp1 != nullptr) {
            temp1 = temp1->next;
            listlength++;
        }

        n = listlength - n;

        if (n == 0) {
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }

        while (--n > 0) {
            temp2 = temp2->next;
        }

        ListNode* deletenode = temp2->next;
        temp2->next = temp2->next->next;
        delete deletenode;

        return head;
    }
};
