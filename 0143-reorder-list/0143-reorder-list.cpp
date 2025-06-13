class Solution {
public:
    ListNode* breaking_point(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }

    void merge_adjacent(ListNode* l1, ListNode* l2) {
        while (l1 && l2) {
            ListNode* n1 = l1->next;
            ListNode* n2 = l2->next;

            l1->next = l2;
            if (n1 == nullptr) break;
            l2->next = n1;

            l1 = n1;
            l2 = n2;
        }
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* mid = breaking_point(head);
        ListNode* second = reverse(mid->next);
        mid->next = nullptr; 
        merge_adjacent(head, second);
    }
};
