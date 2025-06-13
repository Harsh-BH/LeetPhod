class Solution {
public:

    // Merge two sorted linked lists
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (head1 && head2) {
            if (head1->val <= head2->val) {  // â Fix: `head1->value` â `head1->val`, `head2` â `head2->val`
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;  // â Fix: was incorrectly written as `head2 = head1->next`
            }
            tail = tail->next;
        }

        // Append remaining nodes
        if (head1) tail->next = head1;
        if (head2) tail->next = head2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        ListNode* head = nullptr;  
        for (int i = 0; i < lists.size(); i++) {
            head = merge(head, lists[i]);
        }

        return head;
    }
};
