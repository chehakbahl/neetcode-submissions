class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;
        while (second) {
            ListNode* nextNode = second->next;
            second->next = prev;
            prev = second;
            second = nextNode;
        }

        // Step 3: Merge
        ListNode* first = head;
        ListNode* secondHalf = prev;

        while (secondHalf) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = secondHalf->next;

            first->next = secondHalf;
            secondHalf->next = temp1;

            first = temp1;
            secondHalf = temp2;
        }
    }
};