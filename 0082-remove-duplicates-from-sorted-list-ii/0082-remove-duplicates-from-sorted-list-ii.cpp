class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prev = dummy;

        while (head) {
            if (head->next && head->val == head->next->val) {
                // Skip all nodes with this value
                while (head->next && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next; // unlink duplicates
            } else {
                prev = prev->next; // move forward if no duplicate
            }
            head = head->next;
        }
        return dummy->next;
    }
};
